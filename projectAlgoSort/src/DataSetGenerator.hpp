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
	void createRandomSet(std::vector<int>& toFill, int n);
	void createSortedSet(std::vector<int>& toFill, int n);
	void createBackwardSortedSet(std::vector<int>& toFill, int n);
	void createSortedSetWithFirstRandomValue(std::vector<int>& toFill, int n);
	void createBackwardSortedSetWithLastRandomValue(std::vector<int>& toFill, int n);
};

#endif /* DATASETGENERATOR_HPP_ */
