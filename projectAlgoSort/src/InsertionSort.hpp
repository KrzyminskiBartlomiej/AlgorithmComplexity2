#ifndef INSERTIONSORT_HPP_
#define INSERTIONSORT_HPP_
#include "SortingAlgorithm.hpp"

class InsertionSort: public SortingAlgorithm {
public:
	void sort(std::vector<int> toSort);
};

#endif /* INSERTIONSORT_HPP_ */
