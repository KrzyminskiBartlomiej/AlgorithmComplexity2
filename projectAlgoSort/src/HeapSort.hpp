#ifndef HEAPSORT_HPP_
#define HEAPSORT_HPP_

#include "SortingAlgorithm.hpp"

class HeapSort: public SortingAlgorithm {
public:
	void heapify(std::vector<int>& toSort, int vectorSize, int i, unsigned long long& transitions);
	void heapSort(std::vector<int>& toSort, int vectorSize, unsigned long long& transitions);
	void sort(std::vector<int> toSort);
};

#endif /* HEAPSORT_HPP_ */
