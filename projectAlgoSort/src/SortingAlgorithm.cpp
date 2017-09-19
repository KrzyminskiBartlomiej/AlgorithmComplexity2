//============================================================================
// Name        : SortingAlgorithm.cpp
// Description : C++ program for implementation of an abstract SortingAlgorithm class
//============================================================================
#include "SortingAlgorithm.hpp"

SortingAlgorithm::~SortingAlgorithm() {
}

// Accessor function for a mTime member of SortingAlgorithm class
double SortingAlgorithm::getTime() {
	return mTime;
}

// Accessor function for a mTransitions member of SortingAlgorithm class
unsigned long long SortingAlgorithm::getTransitions() {
	return mTransitions;
}
