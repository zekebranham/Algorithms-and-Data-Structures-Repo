#include <iostream>
using namespace std;
class Heap
{
public:
//int Arr[];
//Heap();
void printArray(int Arr[],int n){
    for(int i=0;i<n;i++){
        cout<< Arr[i] << " ";
    }
}
//Max heap
int parent(int i){
    return (i-1)/2;
    }
int left(int i){
    return (2*i + 1);
    }
int right(int i){
    return (2*i + 2);
    }
void modifyValMax (int Arr[], int i,int val){
    Arr[i] = val;
    while (i>1 && Arr[parent(i)]<Arr[i]){
        std::swap(Arr[i],Arr[parent(i)]);
        i = parent(i);
    }
}
void insert_value_maxHeap (int Arr[], int val, int& n){
    n++;
    Arr[n - 1] = val;
    for (int i = (n / 2) - 1; i >= 0; i--) {
        max_heapify(Arr, i, n);
    }
}
void max_heapify(int Arr[], int i,int n) {
    int largest = i;
    int l = left(i);
    int r = right(i);
    if (l < n && Arr[l] > Arr[largest]) {
        largest = l;
    }
    if (r < n && Arr[r] > Arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        std::swap(Arr[i], Arr[largest]);
        max_heapify(Arr, largest, n);
    }
}
//Needed to create two seperate functions to avoid overlapping calls in int main() while reprelcating sample output
int Maximum (int Arr[]){
    return Arr[0];
}
void extract_maximum (int Arr[], int& n){ 
    Arr[0] = Arr[n - 1];
    n--;
    max_heapify(Arr, 0, n);
}
void ascendingHeapSort(int Arr[], int n){
    buildMaxHeap(Arr, n);
    for (int i = n - 1; i > 0; i--) {
        std::swap(Arr[0], Arr[i]);
        max_heapify(Arr, 0, i);
    }
}
void buildMaxHeap(int Arr[], int n){
    for (int i = (n / 2) - 1; i >= 0; i--) {
        max_heapify(Arr, i, n);
    }
}
//Min Heap
void modifyValMin (int Arr[], int i,int val){
    Arr[i] = val;
    while (i>1 && Arr[parent(i)]>Arr[i]){
        std::swap(Arr[i],Arr[parent(i)]);
        i = parent(i);
    }
}
void insert_value_minHeap (int Arr[], int val, int& n){
    n++;
    Arr[n - 1] = val;
    for (int i = (n / 2) - 1; i >= 0; i--) {
        min_heapify(Arr, i, n);
    }
}
void min_heapify(int Arr[], int i, int n){
     int smallest = i;
    int l = left(i);
    int r = right(i);

    if (l < n && Arr[l] < Arr[smallest]) {
        smallest = l;
    }

    if (r < n && Arr[r] < Arr[smallest]) {
        smallest = r;
    }

    if (smallest != i) {
        std::swap(Arr[i], Arr[smallest]);
        min_heapify(Arr, i, smallest);
    }
}
int Minimum (int Arr[]){
    return Arr[0];
}
void extract_minimum (int Arr[], int& n){
    Arr[0] = Arr[n - 1];
    n--;
    min_heapify(Arr, 0, n);
}
void descendingHeapSort(int Arr[], int n){
     buildMinHeap(Arr, n);
    for (int i = n - 1; i > 0; i--) {
        std::swap(Arr[0], Arr[i]);
        min_heapify(Arr, 0, i);
    }
}
void buildMinHeap(int Arr[], int n){
     for (int i = (n / 2) - 1; i >= 0; i--) {
        min_heapify(Arr, i, n);
    }
}
};

int main(){
    int choice;
    int Arr[4];
    int arrSize = (sizeof(Arr)/sizeof(int));

    Heap heap;

    cout<< "Enter 0 for ascending and 1 for descending order "<<endl;
    cin>>choice;
    if (choice == 0){
        cout<<"Please input 4 number for the array, press enter after each number: "<<endl;
        for (int i=0;i<arrSize;i++){
            cin>>Arr[i];
        }
        heap.buildMaxHeap(Arr,arrSize);
        cout<<endl<<"Please enter 1 different element to insert into heap: "<<endl;
        int num1;
        cin>>num1;
        heap.insert_value_maxHeap(Arr,num1,arrSize);
        cout<<"Current heap is: ";
        heap.printArray(Arr, arrSize);
        int max = heap.Maximum(Arr);
        cout<<endl<<"Sorted decending heap is: ";
        heap.ascendingHeapSort(Arr,arrSize);
        heap.printArray(Arr, arrSize);
        cout<<endl<<"Extracted Maximum of Heap: "<<max<<endl;
        heap.descendingHeapSort(Arr,arrSize);
        heap.extract_maximum(Arr, arrSize);
        cout<<"Sorted heap is: ";
        heap.ascendingHeapSort(Arr,arrSize);

        heap.printArray(Arr, arrSize);

    }
    if (choice == 1){
        cout<<"Please input 4 number for the array, press enter after each number: "<<endl;
        for (int i=0;i<arrSize;i++){
            cin>>Arr[i];
        }
        heap.buildMinHeap(Arr,arrSize);
        cout<<endl<<"Please enter 1 different element to insert into heap: "<<endl;
        int num1;
        cin>>num1;
        heap.insert_value_minHeap(Arr,num1,arrSize);
        heap.ascendingHeapSort(Arr,arrSize);

        cout<<"Current heap is: ";
        heap.printArray(Arr, arrSize);
        int min = heap.Minimum(Arr);
        cout<<endl<<"Sorted decending heap is: ";
        heap.descendingHeapSort(Arr,arrSize);
        heap.printArray(Arr, arrSize);
    
        cout<<endl<<"Extracted Minimum of Heap: "<<min<<endl;
        heap.ascendingHeapSort(Arr, arrSize);
        heap.extract_minimum(Arr, arrSize);

        cout<<"Sorted heap is: ";
        heap.descendingHeapSort(Arr,arrSize);

        heap.printArray(Arr, arrSize);
    }
    

    return 0;
}
