//============================================================================
// Name        : SetSortingAlgorithm.cpp
// Description : C++ program for implementation of the function that returns a pointer to SortingAlgorithm type
//============================================================================
#include "SetSortingAlgorithm.hpp"

// Function responsible for creating a pointer to SortingAlgorithm type
SortingAlgorithm* setSortingAlgorithm(int sortAlgoNumber) {
	SortingAlgorithm* toSet;
	switch (sortAlgoNumber) {
	case 1:
		toSet = new BubbleSort();
		break;
	case 2:
		toSet = new QuickSort();
		break;
	case 3:
		toSet = new InsertionSort();
		break;
	case 4:
		toSet = new MergeSort();
		break;
	case 5:
		toSet = new CountingSort();
		break;
	case 6:
		toSet = new HeapSort();
		break;
	default:
		std::cout << "The sorting algorithm setting failed!" << std::endl;
		break;
	}
	return toSet;
}
