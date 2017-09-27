/**
 * Name        : BubbleSort.cpp
 * Description : C++ program for implementation of Bubble Sort
 *
 */

#include "BubbleSort.hpp"

/**
 * A method that is responsible for the calculation of actual
 * processing time and transitions number of the sorting program
 * according to type and size of the vector passed to the function
 * as an argument.
 *
 * A sorting algorithm used in the program is Bubble Sort.
 * It repeatedly steps through the vector to be sorted, compares
 * each pair of adjacent elements and swaps them if they are in
 * the wrong order.
 *
 */

void BubbleSort::sort(std::vector<int> toSort) {
	unsigned long long transitions = 0;
	clock_t start, stop;

	start = clock();
	for (unsigned long long i = 0; i < toSort.size() - 1; i++) {
		for (unsigned long long j = 0; j < toSort.size() - i - 1; j++) {
			if (toSort[j] > toSort[j + 1]) {
				std::swap(toSort[j], toSort[j + 1]);
				transitions++;
			}
		}
	}
	stop = clock();

	mTime = (double) (stop - start) / CLOCKS_PER_SEC;
	mTransitions = transitions;
}
