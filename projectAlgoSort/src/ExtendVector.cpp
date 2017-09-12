#include "ExtendVector.hpp"

void extendVector(std::vector<int>&toFill, int setNumber, unsigned long long size) {
	DataSetGenerator generator;
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
