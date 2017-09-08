#ifndef COUNTINGSORT_HPP_
#define COUNTINGSORT_HPP_

#include "SortingAlgorithm.hpp"

class CountingSort: public SortingAlgorithm {
public:
	void sort(std::vector<int> toSort);
};

#endif /* COUNTINGSORT_HPP_ */
