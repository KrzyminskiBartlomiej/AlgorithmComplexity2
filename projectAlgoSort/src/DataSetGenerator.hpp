#ifndef DATASETGENERATOR_HPP_
#define DATASETGENERATOR_HPP_
#include <vector>
#include <ctime>
#include <cstdlib>

class DataSetGenerator {
public:
	void createSortedSet(std::vector<int>& toFill, unsigned int sizeOfVector);
	void createRandomSet(std::vector<int>& toFill, unsigned int sizeOfVector);
	void createBackwardSortedSet(std::vector<int>& toFill, unsigned int sizeOfVector);
	void createSortedSetWithFirstRandomValue(std::vector<int>& toFill, unsigned int sizeOfVector);
	void createBackwardSortedSetWithLastRandomValue(std::vector<int>& toFill, unsigned int sizeOfVector);

	void extendSortedSet(std::vector<int>& toExtend, unsigned long long toAdd);
	void extendRandomSet(std::vector<int>& toExtend, unsigned long long toAdd);
	void extendBackwardSortedSet(std::vector<int>& toExtend, unsigned long long toAdd);
	void extendSortedSetWithFirstRandomValue(std::vector<int>& toExtend, unsigned long long toAdd);
	void extendBackwardSortedSetWithLastRandomValue(std::vector<int>& toExtend, unsigned long long toAdd);
};

#endif /* DATASETGENERATOR_HPP_ */
