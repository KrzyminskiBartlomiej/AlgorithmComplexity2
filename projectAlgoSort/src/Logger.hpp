#ifndef LOGGER_HPP_
#define LOGGER_HPP_
#include <iostream>
#include <fstream>

class Logger {
public:
	void openFile(unsigned int typeOfSortingAlgorithm);
	void logVectorType(unsigned int typeOfVector);
	void logSortingResults(int sizeOfVector, double time, long long transitions);
	void closeFile();
	std::fstream& getFile();

protected:
	std::fstream mFile;
};

#endif /* LOGGER_HPP_ */
