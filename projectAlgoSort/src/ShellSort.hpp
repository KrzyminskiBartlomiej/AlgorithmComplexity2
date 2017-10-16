#ifndef SHELLSORT_HPP_
#define SHELLSORT_HPP_
#include "SortingAlgorithm.hpp"

class ShellSort: public SortingAlgorithm {
public:
	void sort(std::vector<int> toSort);
	unsigned int setGap(unsigned long long vectorSize);
};

#endif /* SHELLSORT_HPP_ */
