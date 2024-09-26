#include <iostream>
using namespace std;

//This Program creates Binary Search Trees given only the PreOrder Traversal and creates a tree given both InOrder and PreOrder Traversal. 
//Node class
class Node{
public:
    int data;
    Node* left;
    Node* right;

};

//Creation of node
Node* createNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

//Helper for constructing subtrees using only the PreOrder array
 Node* constructTreeHelp(int pre[], int* index, int key, int min, int max, int size){
    if (*index>=size){ return nullptr;}
    Node* root = nullptr;

    if (key > min && key < max){
        root = createNode(key);
        *index=*index+1;

        if (*index < size){
            root->left = constructTreeHelp(pre, index, pre[*index], min, key, size);
        }
        if (*index < size){
            root->right = constructTreeHelp(pre, index, pre[*index], key, max, size);
        }
    }
    return root;
 }

//Search needed for construction of tree using both arrays
 int search(int arr[], int start, int end, int key) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

//Helper function to recursivly create subtrees using both arrays
 Node* constructTreeBoth(int pre[], int in[], int preStart, int preEnd, int inStart, int inEnd){
    if (preStart > preEnd || inStart > inEnd){
        return nullptr;
    }

    int rootVal = pre[preStart];
    Node* root = createNode(rootVal);

    int rootIndex = search(in, inStart, inEnd, rootVal);
    int leftSubtreeSize = rootIndex - inStart;

    root->left = constructTreeBoth(pre, in, preStart+1, preStart+leftSubtreeSize, inStart, rootIndex-1);
    root->right = constructTreeBoth(pre, in, preStart+leftSubtreeSize+1, preEnd, rootIndex+1, inEnd);

    return root;
 }

//Actual Constructor for tree using only PreOrder array
 Node* constructTreePre(int pre[], int size){
    int index = 0;
    int maximum = 0;
    int minimum = 100;
    for (int i = 0; i<=size; i++){
        if (pre[i]>maximum){
            maximum = pre[i];
        }
        if (pre[i]<=minimum){
            minimum = pre[i];
        }
    }
    return constructTreeHelp(pre, &index, pre[0], minimum-1, maximum+1, size);
 }

//Actual Cnstructor for tree using both arrays
 Node* constructTreeBoth2(int pre[], int in[], int size){
   if(!pre || !in || size<=0){
    return nullptr;
   }
    return constructTreeBoth(pre, in, 0, size-1, 0, size+1);
 }

//Print Tree PostOrder Traversal
void printTreePostOrder(Node* Node){
    if (Node == nullptr){
        return;
    }
    printTreePostOrder(Node->left);
    printTreePostOrder(Node->right);
    cout<< Node->data<<" ";
}

int main() {
    
    int pre[] = {20, 8, 4, 12, 23, 24};
    int in[] = {4, 8, 12, 20, 23, 24};
	int sizePre = sizeof(pre) / sizeof(pre[0]);
    int sizeIn = sizeof(in) / sizeof(in[0]);


    Node* rootPre = constructTreePre(pre, sizePre);
    Node* rootIn = constructTreeBoth2(pre, in, sizeIn);

    cout<<endl<<"Constructed Tree using InOrder Array(Traversed with PostOrder): "<<endl;
	printTreePostOrder(rootPre);
    cout<<endl;

    cout<<endl<<"Constructed Tree using Both InOrder and PreOrder Array(Traversed with PostOrder): "<<endl;
    printTreePostOrder(rootIn);


    return 0;
}
