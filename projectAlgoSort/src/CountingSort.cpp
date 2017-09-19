//============================================================================
// Name        : CountingSort.cpp
// Description : C++ program for implementation of Counting Sort
//============================================================================
#include "CountingSort.hpp"

//The main function with one argument to do Counting Sort
void CountingSort::sort(std::vector<int> toSort) {
	unsigned long long transitions = 0; // The flag counting transitions
	clock_t start, stop; // Variables used to calculate the processor time consumed by the program

	start = clock();

	// Create a counting array to store count of individual integers
	// Initialize counting array as 0
	int countingArray[toSort.size()] = { 0 };

	// Store count of each integer from the container
	for (unsigned int i = 0; i < toSort.size(); i++) {
		countingArray[toSort[i]]++;
		transitions++;
	}

	int outputIndex = 0;

	// Modify elements in the container according to the count of individual integers in the counting array
	// Create a sorted container
	for (unsigned int i = 0; i < toSort.size(); i++) {
		while (countingArray[i]--) {
			toSort[outputIndex++] = i;
			transitions++;
		}
		transitions++;
	}
	stop = clock();

	// Convert the processor time consumed by the program to the actual processing time of a program
	mTime = (double) (stop - start) / CLOCKS_PER_SEC;
	mTransitions = transitions;
}
