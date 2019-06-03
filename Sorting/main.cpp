#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <stdlib.h>
#include <iomanip>
#include <cstring>

using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

void InsertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int j = i;
        while(j && arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}

void ShellSort(int arr[], int n) {


}

void SelectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[min] > arr[j])
                min = j;
        }
        if (arr[i] != arr[min])
            swap(arr[i], arr[min]);
    }
}

void BubbleSort(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        int numberOfSwaps = 0;
        for(int j = 0; j < n - 1 ; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                numberOfSwaps++;
            }
        }
        if (numberOfSwaps == 0) break;
    }

}

void merge(int arr[], int left, int mid, int right ) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(int i = 0; i < n2; i++)
        R[i] = arr[i + mid + 1];

    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
           arr[k] = L[i];
           i++;
        }
        else {
           arr[k] = R[j];
           j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2; // or left + (right-left) / 2 avoid overflow
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void MergeSort(int arr[], int n) {
    mergeSort(arr, 0, n - 1);
}

int partion(int arr[], int left, int right ) {
    int pivotValue = arr[left];
    int pivotPosition = left;

    for(int i = left + 1; i < right; i++) {
        if (arr[i] < pivotValue) {
            swap(arr[i], arr[pivotPosition + 1]);
            pivotPosition++;
        }
    }

    swap(arr[left], arr[pivotPosition]);

    return pivotPosition;
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int p = partion(arr, left, right);
        quickSort(arr, left, p);
        quickSort(arr, p + 1, right);

    }
}

void insertionSort(int arr[], int left, int n) {
    for(int i = left; i < n; i++) {
        int j = i;
        while(j && arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}

void quickSortOptimize(int arr[], int left, int right) {
    if (left < right) {

        if (right - left < 10) {
            insertionSort(arr, left, right);
        }
        else {
            int p = partion(arr, left, right);
            quickSortOptimize(arr, left, p);
            quickSortOptimize(arr, p + 1, right);
        }
    }
}

void QuickSort(int arr[], int n) {
    quickSort(arr, 0, n);
}

void CountingSort(int arr[], int n){
    int *new_arr = new int[n];
    memset(new_arr, 0, n);

    for(int i = 0; i < n; i++){
        new_arr[arr[i]]++;
    }

    int index = 0;
    for(int i = 0; i < n; i++) {
        for(int j = new_arr[i]; j > 0; j--) {
            arr[index] = i;
            index++;
        }
    }
    delete[] new_arr;
}

int main() {
    srand(time(0));

    //int n = 1000;
    //int n = 10000;
    int n = 100000; //good test  case 0
    //int n = 1000000; //good test  case 1
    //int n = 10000000; // merger + CountingSort

    //int n = 10;
    int *arr   = new int[n];
    int *arr_1 = new int[n];
    int *arr_2 = new int[n];
    int *arr_3 = new int[n];
    int *arr_4 = new int[n];
    int *arr_5 = new int[n];
    int *arr_6 = new int[n];
    // int *arr_7 = new int[n];
    // int *arr_8 = new int[n];
    // int *arr_9 = new int[n];
    // int *arr_10 = new int[n];


    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
        arr_1[i] = arr[i];
        arr_2[i] = arr[i];
        arr_3[i] = arr[i];
        arr_4[i] = arr[i];
        arr_5[i] = arr[i];
        arr_6[i] = arr[i];
        // arr_7[i] = arr[i];
        // arr_8[i] = arr[i];
        // arr_9[i] = arr[i];
        // arr_10[i] = arr[i];
    }

    cerr << "Starting" << "............." << '\n';
    cerr << "N = " << n << '\n';
    clock_t beginTime, endTime;
    double elapsedTime;

/////////////////////////////////////////////////////////////////////////////////
    beginTime = clock();
    InsertionSort(arr, n);
    endTime = clock();
    elapsedTime = (double) (endTime - beginTime);
    cerr << "Time elapsed InsertionSort: "<< setprecision(10) << elapsedTime / CLOCKS_PER_SEC << " s.\n" << endl;


    beginTime = clock();
    MergeSort(arr_1, n);
    endTime = clock();
    elapsedTime = (double) (endTime - beginTime);
    cerr << "Time elapsed MergeSort: " <<  setprecision(10) << elapsedTime / CLOCKS_PER_SEC << " s.\n" << endl;

    beginTime = clock();
    QuickSort(arr_2, n);
    endTime = clock();
    elapsedTime = (double) (endTime - beginTime);
    cerr << "Time elapsed QuickSort: " <<  setprecision(10) <<elapsedTime / CLOCKS_PER_SEC << " s.\n" << endl;

    beginTime = clock();
    quickSortOptimize(arr_3, 0, n);
    endTime = clock();
    elapsedTime = (double) (endTime - beginTime);
    cerr << "Time elapsed quickSortOptimize: " <<  setprecision(10) <<elapsedTime / CLOCKS_PER_SEC << " s.\n" << endl;

    beginTime = clock();
    BubbleSort(arr_4, n);
    endTime = clock();
    elapsedTime = (double) (endTime - beginTime);
    cerr << "Time elapsed BubbleSort: " <<  setprecision(10) <<elapsedTime / CLOCKS_PER_SEC << " s.\n" << endl;

    beginTime = clock();
    SelectionSort(arr_5, n);
    endTime = clock();
    elapsedTime = (double) (endTime - beginTime);
    cerr << "Time elapsed SelectionSort: " <<  setprecision(10) <<elapsedTime / CLOCKS_PER_SEC << " s.\n" << endl;


    beginTime = clock();
    CountingSort(arr_6, n);
    endTime = clock();
    elapsedTime = (double) (endTime - beginTime);
    cerr << "Time elapsed CountingSort: " <<  setprecision(10) <<elapsedTime / CLOCKS_PER_SEC << " s.\n" << endl;





    return 0;
}
