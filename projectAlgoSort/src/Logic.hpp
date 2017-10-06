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
#include"FunctionsSetter.hpp"
#include"SortingAlgorithmSetter.hpp"

class Logic
{
public:

   Logic();
   void setAlgorithmsNumber();
   void setSelectedAlgorithms();
   void setVectorsNumber();
   void setSelectedVectors();
   void setInterval();
   void setIterations();
   void setInitialVectorSize();
   void fillVector(int n);
   void extendVector(int n);
   void logVectorTypes(int n);
   void sort();
   void logSortingToFile(int algorithmIndex, int iteration);
   void openFiles();
   ~Logic();

private:
	unsigned long long mVectorSize, mInterval, mIterations;
	unsigned int* mSelectedAlgorithms;
	unsigned int* mSelectedVectors;
	int mAlgorithmsNumber, mVectorsNumber;
	SortingAlgorithm* mSortingAlgorithm;
	Logger mLogger;
	FunctionsSetter mSetter;
	std::vector<int>mVectorToSort;
	SortingAlgorithmSetter mAlgorithmSetter;
	DataSetGenerator mGenerator;
};

#endif /* LOGIC_HPP_ */
