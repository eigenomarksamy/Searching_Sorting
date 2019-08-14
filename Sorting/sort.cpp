/*
 * sort.cpp
 *
 *  Created on: Aug 14, 2019
 *      Author: oks
 */

#include "sort.h"

#define MAX_SIZE_RET_ARR     50
#define RANGE                 255

using namespace std;

static void copyArray(int *, int *, int);
static void swap(int *, int *);
static int getMax(int *, int);
static void merge(int *, int, int, int);
static void heapify(int *, int, int);
static int partition(int *, int, int);
static void countSort(int *, int, int);


int* selectionSort(int arr[], int size)
{
    static int ret_arr_selec[MAX_SIZE_RET_ARR];
    int i, j, min_idx;
    copyArray(arr, ret_arr_selec, size);
    for (i = 0; i < size-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < size; j++)
        {
            if (ret_arr_selec[j] < ret_arr_selec[min_idx])
            {
                min_idx = j;
            }
        }
        swap(ret_arr_selec[min_idx], ret_arr_selec[i]);
    }
    return ret_arr_selec;
}

int* insertionSort(int arr[], int size)
{
    static int ret_arr_insrt[MAX_SIZE_RET_ARR];
    int i, j, key;
    copyArray(arr, ret_arr_insrt, size);
    for (i = 0; i < size; i++)
    {
        key = ret_arr_insrt[i];
        j = i - 1;
        while (j >= 0 && ret_arr_insrt[j] > key)
        {
            ret_arr_insrt[j + 1] = ret_arr_insrt[j];
            j -= 1;
        }
        ret_arr_insrt[j + 1] = key;
    }
    return ret_arr_insrt;
}

static void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

int* mergeSort(int arr[], int left, int right)
{
    static int ret_arr_mrge[MAX_SIZE_RET_ARR];
    copyArray(arr, ret_arr_mrge, right+1);
    if (left < right)
    {
        int mid = left + (right - left)/2;
        (void)mergeSort(ret_arr_mrge, left, mid);
        (void)mergeSort(ret_arr_mrge, mid+1, right);
        merge(ret_arr_mrge, left, mid, right);
    }
    return ret_arr_mrge;
}

static void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

int* heapSort(int arr[], int size)
{
    static int ret_arr_heap[MAX_SIZE_RET_ARR];
    copyArray(arr, ret_arr_heap, size);
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(ret_arr_heap, size, i);
    for (int i = size - 1; i >= 0; i--)
    {
        swap(ret_arr_heap[0], ret_arr_heap[i]);
        heapify(ret_arr_heap, i, 0);
    }
    return ret_arr_heap;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int  i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int* quickSort(int arr[], int low, int high)
{
    static int ret_arr_quick[MAX_SIZE_RET_ARR];
    copyArray(arr, ret_arr_quick, high + 1);
    if (low < high)
    {
        int pi = partition(ret_arr_quick, low, high);
        (void)quickSort(ret_arr_quick, low, pi - 1);
        (void)quickSort(ret_arr_quick, pi + 1, high);
    }
    return ret_arr_quick;
}

void countSort(int arr[], int size, int exp)
{
    int output[size];
    int i, count[10] = {0};
    for (i = 0; i < size; i++)
        count[ (arr[i]/exp)%10 ]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = size - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
    for (i = 0; i < size; i++)
        arr[i] = output[i];
}

int* radixSort(int arr[], int size)
{
    static int ret_arr_radix[MAX_SIZE_RET_ARR];
    copyArray(arr, ret_arr_radix, size);
    int m = getMax(ret_arr_radix, size);
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(ret_arr_radix, size, exp);
    return ret_arr_radix;
}

void countSort(char arr[])
{
    char output[strlen((char*)arr)];
    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));
    for (i = 0; arr[i]; ++i)
        ++count[(int)arr[i]];
    for (i = 1; i <= RANGE; ++i)
        count[i] += count[i - 1];
    for (i = 0; arr[i]; ++i)
    {
        output[count[(int)arr[i]] - 1] = arr[i];
        --count[(int)arr[i]];
    }
    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
}

void bucketSort(float arr[], int size)
{
    vector<float> b[size];
    for (int i = 0; i < size; i++)
    {
        int bi = size * arr[i];
        b[bi].push_back(arr[i]);
    }
    for (int i = 0; i < size; i++)
        sort(b[i].begin(), b[i].end());
    int index = 0;
    for (int i = 0; i < size; i++)
        for (unsigned int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}

static int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

static void swap(int *a, int *b)
{
    *b = *a + *b;
    *a = *b - *a;
    *b = *b - *a;
}

static void copyArray(int arr1[], int arr2[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        arr2[i] = arr1[i];
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
