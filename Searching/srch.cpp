/*
 * srch.c
 *
 *  Created on: Aug 14, 2019
 *      Author: oks
 */

#include "srch.h"

using namespace std;

int linearSearch(int arr[], int size, int to_find)
{
    int ret_val = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == to_find)
        {
            ret_val = i;
            break;
        }
    }
    return ret_val;
}

int binarySearch(int arr[], int left, int right, int to_find)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == to_find)
        {
            return arr[mid];
        }
        if (arr[mid] > to_find)
        {
            return binarySearch(arr, left, mid - 1, to_find);
        }
        return binarySearch(arr, mid + 1, right, to_find);
    }
    return -1;
}

int jumpSearch(int arr[], int size, int to_find)
{
    int step = sqrt(size);
    int prev = 0;
    while (arr[min(step, size) - 1] < to_find)
    {
        prev = step;
        step += sqrt(size);
        if (prev >= size)
            return -1;
    }
    while (arr[prev] < to_find)
    {
        prev++;
        if (prev == min(step, size))
            return -1;
    }
    if (arr[prev] == to_find)
        return prev;
    return -1;
}

int interpolationSearch(int arr[], int size, int to_find)
{
    int n = size;
    int x = to_find;
    int lo = 0, hi = (n - 1);
    while (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {
        if (lo == hi)
        {
            if (arr[lo] == x) return lo;
            return -1;
        }
        int pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));
        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x)
            lo = pos + 1;
        else
            hi = pos - 1;
    }
    return -1;
}
