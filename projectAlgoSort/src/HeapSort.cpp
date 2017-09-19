//============================================================================
// Name        : HeapSort.cpp
// Description : C++ program for implementation of Heap Sort
//============================================================================
#include "HeapSort.hpp"

// The function to heapify a subtree rooted with node i which is an index in the vector.
void HeapSort::heapify(std::vector<int>& toSort, int vectorSize, int i, unsigned long long& transitions) {
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // l = left
	int r = 2 * i + 2; // r = right

	// If left child is larger than root
	if (l < vectorSize && toSort[l] > toSort[largest]) {
		largest = l;
		transitions++;
	}

	// If right child is larger than root
	if (r < vectorSize && toSort[r] > toSort[largest]) {
		largest = r;
		transitions++;
	}

	// If largest is not a root
	if (largest != i) {
		std::swap(toSort[i], toSort[largest]);
		transitions++;

		// Recursively heapify the affected subtree
		heapify(toSort, vectorSize, largest, transitions);
	}
}

// The function to do heap sort
void HeapSort::heapSort(std::vector<int>& toSort, int vectorSize, unsigned long long& transitions) {

	// Build heap (rearrange vector)
	for (int i = vectorSize / 2 - 1; i >= 0; i--) {
		heapify(toSort, vectorSize, i, transitions);
	}

	// One by one extract an element from heap
	for (int i = vectorSize - 1; i >= 0; i--) {

		// Move current root to end
		std::swap(toSort[0], toSort[i]);
		transitions++;

		// Heapify on the reduced heap
		heapify(toSort, i, 0, transitions);
	}
}

// The main function with one argument to do sorting
void HeapSort::sort(std::vector<int> toSort) {
	int vectorSize = toSort.size();
	unsigned long long transitions = 0; // The flag counting transitions
	clock_t start, stop; // Variables used to calculate the processor time consumed by the program

	start = clock();
	heapSort(toSort, vectorSize, transitions);
	stop = clock();

	// Convert the processor time consumed by the program to the actual processing time of a program
	mTime = (double) (stop - start) / CLOCKS_PER_SEC;
	mTransitions = transitions;
}
