/**
 * Name        : CountingSort.cpp
 * Description : C++ program for implementation of Counting Sort
 *
 */

#include "CountingSort.hpp"

/**
 * A method that is responsible for the calculation of actual
 * processing time and transitions number of the sorting program
 * according to type and size of the vector passed to the function
 * as an argument.
 *
 * A sorting algorithm used in the program is Counting Sort.
 * It uses a count array to store count of individual elements from the vector and then
 * builds the final sorted vector one item at a time.
 *
 */

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
			transitions++;
		}
		transitions++;
	}
	stop = clock();

	mTime = (double) (stop - start) / CLOCKS_PER_SEC;
	mTransitions = transitions;
}
