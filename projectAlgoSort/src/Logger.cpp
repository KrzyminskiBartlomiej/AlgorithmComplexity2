/**
* Name        : Logger.cpp
* Description : C++ program for implementation of Logger
*
*/

#include "Logger.hpp"
/**
* Method responsible for the conversion of a decimal
* separator in a variable time from dot to comma.
*
*/

std::string Logger::convertTime(double time){
	std::stringstream ss;
	ss<<time;
	std::string converted = ss.str();
	for(unsigned int i=0; i<converted.size(); ++i){
	     if(converted[i]=='.'){
	       converted[i]=',';
	       break;
	   }
	}
	return converted;
}

/**
* Method responsible for opening the file.
*
*/

void Logger::openFile(unsigned int typeOfAlgorithm) {
	switch (typeOfAlgorithm) {
	case 1:
		Logger::mFile[0].open("BubbleSortResults.csv", std::ios::out | std::ios::app);
		break;
	case 2:
		Logger::mFile[1].open("QuickSortResults.csv", std::ios::out | std::ios::app);
		break;
	case 3:
		Logger::mFile[2].open("InsertionSortResults.csv", std::ios::out | std::ios::app);
		break;
	case 4:
		Logger::mFile[3].open("MergeSortResults.csv", std::ios::out | std::ios::app);
		break;
	case 5:
		Logger::mFile[4].open("CountingSortResults.csv", std::ios::out | std::ios::app);
		break;
	case 6:
		Logger::mFile[5].open("HeapSortResults.csv", std::ios::out | std::ios::app);
		break;
	default:
		std::cout << "File can not be opened!" << std::endl;
		break;
	}
}

/**
* Method responsible for logging of vector type to an open file.
*
*/
void Logger::logVectorType(unsigned int typeOfVector, unsigned int typeOfAlgorithm) {
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
	mFile[typeOfAlgorithm-1]<< "----------------------------------------" << std::endl << setType << std::endl << "----------------------------------------"
	<< std::endl;
}

/**
* Method responsible for logging all sorting results to an open file.
*
*/
void Logger::logSortingResults(int sizeOfVector, double time, long long transitions, unsigned int typeOfAlgorithm) {
	mFile[typeOfAlgorithm-1] << sizeOfVector << ";" << convertTime(time) << ";" << transitions << std::endl;
}
