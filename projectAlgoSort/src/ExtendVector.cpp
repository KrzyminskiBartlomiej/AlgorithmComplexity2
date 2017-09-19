//============================================================================
// Name        : ExtendVector.cpp
// Description : C++ program for implementation of the function that extends the container and fills it with elements
//============================================================================
#include "ExtendVector.hpp"

// The function responsible for extension of the container (vector) and filling it with integers
// It uses DataSetGenerator class and its function
void extendVector(std::vector<int>&toFill, int setNumber, unsigned long long size) {
	DataSetGenerator generator;

	// Select a vector type to extend according to an argument passed to the function
	switch (setNumber) {
	case 1:
		generator.extendSortedSet(toFill, size);
		break;
	case 2:
		generator.extendRandomSet(toFill, size);
		break;
	case 3:
		generator.extendBackwardSortedSet(toFill, size);
		break;
	case 4:
		generator.extendSortedSetWithFirstRandomValue(toFill, size);
		break;
	case 5:
		generator.extendBackwardSortedSetWithLastRandomValue(toFill, size);
		break;
	default:
		std::cout << "Vector extension failed!" << std::endl;
		break;
	}
}
