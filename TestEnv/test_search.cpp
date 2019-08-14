/*
 * test_search.cpp
 *
 *  Created on: Aug 14, 2019
 *      Author: oks
 */

#include "test_search.h"

using namespace std;

static void printArray(int *, int);

void testLinearSearch(void)
{
    int arr_search[10];
    int arr_size = 0;
    int to_search = 28;
    int result;
    for(int i = 0; i < 10; i++)
    {
        arr_search[i] = i;
    }
    cout << "Testing Linear Search, with value " << to_search << "\n";
    arr_size = sizeof(arr_search)/sizeof(arr_search[0]);
    printArray(arr_search, arr_size);
    result = linearSearch(arr_search, arr_size, to_search);
    (-1 == result) ? cout << "Element not in array!" << "\n" :
            cout << "Element at: " << result;
}

void testBinarySearch(void)
{
    int arr_search[10];
    int left_index = 0;
    int right_index = 0;
    int arr_size = 0;
    int to_search = 1;
    int result;
    for(int i = 0; i < 10; i++)
    {
        arr_search[i] = i;
    }
    cout << "Testing Binary Search, with value " << to_search << "\n";
    arr_size = (sizeof(arr_search)/sizeof(arr_search[0]));
    right_index = arr_size - 1;
    printArray(arr_search, arr_size);
    result = binarySearch(arr_search, left_index, right_index, to_search);
    (-1 == result) ? cout << "Element not in array!" << "\n" :
            cout << "Element at: " << result;
}

void testJumpSearch(void)
{
    int arr_search[16];
    int arr_size = 0;
    int to_search = 14;
    int result;
    for(int i = 0; i < 16; i++)
    {
        arr_search[i] = i;
    }
    cout << "Testing Jump Search, with value " << to_search << "\n";
    arr_size = (sizeof(arr_search)/sizeof(arr_search[0]));
    printArray(arr_search, arr_size);
    result = jumpSearch(arr_search, arr_size, to_search);
    (-1 == result) ? cout << "Element not in array!" << "\n" :
            cout << "Element at: " << result;
}

void testInterpolationSearch(void)
{
    int arr_search[16];
    int arr_size = 0;
    int to_search = 21;
    int result;
    for(int i = 0; i < 16; i++)
    {
        arr_search[i] = i * 2;
    }
    cout << "Testing Interpolation Search, with value " << to_search << "\n";
    arr_size = (sizeof(arr_search)/sizeof(arr_search[0]));
    printArray(arr_search, arr_size);
    result = interpolationSearch(arr_search, arr_size, to_search);
    (-1 == result) ? cout << "Element not in array!" << "\n" :
            cout << "Element at: " << result;
}

static void printArray(int arr[], int size)
{
    cout << "Array: ";
    for (int i = 0; i < (size - 1); i++)
    {
        cout << arr[i] << ", ";
    }
    cout << arr[size - 1] << "\n";
}
