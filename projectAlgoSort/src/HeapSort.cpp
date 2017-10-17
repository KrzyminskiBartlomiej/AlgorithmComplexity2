/**
 * Name        : HeapSort.cpp
 * Description : C++ program for implementation of Heap Sort
 *
 */

#include "HeapSort.hpp"

/**
 *  A method that is responsible for heapifying of a subtree rooted
 *  at node i which is an index in the vector passed to the function
 *  as an argument.
 *
 */

void HeapSort::heapify(std::vector<int>& toSort, int vectorSize, int i, unsigned long long& transitions) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < vectorSize && toSort[left] > toSort[largest]) {
		largest = left;
	}

	if (right < vectorSize && toSort[right] > toSort[largest]) {
		largest = right;
	}

	if (largest != i) {
		std::swap(toSort[i], toSort[largest]);
		transitions++;

		heapify(toSort, vectorSize, largest, transitions);
	}
}

/**
 * A method that is responsible for sorting (Heap Sort) of elements in the
 * vector passed to the function as an argument. First, it builds a
 * heap - rearranges the vector - using the heapify function, then
 * extracts all elements from the created heap creating a sorted
 * set.
 *
 */

void HeapSort::heapSort(std::vector<int>& toSort, int vectorSize, unsigned long long& transitions) {
	for (int i = vectorSize / 2 - 1; i >= 0; i--) {
		heapify(toSort, vectorSize, i, transitions);
	}
	for (int i = vectorSize - 1; i >= 0; i--) {
		std::swap(toSort[0], toSort[i]);
		transitions++;
		heapify(toSort, i, 0, transitions);
	}
}

/**
 * A method that is responsible for the calculation of actual
 * processing time and transitions number of the sorting program
 * according to type and size of the vector passed to the function
 * as an argument.
 *
 * A sorting algorithm used in the program is Heap Sort.
 *
 */

void HeapSort::sort(std::vector<int> toSort) {
	int vectorSize = toSort.size();
	unsigned long long transitions = 0;
	clock_t start, stop;

	start = clock();
	heapSort(toSort, vectorSize, transitions);
	stop = clock();

	mTime = (double) (stop - start) / CLOCKS_PER_SEC;
	mTransitions = transitions;
}
