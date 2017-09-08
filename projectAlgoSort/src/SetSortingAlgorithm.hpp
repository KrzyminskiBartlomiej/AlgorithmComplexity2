#ifndef SETSORTINGALGORITHM_HPP_
#define SETSORTINGALGORITHM_HPP_
#include"BubbleSort.hpp"
#include"InsertionSort.hpp"
#include"QuickSort.hpp"
#include"MergeSort.hpp"
#include"CountingSort.hpp"
#include"HeapSort.hpp"
#include"SortingAlgorithm.hpp"

//void setSortingAlgorithm(AlgoSort& toSet, int sortAlgoNumber)
SortingAlgorithm* setSortingAlgorithm(int sortAlgoNumber)
{
	SortingAlgorithm* toSet;
	switch(sortAlgoNumber){
	case 1:
		toSet = new BubbleSort();
		break;
	case 2:
		toSet = new QuickSort();
		break;
	case 3:
		toSet = new InsertionSort();
		break;
	case 4:
		toSet = new MergeSort();
		break;
	case 5:
		toSet = new CountingSort();
		break;
	case 5:
		toSet = new HeapSort();
		break;
	}
	return toSet;
}
#endif /* SETSORTINGALGORITHM_HPP_ */
