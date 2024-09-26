#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

int partition(int arr[], int low, int high, int pivotChoice) {
    int pivot;
    if (pivotChoice == 1) {
        pivot = arr[low];
    } else if (pivotChoice == 2) {
        int randomIndex = low + rand() % (high - low + 1);
        std::swap(arr[randomIndex], arr[low]);
        pivot = arr[low];
    } else if (pivotChoice == 3) {
        int mid = low + (high - low) / 2;
        if ((arr[low] <= arr[mid] && arr[mid] <= arr[high]) || (arr[high] <= arr[mid] && arr[mid] <= arr[low])) {
            pivot = arr[mid];
            std::swap(arr[mid], arr[low]);
        } else if ((arr[mid] <= arr[low] && arr[low] <= arr[high]) || (arr[high] <= arr[low] && arr[low] <= arr[mid])) {
            pivot = arr[low];
        } else {
            pivot = arr[high];
            std::swap(arr[high], arr[low]);
        }
    }

    int i = low + 1;
    int j = high;

    while (true) {
        while (i <= j && arr[i] <= pivot) {
            i++;
        }
        while (i <= j && arr[j] >= pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
        } else {
            break;
        }
    }

    std::swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high, int pivotChoice) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, pivotChoice);
        quickSort(arr, low, pivotIndex - 1, pivotChoice);
        quickSort(arr, pivotIndex + 1, high, pivotChoice);
    }
}

int main() {
    const int n = 500000;
    int arr[500000] = {0};
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = 0; i < n; i++) {
        arr[i] = 1 + std::rand() % 500000;
    }

    int pivotChoice;
    string choice;
    cout << "Choose pivot choice (1: First element, 2: Random element, 3: Median of first, middle, and last): ";
    cin >> pivotChoice;
    if (pivotChoice == 1){choice = "First Element"; }
    if (pivotChoice == 2){choice = "Random Element";}
    if (pivotChoice == 3){choice = "Median Element";}
    srand(time(nullptr)); 

auto start_timeS1 = chrono::high_resolution_clock::now(); //Start time
    quickSort(arr, 0, n - 1, pivotChoice);
auto end_timeS1 = chrono::high_resolution_clock::now(); //End time
chrono::duration<double> elapsedS1 = end_timeS1 - start_timeS1; //Total time 
cout << "Elapsed time for " << choice << " Pivot: " << elapsedS1.count() << " seconds" << endl<<" "<<endl;

    std::cout << "Sorted array: ";
    for (int i = 0; i < 20; i++) {
        cout << arr[i] << " ";
    }
    cout << std::endl;

    return 0;
}
