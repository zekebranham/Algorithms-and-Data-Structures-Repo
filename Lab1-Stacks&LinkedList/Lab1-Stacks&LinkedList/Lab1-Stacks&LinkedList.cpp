
#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;


//Part 1: Stacks

class Array{
    public:

        void PushArray(int arr[],int x){            
            for (int i=0; i<10; i++){
            if (arr[i] == 0){
                arr[i] = x;
                break;

        }
    }
                    
}
        void PopArray(int arr[]){
            if (arr[0]==0){
                cout<<"Array is empty"<<endl;
            }
            else {
                for (int i=0; i<10; i++){
                    int j = arr[i];
                    if (j != 0){
                        continue;
                    }
                    else {
                        cout<< "Popped value: "<<arr[i-1]<<endl;
                        arr[i-1]=0;
                        break;
                    }
                }
            }
        }

        void PeekArray(int arr[]){
            if (arr[0]==0){
                cout<<"Array is empty"<<endl;
            }
            else {
                for (int i=0; i<10; i++){
                    int j = arr[i];
                    if (j != 0){
                        continue;
                    }
                    else {
                        cout<<"Peeked value: "<<arr[i-1]<<endl;
                        break;
                    }
                }
            }
        }

        void DisplayArray(int arr[]){
            cout<<"Items in the stack: ";
            for (int i=0; i<10; i++){
                if (arr[i] != 0){
                cout<<arr[i]<<" ";
                }
            }
        }
};

//Part 2: Linked Lists

class Node {
public:
    int value;
    Node* next;

    Node(int val, Node* nextPtr = nullptr) : value(val), next(nextPtr) {}
};

class List {
private:
    Node* head;
    Node* tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    bool isEmpty() const {
        return head == nullptr;
    }

    void insertBeginning(int val) {
        Node* newNode = new Node(val);

        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
            cout<<"Inserted Node: "<< head->value <<endl;
        }
    }

    void deleteBeginning(){
        cout<<"Items in the linked list after deleting the first element: ";
        head = head->next;
    }

    void deleteEnd(){
        Node* SecondLastNode = head;
        while (SecondLastNode->next->next != nullptr){
            SecondLastNode = SecondLastNode->next;
        }
        delete (SecondLastNode->next);
        SecondLastNode->next = nullptr;
        cout<<"Items in the linked list after deleting the last element: ";
    }

    void print() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main()
{
    //Part 1: Stacks
    
auto start_time = chrono::high_resolution_clock::now(); //Start time
    
    int arr1[10];
    for (int i=0; i<10; i++){
            arr1[i] = 0;
        } 
    Array obj1;
        obj1.PushArray(arr1,20);
        obj1.PushArray(arr1,40);
        obj1.PushArray(arr1,60);
            obj1.DisplayArray(arr1);
        cout<<endl;
        obj1.PopArray(arr1);
        obj1.PeekArray(arr1);
            obj1.DisplayArray(arr1);
            cout<<endl<<" "<<endl;

auto end_time = chrono::high_resolution_clock::now(); //End time
chrono::duration<double> elapsed = end_time - start_time; //Total time 
cout << "Elapsed time for Part 1: " << elapsed.count() << " seconds" << endl<<" "<<endl;

    //Part 2: Linked Lists

auto start_time2 = chrono::high_resolution_clock::now(); //Start time
     List list;
    list.insertBeginning(60);
    list.insertBeginning(40);
    list.insertBeginning(20);
        cout<<"Items in the linked list: ";
        list.print();
    list.deleteBeginning();
        list.print();
    list.deleteEnd();
        list.print();

auto end_time2 = chrono::high_resolution_clock::now(); //End time
chrono::duration<double> elapsed2 = end_time2 - start_time2; //Total time 
cout<<endl<< "Elapsed time for Part 2: " << elapsed2.count() << " seconds" << endl<<" "<<endl;

    return 0;
}

