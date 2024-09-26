#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

void print(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

//Selection Sort
void selectionSort(int arr[], int n)
{
    int min_in;
    for(int i=0;i<n;i++)
    {
        min_in = i;
        for(int j=i+1;j<n;j++)
            if (arr[j] < arr[min_in])
                min_in = j;
        swap(arr[i],arr[min_in]);
    }
}

//Merge Sort

void merge(int array[], int const left, int const mid, int const right){
    auto const subArray1 = mid-left+1;
    auto const subArray2 = right-mid;
    auto *leftArray = new int[subArray1];
    auto *rightArray = new int[subArray2];

    for(auto i = 0; i<subArray1; i++){
        leftArray[i] = array[left+i];
    }
    for (auto i = 0; i<subArray2; i++){
        rightArray[i] = array[mid+1+i];
    }

    auto indexOfSubArray1 = 0;
    auto indexOfSubArray2 = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArray1<subArray1 && indexOfSubArray2<subArray2){
        if (leftArray[indexOfSubArray1]<=rightArray[indexOfSubArray2]){
            array[indexOfMergedArray] = leftArray[indexOfSubArray1];
            indexOfSubArray1++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArray2];
            indexOfSubArray2++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArray1<subArray1){
        array[indexOfMergedArray] = leftArray[indexOfSubArray1];
        indexOfSubArray1++;
        indexOfMergedArray++;
    }
    while (indexOfSubArray2<subArray2){
        array[indexOfMergedArray] = rightArray[indexOfSubArray2];
        indexOfSubArray2++;
        indexOfMergedArray++;
    }
}
void mergeSort(int array[],int const start, int const end){
    if (start>=end) {return;}
    auto mid = start+(end-start)/2;
    mergeSort(array,start,mid);
    mergeSort(array,mid+1,end);
    merge(array,start,mid,end);
}

int main()
{
    cout<<"SELECTION SORT:"<<endl;
    int sorted1[10000];
    for (int i = 1; i<=10000; i++){
        sorted1[i]=i;
    }
    int partsorted1[10000];
    for (int i = 1; i<=5000; i++){
        partsorted1[i]=i;
    }
    for (int i = 10000; i>5000; i--){
        partsorted1[i]=i;
    }
    int revsorted1[10000];
    for (int i = 10000; i>0; i--){
        revsorted1[i]=i;
    }
    int n;
    n = sizeof(sorted1)/sizeof(int);
auto start_timeS1 = chrono::high_resolution_clock::now(); //Start time
    selectionSort(sorted1,n);
auto end_timeS1 = chrono::high_resolution_clock::now(); //End time
chrono::duration<double> elapsedS1 = end_timeS1 - start_timeS1; //Total time 
    cout<<"Fully Sorted Array ";
    //print(sorted1,n);
cout << "Elapsed time: " << elapsedS1.count() << " seconds" << endl<<" "<<endl;

auto start_timeS2 = chrono::high_resolution_clock::now(); //Start time
    selectionSort(partsorted1,n);
auto end_timeS2 = chrono::high_resolution_clock::now(); //End time
chrono::duration<double> elapsedS2 = end_timeS2 - start_timeS2; //Total time 
    cout<<"Partially Sorted Array ";
    //print(partsorted1,n);
cout << "Elapsed time: " << elapsedS2.count() << " seconds" << endl<<" "<<endl;

auto start_timeS3 = chrono::high_resolution_clock::now(); //Start time
    selectionSort(revsorted1,n);
auto end_timeS3 = chrono::high_resolution_clock::now(); //End time
chrono::duration<double> elapsedS3 = end_timeS3 - start_timeS3; //Total time    
    cout<<"Reverse Sorted Array ";
    //print(revsorted1,n);
cout << "Elapsed time: " << elapsedS3.count() << " seconds" << endl<<" "<<endl;

    
    cout<<endl<<"MERGE SORT:"<<endl;
    int sorted2[10000];
    for (int i = 1; i<=10000; i++){
        sorted2[i]=i;
    }
    int partsorted2[10000];
    for (int i = 1; i<=5000; i++){
        partsorted2[i]=i;
    }
    for (int i = 10000; i>5000; i--){
        partsorted2[i]=i;
    }
    int revsorted2[10000];
    for (int i = 10000; i>=1; i--){
        revsorted2[i]=i;
    }

auto start_timeM1 = chrono::high_resolution_clock::now(); //Start time
    mergeSort(sorted2,0,n-1);
auto end_timeM1 = chrono::high_resolution_clock::now(); //End time
chrono::duration<double> elapsedM1 = end_timeM1 - start_timeM1; //Total time 
    cout<<"Fully Sorted Array ";
    //print(sorted2,n);
cout << "Elapsed time: " << elapsedM1.count() << " seconds" << endl<<" "<<endl;

auto start_timeM2 = chrono::high_resolution_clock::now(); //Start time
    mergeSort(partsorted2,0,n-1);
auto end_timeM2 = chrono::high_resolution_clock::now(); //End time
chrono::duration<double> elapsedM2 = end_timeM2 - start_timeM2; //Total time 
    cout<<"Partially Sorted Array ";
    //print(partsorted2,n);
cout << "Elapsed time: " << elapsedM2.count() << " seconds" << endl<<" "<<endl;

auto start_timeM3 = chrono::high_resolution_clock::now(); //Start time
    mergeSort(revsorted2,0,n-1);
auto end_timeM3 = chrono::high_resolution_clock::now(); //End time
chrono::duration<double> elapsedM3 = end_timeM3 - start_timeM3; //Total time 
    cout<<"Reverse Sorted Array ";
    //print(revsorted2,n);
cout << "Elapsed time: " << elapsedM3.count() << " seconds" << endl<<" "<<endl;
    

    return 0;
}

