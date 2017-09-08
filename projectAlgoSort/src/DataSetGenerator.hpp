#ifndef DATASETGENERATOR_HPP_
#define DATASETGENERATOR_HPP_
#include<vector>
#include<algorithm>
#include <random>
#include <chrono>
#include <cstdlib>

class DataSetGenerator
{
public:
	DataSetGenerator();
	void createRandomSet(std::vector<int>& toFill, unsigned long long vectorSize);
	void createSortedSet(std::vector<int>&toFill, unsigned long long vectorSize);
	void createBackwardSortedSet(std::vector<int>& toFill, unsigned long long vectorSize);
	void createSortedSetWithFirstRandomValue(std::vector<int>& toFill, unsigned long long vectorSize);
	void createBackwardSortedSetWithLastRandomValue(std::vector<int>& toFill, unsigned long long vectorSize);

	void extendRandomSet(std::vector<int>& toFill, unsigned long long toAdd);
	void extendSortedSet(std::vector<int>&toFill, unsigned long long toAdd);
	void extendBackwardSortedSet(std::vector<int>& toFill, unsigned long long toAdd);
	void extendSortedSetWithFirstRandomValue(std::vector<int>& toFill, unsigned long long toAdd);
	void extendBackwardSortedSetWithLastRandomValue(std::vector<int>& toFill, unsigned long long toAdd);
};



#endif /* DATASETGENERATOR_HPP_ */
