#ifndef SORTINGALGORITHMSETTER_HPP_
#define SORTINGALGORITHMSETTER_HPP_
#include"BubbleSort.hpp"
#include"InsertionSort.hpp"
#include"QuickSort.hpp"
#include"MergeSort.hpp"
#include"CountingSort.hpp"
#include"HeapSort.hpp"
#include"SortingAlgorithm.hpp"
#include <iostream>

class SortingAlgorithmSetter {
public:
	SortingAlgorithm* setSortingAlgorithm(int sortAlgoNumber);
};


#endif /* SORTINGALGORITHMSETTER_HPP_ */
