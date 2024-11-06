#include <bits/stdc++.h>
using namespace std;

// Deterministic Partition: Uses the first element as the pivot
int partitionDeterministic(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

// Randomized Partition: Selects a random pivot within range [low, high]
int partitionRandomized(vector<int> &arr, int low, int high) {
    int randomPivotIndex = low + rand() % (high - low + 1); 
    swap(arr[low], arr[randomPivotIndex]); 
    return partitionDeterministic(arr, low, high);
}

// Deterministic Quick Sort
void quickSortDeterministic(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partitionDeterministic(arr, low, high);
        quickSortDeterministic(arr, low, pIndex - 1);
        quickSortDeterministic(arr, pIndex + 1, high);
    }
}

// Randomized Quick Sort
void quickSortRandomized(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partitionRandomized(arr, low, high);
        quickSortRandomized(arr, low, pIndex - 1);
        quickSortRandomized(arr, pIndex + 1, high);
    }
}

int main() {
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size();

    // Demonstrate Deterministic Quick Sort
    vector<int> arrDet = arr;
    cout << "Before Deterministic Quick Sort:\n";
    for (int i = 0; i < n; i++) cout << arrDet[i] << " ";
    cout << endl;

    quickSortDeterministic(arrDet, 0, n - 1);
    cout << "After Deterministic Quick Sort:\n";
    for (int i = 0; i < n; i++) cout << arrDet[i] << " ";
    cout << endl;

    // Demonstrate Randomized Quick Sort
    vector<int> arrRand = arr;
    cout << "Before Randomized Quick Sort:\n";
    for (int i = 0; i < n; i++) cout << arrRand[i] << " ";
    cout << endl;

    srand(time(0)); // Seed for random number generation
    quickSortRandomized(arrRand, 0, n - 1);
    cout << "After Randomized Quick Sort:\n";
    for (int i = 0; i < n; i++) cout << arrRand[i] << " ";
    cout << endl;

    return 0;
}
