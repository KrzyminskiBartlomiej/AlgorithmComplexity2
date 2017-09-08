#include "MergeSort.hpp"

void MergeSort::merge(std::vector<int> &toMerge, int leftIndexOfSet,
		int mediumIndexOfSet, int rightIndexOfSet,
		unsigned long long& transitions) {
	int indexOfFirstSubset, indexOfSecondSubset, indexOfMergedSubset;
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
	indexOfFirstSubset = 0;
	indexOfSecondSubset = 0;
	indexOfMergedSubset = leftIndexOfSet;
	while (indexOfFirstSubset < subsetOneSize
			&& indexOfSecondSubset < subsetTwoSize) {
		if (leftSubset[indexOfFirstSubset]
				<= rightSubset[indexOfSecondSubset]) {
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
void MergeSort::mergeSort(std::vector<int>& toSort, int leftIndexOfSet,
		int rightIndexOfSet, unsigned long long &transitions) {
	if (leftIndexOfSet < rightIndexOfSet) {
		int mediumIndexOfSet = leftIndexOfSet
				+ (rightIndexOfSet - leftIndexOfSet) / 2;

		mergeSort(toSort, leftIndexOfSet, mediumIndexOfSet, transitions);
		mergeSort(toSort, mediumIndexOfSet + 1, rightIndexOfSet, transitions);
		merge(toSort, leftIndexOfSet, mediumIndexOfSet, rightIndexOfSet,
				transitions);
		transitions++;
	}
}
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
