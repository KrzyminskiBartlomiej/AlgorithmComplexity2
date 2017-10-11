/**
 * Name        : DataSetGenerator.cpp
 * Description : C++ program for implementation of DataSetGenerator
 *
 */

#include "DataSetGenerator.hpp"

/**
 * A method that is responsible for creating a sorted set.
 *
 */

void DataSetGenerator::createSortedSet(std::vector<int>&toFill) {
	unsigned int valueToAdd = 0;
	for (std::vector<int>::iterator it = toFill.begin(); it != toFill.end(); ++it) {
		*it = valueToAdd++;
	}
}

/**
 * A method that is responsible for extension of sorted set.
 *
 */

void DataSetGenerator::extendSortedSet(std::vector<int>&toFill, unsigned long long toAdd) {
	int lastElementIndex = toFill.size();
	int valueToAdd = toFill.back() + 1;
	toFill.resize(toFill.size() + toAdd);
	for (unsigned int i = 0; i < toAdd; ++i) {
		toFill[lastElementIndex++] = valueToAdd++;
	}
}

/**
 * A method that is responsible for creating a random set.
 *
 */

void DataSetGenerator::createRandomSet(std::vector<int>& toFill) {
	unsigned long long vectorSize = toFill.size();
	for (std::vector<int>::iterator it = toFill.begin(); it != toFill.end(); ++it) {
		*it = std::rand() % vectorSize;
	}
}

/**
 * A method that is responsible for extension of random set.
 *
 */

void DataSetGenerator::extendRandomSet(std::vector<int>& toFill, unsigned long long toAdd) {
	int lastElementIndex = toFill.size();
	toFill.resize(toFill.size() + toAdd);
	for (unsigned int i = 0; i < toAdd; ++i) {
		toFill[lastElementIndex++] = std::rand() % toFill.size();
	}
}

/**
 * A method that is responsible for creating a backward sorted set.
 *
 */

void DataSetGenerator::createBackwardSortedSet(std::vector<int>& toFill) {
	unsigned int valueToAdd = toFill.size() - 1;
	for (std::vector<int>::iterator it = toFill.begin(); it != toFill.end(); ++it) {
		*it = valueToAdd--;
	}
}

/**
 * A method that is responsible for extension of backward sorted set.
 *
 */

void DataSetGenerator::extendBackwardSortedSet(std::vector<int>& toFill, unsigned long long toAdd) {
	unsigned int valueToAdd = toFill.front();
	for (unsigned int i = 0; i < toAdd; ++i) {
		toFill.insert(toFill.begin(), ++valueToAdd);
	}
}

/**
 * A method that is responsible for creating a sorted set with first random value.
 *
 */

void DataSetGenerator::createSortedSetWithFirstRandomValue(std::vector<int>& toFill) {
	toFill[0] = std::rand() % toFill.size();
	unsigned long valueToAdd = 1;
	for (std::vector<int>::iterator it = toFill.begin() + 1; it != toFill.end(); ++it) {
		*it = valueToAdd++;
	}
}

/**
 * A method that is responsible for extension of sorted set with first random value.
 *
 */

void DataSetGenerator::extendSortedSetWithFirstRandomValue(std::vector<int>& toFill, unsigned long long toAdd) {
	extendSortedSet(toFill, toAdd);
	toFill[0] = std::rand() % toFill.size();
}

/**
 * A method that is responsible for creating a backward sorted set with last random value.
 *
 */

void DataSetGenerator::createBackwardSortedSetWithLastRandomValue(std::vector<int>& toFill) {
	createBackwardSortedSet(toFill);
	toFill[toFill.size() - 1] = std::rand() % toFill.size();
}

/**
 * A method that is responsible for extension of backward sorted set with last random value.
 *
 */

void DataSetGenerator::extendBackwardSortedSetWithLastRandomValue(std::vector<int>& toFill, unsigned long long toAdd) {
	unsigned int valueToAdd = toFill.front();
	for (unsigned int i = 0; i < toAdd; ++i) {
		toFill.insert(toFill.begin(), ++valueToAdd);
	}
	toFill[toFill.size() - 1] = std::rand() % toFill.size();
}
