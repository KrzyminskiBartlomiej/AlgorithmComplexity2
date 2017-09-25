//============================================================================
// Name        : Logic.cpp
// Description : C++ program for implementation of program logic
//============================================================================
#include "Logic.hpp"

// The main function responsible for whole logic of the program
// It calls function that creates specified data sets and implements different sorting algorithms
void Logic::logic() {
	srand(time(NULL));
	unsigned long long vectorSize, interval, iterations;

	// Create a pointer to SortingAlgorithm type
	SortingAlgorithm* sortingAlgorithm;

	// Create an object of Logger class
	Logger logger;

	// Create an object of FunctionsSetter class
	FunctionsSetter setter;

	// Select the number of sorting algorithms
	int algorithmsNumber;
	algorithmsNumber = setter.setAlgorithmsNumber();

	// Create an array to store types of selected sorting algorithms
	unsigned int* selectedAlgorithms;
	selectedAlgorithms = new unsigned int[algorithmsNumber];

	// Add types of sorting algorithms to created array
	if (algorithmsNumber < 6) {
		for (int i = 0; i < algorithmsNumber; ++i) {
			selectedAlgorithms[i] = setter.setAlgorithmType(i);
		}
	} else {
		algorithmsNumber = 6;
		for (int i = 0; i < algorithmsNumber; ++i) {
			selectedAlgorithms[i] = i + 1;
		}
	}

	// Select the type of vector to be sorted
	int selectedVector = setter.setVectorType();

	//select the size of vector
	vectorSize = setter.setVectorSize();

	// Select the interval
	interval = setter.setInterval();

	// Select the number of iterations
	iterations = setter.setIterations();

	// Create an empty vector
	std::vector<int> vectorToSort(0);

	// Create an object of VectorFiller class
	VectorFiller filler;

	// Fill the created vector with elements according to arguments passed to the function
	filler.fillVector(vectorToSort, selectedVector, vectorSize);

	// For all selected sorting algorithms, create/open files gathering results of sorting, log type of selected vector and close files
	for (int i = 0; i < algorithmsNumber; i++) {
		logger.openFile(selectedAlgorithms[i]);
		logger.logVectorType(selectedVector);
		logger.closeFile();
	}

	// Create an object of VectorExtender class
	VectorExtender extender;

	// Create an object of SortingAlgorithmSetter class
	SortingAlgorithmSetter algorithmSetter;

	// Extend selected vector as many times as indicated by iterations
	for (unsigned int i = 0; i <= iterations; i++) {
		if (i) {
			extender.extendVector(vectorToSort, selectedVector, interval);
		}

		// Sort filled vector using all selected sorting algorithms, open created files, log all desired results and close files
		for (int j = 0; j < algorithmsNumber; j++) {
			sortingAlgorithm = algorithmSetter.setSortingAlgorithm(selectedAlgorithms[j]);
			sortingAlgorithm->sort(vectorToSort);
			logger.openFile(selectedAlgorithms[j]);
			logger.logSortingResults(vectorSize + (i * interval), sortingAlgorithm->getTime(), sortingAlgorithm->getTransitions());
			logger.closeFile();
		}
	}

	// Delete dynamically allocated variables/arrays
	delete sortingAlgorithm;
	delete[] selectedAlgorithms;
}
