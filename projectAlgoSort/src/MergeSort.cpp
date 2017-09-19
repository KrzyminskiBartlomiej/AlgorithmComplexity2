//============================================================================
// Name        : MergeSort.cpp
// Description : C++ program for implementation of Merge Sort
//============================================================================
#include "MergeSort.hpp"

// The function responsible for merging subsets created during Merge Sorting process
void MergeSort::merge(std::vector<int> &toMerge, int leftIndexOfSet, int mediumIndexOfSet, int rightIndexOfSet, unsigned long long& transitions) {
	int indexOfFirstSubset, indexOfSecondSubset, indexOfMergedSubset;

	// Calculate the size of subsets
	int subsetOneSize = mediumIndexOfSet - leftIndexOfSet + 1;
	int subsetTwoSize = rightIndexOfSet - mediumIndexOfSet;

	// Create temporary subsets
	int leftSubset[subsetOneSize], rightSubset[subsetTwoSize];

	// Copy elements from the container to the left subset
	for (int i = 0; i < subsetOneSize; i++) {
		leftSubset[i] = toMerge[leftIndexOfSet + i];
		transitions++;
	}

	// Copy elements from the container to the right subset
	for (int j = 0; j < subsetTwoSize; j++) {
		rightSubset[j] = toMerge[mediumIndexOfSet + 1 + j];
		transitions++;
	}

	indexOfFirstSubset = 0; // Initial index of first subset
	indexOfSecondSubset = 0; // Initial index of second subset
	indexOfMergedSubset = leftIndexOfSet; // Initial index of merged subset

	// Merge the temporary subsets back into the container
	while (indexOfFirstSubset < subsetOneSize && indexOfSecondSubset < subsetTwoSize) {
		if (leftSubset[indexOfFirstSubset] <= rightSubset[indexOfSecondSubset]) {
			toMerge[indexOfMergedSubset] = leftSubset[indexOfFirstSubset];
			indexOfFirstSubset++;
		} else {
			toMerge[indexOfMergedSubset] = rightSubset[indexOfSecondSubset];
			indexOfSecondSubset++;
		}
		indexOfMergedSubset++;
		transitions++;
	}

	// Copy the remaining elements of left subset, if there are any
	while (indexOfFirstSubset < subsetOneSize) {
		toMerge[indexOfMergedSubset] = leftSubset[indexOfFirstSubset];
		indexOfFirstSubset++;
		indexOfMergedSubset++;
		transitions++;
	}

	// Copy the remaining elements of right subset, if there are any
	while (indexOfSecondSubset < subsetTwoSize) {
		toMerge[indexOfMergedSubset] = rightSubset[indexOfSecondSubset];
		indexOfSecondSubset++;
		indexOfMergedSubset++;
		transitions++;
	}
}

// The function to do Merge Sort
void MergeSort::mergeSort(std::vector<int>& toSort, int leftIndexOfSet, int rightIndexOfSet, unsigned long long& transitions) {

	// If left index of set is smaller than right index of set
	if (leftIndexOfSet < rightIndexOfSet) {

		// Calculate the middle index of set
		int mediumIndexOfSet = leftIndexOfSet + (rightIndexOfSet - leftIndexOfSet) / 2;

		// Recursively sort subsets (first and second halves)
		mergeSort(toSort, leftIndexOfSet, mediumIndexOfSet, transitions);
		mergeSort(toSort, mediumIndexOfSet + 1, rightIndexOfSet, transitions);

		// Merge all sorted subsets
		merge(toSort, leftIndexOfSet, mediumIndexOfSet, rightIndexOfSet, transitions);
	}
}

// The main function with one argument to do sorting
void MergeSort::sort(std::vector<int> toSort) {
	int vectorSize = toSort.size();
	unsigned long long transitions = 0; // The flag counting transitions
	clock_t start, stop; // Variables used to calculate the processor time consumed by the program

	start = clock();
	mergeSort(toSort, 0, vectorSize - 1, transitions);
	stop = clock();

	// Convert the processor time consumed by the program to the actual processing time of a program
	mTime = (double) (stop - start) / CLOCKS_PER_SEC;
	mTransitions = transitions;
}
