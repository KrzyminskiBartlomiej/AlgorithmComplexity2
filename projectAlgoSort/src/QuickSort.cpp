//============================================================================
// Name        : QuickSort.cpp
// Description : C++ program for implementation of Quick Sort
//============================================================================
#include "QuickSort.hpp"

// The function to do Quick Sort, where low is starting index and high is ending index
void QuickSort::quickSort(std::vector<int>& toSort, int low, int high, unsigned long long& transitions) {
	int i, j; // Temporary indexes used in Quick Sort

	// Calculate a middle index of set
	i = (low + high) / 2;

	// Take middle element as pivot
	int pivot = toSort[i];
	toSort[i] = toSort[high];
	for (i = j = low; i < high; i++) {

		// If current element is smaller than pivot
		if (toSort[i] < pivot) {
			std::swap(toSort[i], toSort[j]);

			// Increment index of smaller element
			j++;
			transitions++;
		}
		transitions++;
	}

	// Change the position of the pivot
	toSort[high] = toSort[j];
	toSort[j] = pivot;

	// Recursively sort elements of left subset (elements on the left of the pivot)
	if (low < j - 1) {
		quickSort(toSort, low, j - 1, transitions);
	}

	// Recursively sort elements of right subset (elements on the right of the pivot)
	if (j + 1 < high) {
		quickSort(toSort, j + 1, high, transitions);
	}
}

// The main function with one argument to do sorting
void QuickSort::sort(std::vector<int> toSort) {
	int low = 0;
	int high = toSort.size() - 1;
	unsigned long long transitions = 0; // The flag counting transitions
	clock_t start, stop; // Variables used to calculate the processor time consumed by the program

	start = clock();
	quickSort(toSort, low, high, transitions);
	stop = clock();

	// Convert the processor time consumed by the program to the actual processing time of a program
	mTime = (double) (stop - start) / CLOCKS_PER_SEC;
	mTransitions = transitions;
}
