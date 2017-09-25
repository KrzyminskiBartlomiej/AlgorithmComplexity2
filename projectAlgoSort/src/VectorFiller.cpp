//============================================================================
// Name        : FillVector.cpp
// Description : C++ program for implementation of the function that fills the container with elements
//============================================================================
#include "VectorFiller.hpp"

// The function responsible for filling the container (vector) with integers
// It uses DataSetGenerator class and its function
void VectorFiller::fillVector(std::vector<int>&toFill, int setNumber) {
	DataSetGenerator generator;

	// Select a vector type according to an argument passed to the function
	switch (setNumber) {
	case 1:
		generator.createSortedSet(toFill);
		break;
	case 2:
		generator.createRandomSet(toFill);
		break;
	case 3:
		generator.createBackwardSortedSet(toFill);
		break;
	case 4:
		generator.createSortedSetWithFirstRandomValue(toFill);
		break;
	case 5:
		generator.createBackwardSortedSetWithLastRandomValue(toFill);
		break;
	default:
		std::cout << "Vector filling failed!" << std::endl;
		break;
	}
}
