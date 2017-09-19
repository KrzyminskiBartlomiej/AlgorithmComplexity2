//============================================================================
// Name        : DataSetGenerator.cpp
// Description : C++ program for implementation of DataSetGenerator
//============================================================================
#include "DataSetGenerator.hpp"

// Function responsible for creating a sorted set
void DataSetGenerator::createSortedSet(std::vector<int>& toFill, unsigned int sizeOfVector) {
	for (unsigned int i = 0; i < sizeOfVector; i++) {
		toFill.push_back(i);
	}
}

// Function responsible for creating a random set
void DataSetGenerator::createRandomSet(std::vector<int>& toFill, unsigned int sizeOfVector) {
	for (unsigned int i = 0; i < sizeOfVector; i++) {
		toFill.push_back(rand() % sizeOfVector);
	}
}

// Function responsible for creating a backward sorted set
void DataSetGenerator::createBackwardSortedSet(std::vector<int>& toFill, unsigned int sizeOfVector) {
	for (int i = sizeOfVector - 1; i >= 0; i--) {
		toFill.push_back(i);
	}
}

// Function responsible for creating a sorted set with first random value
void DataSetGenerator::createSortedSetWithFirstRandomValue(std::vector<int>& toFill, unsigned int sizeOfVector) {
	toFill.push_back(rand() % sizeOfVector);
	for (unsigned int i = 1; i < sizeOfVector; i++) {
		toFill.push_back(i);
	}
}

// Function responsible for creating a backward sorted set with last random value
void DataSetGenerator::createBackwardSortedSetWithLastRandomValue(std::vector<int>& toFill, unsigned int sizeOfVector) {
	for (int i = sizeOfVector - 1; i > 0; i--) {
		toFill.push_back(i);
	}
	toFill.push_back(rand() % sizeOfVector);
}

// Function responsible for extension of sorted set
void DataSetGenerator::extendSortedSet(std::vector<int>& toExtend, unsigned long long toAdd) {
	for (unsigned int i = toExtend.size(), j = 0; j < toAdd; i++, j++) {
		toExtend.push_back(i);
	}
}

// Function responsible for extension of random set
void DataSetGenerator::extendRandomSet(std::vector<int>& toExtend, unsigned long long toAdd) {
	for (unsigned int i = 0; i < toAdd; i++) {
		toExtend.push_back(rand() % toExtend.size());
	}
}

// Function responsible for extension of backward sorted set
void DataSetGenerator::extendBackwardSortedSet(std::vector<int>& toExtend, unsigned long long toAdd) {
	for (unsigned int j = 0, i = toExtend.size(); j < toAdd; j++, i++) {
		toExtend.insert(toExtend.begin(), i);
	}
}

// Function responsible for extension of sorted set with first random value
void DataSetGenerator::extendSortedSetWithFirstRandomValue(std::vector<int>& toExtend, unsigned long long toAdd) {
	for (unsigned int i = toExtend.size(), j = 0; j < toAdd; i++, j++) {
		toExtend.push_back(i);
	}
}

// Function responsible for extension of backward sorted set with last random value
void DataSetGenerator::extendBackwardSortedSetWithLastRandomValue(std::vector<int>& toExtend, unsigned long long toAdd) {
	for (unsigned int j = 0, i = toExtend.size(); j < toAdd; j++, i++) {
		toExtend.insert(toExtend.begin(), i);
	}
}
