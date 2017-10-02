//============================================================================
// Name        : Logger.cpp
// Description : C++ program for implementation of Logger
//============================================================================
#include "Logger.hpp"

// The function responsible for opening/creating the file
void Logger::openFile(unsigned int typeOfSortingAlgorithm) {

	// Select a file according to an argument passed to the function
	switch (typeOfSortingAlgorithm) {
	case 1:
		Logger::mFile.open("BubbleSortResults.csv", std::ios::out | std::ios::app);
		break;
	case 2:
		Logger::mFile.open("QuickSortResults.csv", std::ios::out | std::ios::app);
		break;
	case 3:
		Logger::mFile.open("InsertionSortResults.csv", std::ios::out | std::ios::app);
		break;
	case 4:
		Logger::mFile.open("MergeSortResults.csv", std::ios::out | std::ios::app);
		break;
	case 5:
		Logger::mFile.open("CountingSortResults.csv", std::ios::out | std::ios::app);
		break;
	case 6:
		Logger::mFile.open("HeapSortResults.csv", std::ios::out | std::ios::app);
		break;
	default:
		std::cout << "File can not be opened!" << std::endl;
		break;
	}
}

// The function responsible for logging of vector type to an open file
void Logger::logVectorType(unsigned int typeOfVector) {
	std::string setType;
	switch (typeOfVector) {
	case 1:
		setType = "Sorted set";
		break;
	case 2:
		setType = "Random set";
		break;
	case 3:
		setType = "Backward sorted set";
		break;
	case 4:
		setType = "Sorted set with first random value";
		break;
	case 5:
		setType = "Backward sorted set with last random value";
		break;
	default:
		std::cout << "Converting of sorting algorithm from integer to string failed" << std::endl;
		break;
	}
	mFile << "----------------------------------------" << std::endl << setType << std::endl << "----------------------------------------"
			<< std::endl;
}

// The function responsible for logging all sorting results to an open file
void Logger::logSortingResults(int sizeOfVector, double time, long long transitions) {
	mFile << sizeOfVector << ";" << time << ";" << transitions << std::endl;
}

// The function responsible for closing an open file
void Logger::closeFile() {
	mFile.close();
}
