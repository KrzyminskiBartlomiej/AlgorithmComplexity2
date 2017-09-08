#include "QuickSort.hpp"
#include <time.h>
#include <cstdlib>

void QuickSort::quickSort(std::vector<int>& toSort, int low, int high,
		unsigned long long& transitions) {
	int i, j, pivot;
	i = (low + high) / 2;
	pivot = toSort[i];
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
		transitions++;
	}
	if (j + 1 < high) {
		quickSort(toSort, j + 1, high, transitions);
		transitions++;
	}
}

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

