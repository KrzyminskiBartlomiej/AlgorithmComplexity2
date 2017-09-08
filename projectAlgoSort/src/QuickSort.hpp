#ifndef QUICKSORT_HPP_
#define QUICKSORT_HPP_

#include "SortingAlgorithm.hpp"

class QuickSort: public SortingAlgorithm {
public:
	void quickSort(std::vector<int>& toSort, int low, int high, unsigned long long& transitions);
	void sort(std::vector<int> toSort);
};

#endif /* QUICKSORT_HPP_ */
