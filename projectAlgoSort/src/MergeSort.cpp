/**
 * Name        : MergeSort.cpp
 * Description : C++ program for implementation of Merge Sort
 *
 */

#include "MergeSort.hpp"

/**
 * A method that is responsible for merging of two subsets
 * created from vector passed to the function as an argument.
 *
 */

void MergeSort::merge(std::vector<int> &toMerge, int leftIndexOfSet, int mediumIndexOfSet, int rightIndexOfSet, unsigned long long& transitions) {
	int indexOfFirstSubset = 0, indexOfSecondSubset = 0, indexOfMergedSubset;
	int subsetOneSize = mediumIndexOfSet - leftIndexOfSet + 1;
	int subsetTwoSize = rightIndexOfSet - mediumIndexOfSet;
	int leftSubset[subsetOneSize], rightSubset[subsetTwoSize];
	for (int i = 0; i < subsetOneSize; i++) {
		leftSubset[i] = toMerge[leftIndexOfSet + i];
		transitions++;
	}
	for (int j = 0; j < subsetTwoSize; j++) {
		rightSubset[j] = toMerge[mediumIndexOfSet + 1 + j];
		transitions++;
	}
	indexOfMergedSubset = leftIndexOfSet;
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
	while (indexOfFirstSubset < subsetOneSize) {
		toMerge[indexOfMergedSubset] = leftSubset[indexOfFirstSubset];
		indexOfFirstSubset++;
		indexOfMergedSubset++;
		transitions++;
	}
	while (indexOfSecondSubset < subsetTwoSize) {
		toMerge[indexOfMergedSubset] = rightSubset[indexOfSecondSubset];
		indexOfSecondSubset++;
		indexOfMergedSubset++;
		transitions++;
	}
}

/**
 *  A method that is responsible for sorting (Merge Sort) of
 *  elements in the vector passed to the function as an argument.
 *  It divides the vector into subsets, each containing one element.
 *  Such subset, with only one element, is considered sorted. Then,
 *  it merges all sorted subsets using merge function.
 *
 */

void MergeSort::mergeSort(std::vector<int>& toSort, int leftIndexOfSet, int rightIndexOfSet, unsigned long long& transitions) {
	if (leftIndexOfSet < rightIndexOfSet) {
		int mediumIndexOfSet = leftIndexOfSet + (rightIndexOfSet - leftIndexOfSet) / 2;
		mergeSort(toSort, leftIndexOfSet, mediumIndexOfSet, transitions);
		mergeSort(toSort, mediumIndexOfSet + 1, rightIndexOfSet, transitions);
		merge(toSort, leftIndexOfSet, mediumIndexOfSet, rightIndexOfSet, transitions);
	}
}

/**
 * A method that is responsible for the calculation of actual
 * processing time and transitions number of the sorting program
 * according to type and size of the vector passed to the function
 * as an argument.
 *
 * A sorting algorithm used in the program is Merge Sort.
 *
 */

void MergeSort::sort(std::vector<int> toSort) {
	int vectorSize = toSort.size();
	unsigned long long transitions = 0;
	clock_t start, stop;

	start = clock();
	mergeSort(toSort, 0, vectorSize - 1, transitions);
	stop = clock();

	mTime = (double) (stop - start) / CLOCKS_PER_SEC;
	mTransitions = transitions;
}
