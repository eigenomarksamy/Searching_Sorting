//============================================================================
// Name        : Prac_SearchSort.cpp
// Author      : OmarKSamy
// Version     :
// Copyright   : Your copyright notice
// Description : Searching and Sorting in C++, Ansi-style
//============================================================================

#include "TestEnv/test_search.h"
#include "TestEnv/test_sort.h"

using namespace std;

int main() {
    cout << "---------------------------------------\n";
    cout << "Testing Searching Algorithms\n";
    testLinearSearch();
    testBinarySearch();
    testJumpSearch();
    testInterpolationSearch();
    cout << "\n---------------------------------------\n";
    cout << "Testing Sorting Algorithms\n";
    testSelectionSort();
    testInsertionSort();
    testMergeSort();
    testHeapSort();
    testQuickSort();
    testRadixSort();
    testCountSort();
    testBucketSort();
    cout << "\n---------------------------------------\n";
    return 0;
}
