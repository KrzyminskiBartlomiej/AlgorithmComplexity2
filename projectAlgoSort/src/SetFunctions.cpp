//============================================================================
// Name        : SetFunctions.cpp
// Description : C++ program for implementation of functions that can be controlled by users
//============================================================================
#include "SetFunctions.hpp"

// Function that allows to select the type of vector
int setVectorType() {
	int setNumber;
	std::cout << "Select type of set: " << std::endl;
	std::cout << "1.Sorted set." << std::endl;
	std::cout << "2.Random set." << std::endl;
	std::cout << "3.Backward sorted set." << std::endl;
	std::cout << "4.Sorted set with first random value." << std::endl;
	std::cout << "5.Backward sorted set with last random value." << std::endl;
	std::cout << "Enter number: ";
	std::cin >> setNumber;
	return setNumber;
}

// Function that allows to select the size of vector
unsigned long long setVectorSize() {
	unsigned long long vectorSize;
	std::cout << "Enter initial vector's size: ";
	std::cin >> vectorSize;
	return vectorSize;
}

// Function that allows to select the number of sorting algorithms
int setAlgorithmsNumber() {
	int algorithmsNumber;
	std::cout << "Enter number of algorithms you want to use: ";
	std::cin >> algorithmsNumber;
	return algorithmsNumber;
}

// Function that allows to select the type of sorting algorithm
int setAlgorithmType(int n) {
	int algorithmNumber;
	std::cout << "Select " << n + 1 << " algorithm: " << std::endl;
	std::cout << "1.Bubble sort." << std::endl;
	std::cout << "2.Quick sort." << std::endl;
	std::cout << "3.Insertion sort." << std::endl;
	std::cout << "4.Merge sort." << std::endl;
	std::cout << "5.Counting sort." << std::endl;
	std::cout << "6.Heap sort." << std::endl;
	std::cout << "Enter number: ";
	std::cin >> algorithmNumber;
	return algorithmNumber;
}

// Function that allows to select the interval
unsigned long long setInterval() {
	unsigned long long interval;
	std::cout << "Enter interval: ";
	std::cin >> interval;
	return interval;
}

// Function that allows to select the number of iterations
unsigned long long setIterations() {
	unsigned long long iterations;
	std::cout << "Enter iterations: ";
	std::cin >> iterations;
	return iterations;
}
