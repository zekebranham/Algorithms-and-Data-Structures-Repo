#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class BSTNode {
public:
    int data;
    BSTNode* left;
    BSTNode* right;
};

class BST {
public:
    BST() {
        root = nullptr;
    }

    void InsertNode(int data) {
        root = InsertNodeHelper(root, data);
    }

    BSTNode* InsertNodeHelper(BSTNode* node, int data) {
        if (node == nullptr) {
            node = new BSTNode();
            node->data = data;
            node->left = node->right = nullptr;
        }
        else if (data < node->data) {
            node->left = InsertNodeHelper(node->left, data);
        }
        else if (data > node->data) {
            node->right = InsertNodeHelper(node->right, data);
        }
        return node;
    }

    bool search(int key) {
        return searchHelper(root, key);
    }

    bool searchHelper(BSTNode* node, int key){
        if (node == nullptr){
            cout<<key<<" not found";
            return false;
        }
        if (key == node->data){
            cout<<" Value: "<<node->data<<" found in tree";
            return true;
        }
        if (key < node->data){
            return searchHelper(node->left, key);
        }
        else{
            return searchHelper (node->right, key);
        }
    }

    int maximum(){
        BSTNode* node = root;  
        int max = -1;          

        while (node != nullptr) {
            max = node->data;  
            node = node->right;  
    }

    return max;
    }

    void PrintPostOrder() {
        PrintPostOrderHelper(root);
        cout << endl;
    }

    void PrintPostOrderHelper(BSTNode* node) {
        if (node != nullptr) {
            PrintPostOrderHelper(node->left);cout << node->data << " ";
            PrintPostOrderHelper(node->right);
            
        }
    }
private:
    BSTNode* root;
};

int main() {
    BST bst;
    bst.InsertNode(10);
    bst.InsertNode(5);
    bst.InsertNode(20);
    bst.InsertNode(3);
    bst.InsertNode(8);
    bst.InsertNode(15);
    bst.InsertNode(25);
    // const int n = 500000;
    // std::srand(static_cast<unsigned int>(std::time(nullptr)));
    // for (int i = 0; i < n; i++) {
    //     bst.InsertNode(::rand() % 500000);
    // }

    cout << "Inserted values: 10, 5, 20, 3, 8, 15, 25"<<endl;
    cout<<"Post-Order Traversal: ";
    bst.PrintPostOrder();

    cout<<"Largest element in list: "<<bst.maximum()<<endl;

    int num;
    cout<<"Type value to search for: ";
    cin>>num;
    bst.search(num);

return 0;
}
