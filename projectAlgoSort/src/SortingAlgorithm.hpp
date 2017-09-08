#ifndef SORTINGALGORITHM_HPP_
#define SORTINGALGORITHM_HPP_
#include <vector>
#include <time.h>
#include <cstdlib>

class SortingAlgorithm {
public:
	virtual void sort(std::vector<int> toSort) = 0;
	virtual ~SortingAlgorithm();
	double getTime();
	unsigned long long getTransitions();

protected:
	int mTransitions;
	double mTime;
};

#endif /* SORTINGALGORITHM_HPP_ */
