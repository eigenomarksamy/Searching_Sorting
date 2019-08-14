/*
 * test_sort.cpp
 *
 *  Created on: Aug 14, 2019
 *      Author: oks
 */

#include "../Sorting/sort.h"

using namespace std;

static void printArray(int *, int);
static void generateArray(int *, int);

void testSelectionSort(void)
{
    int arr_sort[10];
    int arr_size = 0;
    int *result;
    generateArray(arr_sort, 10);
    cout << "Testing Selection Sort\n";
    arr_size = sizeof(arr_sort)/sizeof(arr_sort[0]);
    cout << "Unsorted ";
    printArray(arr_sort, arr_size);
    cout << "Sorted   ";
    result = selectionSort(arr_sort, arr_size);
    printArray(result, arr_size);
}

void testInsertionSort(void)
{
    int arr_sort[10];
    int arr_size = 0;
    int *result;
    generateArray(arr_sort, 10);
    cout << "Testing Insertion Sort\n";
    arr_size = sizeof(arr_sort)/sizeof(arr_sort[0]);
    cout << "Unsorted ";
    printArray(arr_sort, arr_size);
    cout << "Sorted   ";
    result = insertionSort(arr_sort, arr_size);
    printArray(result, arr_size);
}

void testMergeSort(void)
{
    int arr_sort[10];
    int arr_size = 0;
    int *result;
    generateArray(arr_sort, 10);
    cout << "Testing Merge Sort\n";
    arr_size = sizeof(arr_sort)/sizeof(arr_sort[0]);
    cout << "Unsorted ";
    printArray(arr_sort, arr_size);
    cout << "Sorted   ";
    result = mergeSort(arr_sort, 0, arr_size - 1);
    printArray(result, arr_size);
}

void testHeapSort(void)
{
    int arr_sort[10];
    int arr_size = 0;
    int *result;
    generateArray(arr_sort, 10);
    cout << "Testing Heap Sort\n";
    arr_size = sizeof(arr_sort)/sizeof(arr_sort[0]);
    cout << "Unsorted ";
    printArray(arr_sort, arr_size);
    cout << "Sorted   ";
    result = heapSort(arr_sort, arr_size);
    printArray(result, arr_size);
}

void testQuickSort(void)
{
    int arr_sort[10];
    int arr_size = 0;
    int *result;
    generateArray(arr_sort, 10);
    cout << "Testing Quick Sort\n";
    arr_size = sizeof(arr_sort)/sizeof(arr_sort[0]);
    cout << "Unsorted ";
    printArray(arr_sort, arr_size);
    cout << "Sorted   ";
    result = quickSort(arr_sort, 0, arr_size - 1);
    printArray(result, arr_size);
}

void testRadixSort(void)
{
    int arr_sort[10];
    int arr_size = 0;
    int *result;
    generateArray(arr_sort, 10);
    cout << "Testing Count Sort\n";
    arr_size = sizeof(arr_sort)/sizeof(arr_sort[0]);
    cout << "Unsorted ";
    printArray(arr_sort, arr_size);
    cout << "Sorted   ";
    result = radixSort(arr_sort, arr_size);
    printArray(result, arr_size);
}

void testCountSort(void)
{
    char arr[] = "omarkhaledsamy";
    cout << "Testing Count Sort\n";
    cout << "Unsorted String: ";
    cout << arr;
    cout << endl;
    cout << "Sorted   String: ";
    countSort(arr);
    cout << arr;
    cout << endl;
}

void testBucketSort(void)
{
    float arr[] = {0.8971, 0.5651, 0.1234, 0.0226, 0.0015, 0.9989, 0.8971, 0.6562, 0.3434, 0.4321};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    cout << "Testing Bucket Sort\n";
    cout << "Unsorted Array: ";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "Sorted   Array: ";
    bucketSort(arr, arr_size);
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

static void generateArray(int * arr, int size)
{
    srand(time(NULL));
    for(int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
}

void printArray(int arr[], int size)
{
    cout << "Array: ";
    for (int i = 0; i < (size - 1); i++)
    {
        cout << arr[i] << ", ";
    }
    cout << arr[size - 1] << "\n";
}
