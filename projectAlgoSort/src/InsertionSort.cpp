/**
 * Name        : InsertionSort.cpp
 * Description : C++ program for implementation of Insertion Sort
 *
 */

#include "InsertionSort.hpp"

/**
 * A method that is responsible for the calculation of actual
 * processing time and transitions number of the sorting program
 * according to type and size of the vector passed to the function
 * as an argument.
 *
 * A sorting algorithm used in the program is Insertion Sort.
 * It moves elements of the vector that are smaller than temporary variable tmp
 * to one position back of their current position and builds the final
 * sorted vector one item at a time
 *
 */

void InsertionSort::sort(std::vector<int> toSort) {
	int sizeOfVector = toSort.size();
	unsigned long long transitions = 0;
	clock_t start, stop;

	start = clock();
	int tmp, tmpToCompare;
	for (int i = toSort.size() - 2; i >= 0; i--) {
		tmp = toSort[i];
		tmpToCompare = i + 1;
		while ((tmpToCompare < sizeOfVector) && (tmp > toSort[tmpToCompare])) {
			toSort[tmpToCompare - 1] = toSort[tmpToCompare];
			tmpToCompare++;
			transitions++;
		}
		toSort[tmpToCompare - 1] = tmp;
		transitions++;
	}
	stop = clock();

	mTime = (double) (stop - start) / CLOCKS_PER_SEC;
	mTransitions = transitions;
}
