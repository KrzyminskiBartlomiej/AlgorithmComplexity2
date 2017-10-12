#ifndef SORTINGALGORITHM_HPP_
#define SORTINGALGORITHM_HPP_
#include <vector>
#include <time.h>
#include <cstdlib>
#include <iostream>

class SortingAlgorithm {
public:
	virtual void sort(std::vector<int> toSort) = 0;
	virtual ~SortingAlgorithm();
	double getTime();
	unsigned long long getTransitions();

protected:
	unsigned long long mTransitions;
	double mTime;
};

#endif /* SORTINGALGORITHM_HPP_ */
