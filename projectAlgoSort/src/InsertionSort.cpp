#include "InsertionSort.hpp"

void InsertionSort::sort(std::vector<int> toSort) {
	unsigned long long transitions = 0;
	clock_t start, stop;
	start = clock();
	int tmp, tmpToCompare, sizeOfVector;
	sizeOfVector = toSort.size();
	for (int i = toSort.size() - 2; i >= 0; i--) {
		tmp = toSort[i];
		tmpToCompare = i + 1;
		while ((tmp < sizeOfVector) && (tmp > toSort[tmpToCompare])) {
			toSort[tmpToCompare - 1] = toSort[tmpToCompare];
			tmpToCompare++;
			transitions++;
		}
		toSort[tmpToCompare - 1] = tmp;
	}
	stop = clock();
	mTime = (double) (stop - start) / CLOCKS_PER_SEC;
	mTransitions = transitions;
}
