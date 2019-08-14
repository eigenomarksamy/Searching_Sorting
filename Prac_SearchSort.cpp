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
    cout << "\n";
    testLinearSearch();
    cout << "\n";
    testBinarySearch();
    cout << "\n";
    testJumpSearch();
    cout << "\n";
    testInterpolationSearch();
    cout << "\n";
    cout << "\n---------------------------------------\n";
    cout << "Testing Sorting Algorithms\n";
    cout << "\n";
    testSelectionSort();
    cout << "\n";
    testInsertionSort();
    cout << "\n";
    testMergeSort();
    cout << "\n";
    testHeapSort();
    cout << "\n";
    testQuickSort();
    cout << "\n";
    testRadixSort();
    cout << "\n";
    testCountSort();
    cout << "\n";
    testBucketSort();
    cout << "\n";
    cout << "\n---------------------------------------\n";
    return 0;
}
