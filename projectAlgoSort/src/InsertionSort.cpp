//============================================================================
// Name        : InsertionSort.cpp
// Description : C++ program for implementation of Insertion Sort
//============================================================================
#include "InsertionSort.hpp"

// The main function with one argument to do Insertion Sort
void InsertionSort::sort(std::vector<int> toSort) {
	int sizeOfVector = toSort.size();
	unsigned long long transitions = 0; // The flag counting transitions
	clock_t start, stop; // Variables used to calculate the processor time consumed by the program

	start = clock();

	// Create two temporary variables
	int tmp, tmpToCompare;
	for (int i = toSort.size() - 2; i >= 0; i--) {
		tmp = toSort[i];
		tmpToCompare = i + 1;

		// Move elements of the container that are smaller than temporary variable tmp to one position back of their current position
		while ((tmpToCompare < sizeOfVector) && (tmp > toSort[tmpToCompare])) {
			toSort[tmpToCompare - 1] = toSort[tmpToCompare];
			tmpToCompare++;
			transitions++;
		}
		toSort[tmpToCompare - 1] = tmp;
	}
	stop = clock();

	// Convert the processor time consumed by the program to the actual processing time of a program
	mTime = (double) (stop - start) / CLOCKS_PER_SEC;
	mTransitions = transitions;
}
