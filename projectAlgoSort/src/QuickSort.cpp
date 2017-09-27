/**
 * Name        : QuickSort.cpp
 * Description : C++ program for implementation of Quick Sort
 *
 */

#include "QuickSort.hpp"

/**
 * A method that is responsible for sorting (Quick Sort) of
 * elements in the vector passed to the function as an argument.
 * It takes a middle element as a pivot, places the pivot element at
 * its correct position in the sorted vector, and places all smaller
 * elements to the left of the pivot and all greater element to the
 * right of the pivot. Then, it recursively sorts elements of the left
 * subset (elements on the left of the pivot) and the right subset
 * (elements on the right of the pivot) creating final, sorted vector.
 *
 */

void QuickSort::quickSort(std::vector<int>& toSort, int low, int high, unsigned long long& transitions) {
	int i, j;
	i = (low + high) / 2;
	int pivot = toSort[i];
	toSort[i] = toSort[high];
	for (i = j = low; i < high; i++) {
		if (toSort[i] < pivot) {
			std::swap(toSort[i], toSort[j]);
			j++;
			transitions++;
		}
		transitions++;
	}
	toSort[high] = toSort[j];
	toSort[j] = pivot;
	if (low < j - 1) {
		quickSort(toSort, low, j - 1, transitions);
	}
	if (j + 1 < high) {
		quickSort(toSort, j + 1, high, transitions);
	}
}

/**
 * A method that is responsible for the calculation of actual
 * processing time and transitions number of the sorting program
 * according to type and size of the vector passed to the function
 * as an argument.
 *
 * A sorting algorithm used in the program is Quick Sort.
 *
 */

void QuickSort::sort(std::vector<int> toSort) {
	int low = 0;
	int high = toSort.size() - 1;
	unsigned long long transitions = 0;
	clock_t start, stop;

	start = clock();
	quickSort(toSort, low, high, transitions);
	stop = clock();

	mTime = (double) (stop - start) / CLOCKS_PER_SEC;
	mTransitions = transitions;
}
