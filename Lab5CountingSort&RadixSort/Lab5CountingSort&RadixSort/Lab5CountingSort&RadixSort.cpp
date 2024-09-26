#include <iostream>
#include <chrono>
#include <cstdlib>  
#include <ctime>

using namespace std;
using namespace chrono;

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
void countingSort(int arr[], int size) {
    int max = findMax(arr, size);
    int* output = new int[size];
    int* count = new int[max + 1];
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
    delete[] output;
    delete[] count;
}

void countingSortRadix(int arr[], int n, int exp) 
{ 

	// Output array 
	int* output = new int[n]; 
	int i, count[10] = { 0 }; 

	// Store count of occurrences 
	// in count[] 
	for (i = 0; i < n; i++) 
		count[(arr[i] / exp) % 10]++; 

	// Change count[i] so that count[i] 
	// now contains actual position 
	// of this digit in output[] 
	for (i = 1; i < 10; i++) 
		count[i] += count[i - 1]; 

	// Build the output array 
	for (i = n - 1; i >= 0; i--) { 
		output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
		count[(arr[i] / exp) % 10]--; 
	} 

	// Copy the output array to arr[], 
	// so that arr[] now contains sorted 
	// numbers according to current digit 
	for (i = 0; i < n; i++) 
		arr[i] = output[i]; 
} 

// The main function to that sorts arr[] 
// of size n using Radix Sort 
void radixSort(int arr[], int n) 
{ 
	int m = findMax(arr, n); 

	for (int exp = 1; m / exp > 0; exp *= 10) 
		countingSortRadix(arr, n, exp); 
} 

void radixSort(int arr[],int n);


int main() {
    const int size = 500000;
    int arr[500000] = {0};
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = 0; i < size; i++) {
        arr[i] = 1 + std::rand() % 500000;
    }

    // cout<<endl << "Original Array: ";
    // for (int i = 0; i < size; i++) {
    //     cout << arr[i] << " ";
    // }
    cout<<endl<<endl;

    int* unsorted = new int[size]; 
    for (int i = 0; i < size; i++) {
        unsorted[i] = arr[i];
    }

auto start_timeS1 = chrono::high_resolution_clock::now(); //Start time
    countingSort(arr, size);
auto end_timeS1 = chrono::high_resolution_clock::now(); //End time

    // cout << "Sorted Array using Counting Sort: ";
    // for (int i = 0; i < size; i++) {
    //     cout << arr[i] << " ";
    // }
chrono::duration<double> elapsedS1 = end_timeS1 - start_timeS1; //Total time 
cout << "Elapsed time for Counting Sort: " << elapsedS1.count() << " seconds" << endl<<" "<<endl;

auto start_timeS2 = chrono::high_resolution_clock::now(); //Start time
    radixSort(unsorted, size);
auto end_timeS2 = chrono::high_resolution_clock::now(); //End time

    // cout << "Sorted Array using Radix Sort: ";
    // for (int i = 0; i < size; i++) {
    //     cout << unsorted[i] << " ";
    // }
chrono::duration<double> elapsedS2 = end_timeS2 - start_timeS2; //Total time 
cout << "Elapsed time for Radix Sort: " << elapsedS2.count() << " seconds" << endl<<" "<<endl;
    delete[] unsorted;
    return 0;
}



