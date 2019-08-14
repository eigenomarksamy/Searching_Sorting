/*
 * sort.h
 *
 *  Created on: Aug 14, 2019
 *      Author: oks
 */

#ifndef SORTING_SORT_H_
#define SORTING_SORT_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <bits/stdc++.h>

extern int* selectionSort(int *, int);
extern int* insertionSort(int *, int);
extern int* mergeSort(int *, int, int);
extern int* heapSort(int *, int);
extern int* quickSort(int*, int, int);
extern int* radixSort(int *, int);
extern void bucketSort(float *, int);
extern void countSort(char *);

#endif /* SORTING_SORT_H_ */
