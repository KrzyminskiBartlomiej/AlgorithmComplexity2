//============================================================================
// Name        : BubbleSort.cpp
// Description : C++ program for implementation of Bubble Sort
//============================================================================
#include "BubbleSort.hpp"

// The main function with one argument to do Bubble Sort
void BubbleSort::sort(std::vector<int> toSort) {
	unsigned long long transitions = 0; // The flag counting transitions
	clock_t start, stop; // Variables used to calculate the processor time consumed by the program

	start = clock();
	for (unsigned long long i = 0; i < toSort.size() - 1; i++) {

		// One by one compare the adjacent elements
		// Last i elements are already in place
		for (unsigned long long j = 0; j < toSort.size() - i - 1; j++) {

			// If an element is larger than next one
			if (toSort[j] > toSort[j + 1]) {
				std::swap(toSort[j], toSort[j + 1]);
				transitions++;
			}
		}
	}
	stop = clock();

	// Convert the processor time consumed by the program to the actual processing time of a program
	mTime = (double) (stop - start) / CLOCKS_PER_SEC;
	mTransitions = transitions;
}
