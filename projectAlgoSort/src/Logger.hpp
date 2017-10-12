#ifndef LOGGER_HPP_
#define LOGGER_HPP_
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class Logger {
public:
	void openFile(unsigned int typeOfAlgorithm);
	void logVectorType(unsigned int typeOfVector, unsigned int typeOfAlgorithm);
	void logSortingResults(int sizeOfVector, double time, unsigned long long transitions, unsigned int typeOfAlgorithm);
	void setFilesNumber(int filesNumber);
	std::string convertTime(double time);

protected:
	std::ofstream mFile[6];
};

#endif /* LOGGER_HPP_ */
