#ifndef LOGGER_HPP_
#define LOGGER_HPP_
#include <iostream>
#include <fstream>
#include <sstream>

class Logger {
public:
	void openFile(unsigned int typeOfSortingAlgorithm);
	void logVectorType(unsigned int typeOfVector);
	void logSortingResults(int sizeOfVector, double time, long long transitions);
	void closeFile();
	std::string convertTime(double time);

protected:
	std::fstream mFile;
};

#endif /* LOGGER_HPP_ */
