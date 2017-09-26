#ifndef LOGIC_HPP_
#define LOGIC_HPP_

#include<iostream>
#include"DataSetGenerator.hpp"
#include"BubbleSort.hpp"
#include"InsertionSort.hpp"
#include"QuickSort.hpp"
#include"MergeSort.hpp"
#include"CountingSort.hpp"
#include"HeapSort.hpp"
#include"Logger.hpp"
#include "FunctionsSetter.hpp"
#include "SortingAlgorithmSetter.hpp"
#include "VectorExtender.hpp"
#include "VectorFiller.hpp"

class Logic
{
public:

   Logic();
   void setAlgorithmsNumber();
   void setselectedAlgorithms();
   void setVectorType();
   void setInterval();
   void setIterations();
   void setInitialVectorSize();
   void fillVector();
   void extendVector();
   void logVectorTypes();
   void sort();
   void logSortingResults(int algorithmIndex, int iteration);
   ~Logic();

private:
	unsigned long long mVectorSize, mInterval, mIterations;
	unsigned int* mSelectedAlgorithms;
	int mAlgorithmsNumber, mSelectedVector;
	SortingAlgorithm* mSortingAlgorithm;
	Logger mLogger;
	FunctionsSetter mSetter;
	std::vector<int>mVectorToSort;
	VectorFiller mFiller;
	VectorExtender mExtender;
	SortingAlgorithmSetter mAlgorithmSetter;
};

#endif /* LOGIC_HPP_ */
