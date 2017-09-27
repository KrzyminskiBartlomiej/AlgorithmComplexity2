#ifndef DATASETGENERATOR_HPP_
#define DATASETGENERATOR_HPP_
#include <vector>
#include <ctime>
#include <cstdlib>

class DataSetGenerator {
public:
	void createSortedSet(std::vector<int>& toFill);
	void createRandomSet(std::vector<int>& toFill);
	void createBackwardSortedSet(std::vector<int>& toFill);
	void createSortedSetWithFirstRandomValue(std::vector<int>& toFill);
	void createBackwardSortedSetWithLastRandomValue(std::vector<int>& toFill);

	void extendSortedSet(std::vector<int>& toExtend, unsigned long long toAdd);
	void extendRandomSet(std::vector<int>& toExtend, unsigned long long toAdd);
	void extendBackwardSortedSet(std::vector<int>& toExtend, unsigned long long toAdd);
	void extendSortedSetWithFirstRandomValue(std::vector<int>& toExtend, unsigned long long toAdd);
	void extendBackwardSortedSetWithLastRandomValue(std::vector<int>& toExtend, unsigned long long toAdd);
};

#endif /* DATASETGENERATOR_HPP_ */
