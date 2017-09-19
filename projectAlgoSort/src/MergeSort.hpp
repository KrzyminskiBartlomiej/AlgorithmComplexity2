#ifndef MERGESORT_HPP_
#define MERGESORT_HPP_
#include "SortingAlgorithm.hpp"

class MergeSort: public SortingAlgorithm {
public:
	void merge(std::vector<int> &toMerge, int leftIndexOfSet, int mediumIndexOfSet, int rightIndexOfSet, unsigned long long& transitions);
	void mergeSort(std::vector<int>& toSort, int leftIndexOfSet, int rightIndexOfSet, unsigned long long &transitions);
	void sort(std::vector<int> toSort);
};

#endif /* MERGESORT_HPP_ */
