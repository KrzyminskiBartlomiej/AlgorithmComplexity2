#include "FillVector.hpp"

void fillVector(std::vector<int>&toFill, int setNumber, unsigned long long size) {
	DataSetGenerator generator;
	switch(setNumber){
	case 1:
		generator.createSortedSet(toFill,size);
		break;
	case 2:
		generator.createRandomSet(toFill,size);
		break;
	case 3:
		generator.createBackwardSortedSet(toFill,size);
		break;
	case 4:
		generator.createSortedSetWithFirstRandomValue(toFill,size);
		break;
	case 5:
		generator.createBackwardSortedSetWithLastRandomValue(toFill,size);
		break;
	default:
		std::cout << "Vector filling failed!" << std::endl;
		break;
	}
}
