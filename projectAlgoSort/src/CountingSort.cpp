#include "CountingSort.hpp"

void CountingSort::sort(std::vector<int> toSort) {
	unsigned long long transitions = 0;
	clock_t start, stop;
	start = clock();
	int countingArray[toSort.size()] = { 0 };
	for (unsigned int i = 0; i < toSort.size(); i++) {
		countingArray[toSort[i]]++;
		transitions++;
	}

	int outputIndex = 0;
	for (unsigned int i = 0; i < toSort.size(); i++) {
		while (countingArray[i]--) {
			toSort[outputIndex++] = i;
		}
		transitions++;
	}
	stop = clock();
	mTime = (double) (stop - start) / CLOCKS_PER_SEC;
	mTransitions = transitions;
}
