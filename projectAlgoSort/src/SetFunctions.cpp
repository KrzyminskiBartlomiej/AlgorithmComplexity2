#include "SetFunctions.hpp"

int setVectorType(int n) {
	int setNumber;
	std::cout << "Select " << n + 1 << " type of set: " << std::endl;
	std::cout << "1.Sorted set." << std::endl;
	std::cout << "2.Random set." << std::endl;
	std::cout << "3.Backward sorted set." << std::endl;
	std::cout << "4.Sorted set with first random value." << std::endl;
	std::cout << "5.Backward sorted set with last random value." << std::endl;
	std::cout << "Enter number: ";
	std::cin >> setNumber;
	return setNumber;
}

unsigned long long setVectorSize() {
	unsigned long long vectorSize;
	std::cout << "Enter initial vector's size: ";
	std::cin >> vectorSize;
	return vectorSize;
}

int setVectorsNumber() {
	int vectorsNumber;
	std::cout << "Enter number of vectors you want to create: ";
	std::cin >> vectorsNumber;
	return vectorsNumber;
}

int setAlgorithmsNumber() {
	int algorithmsNumber;
	std::cout << "Enter number of algorithms you want to use: ";
	std::cin >> algorithmsNumber;
	return algorithmsNumber;
}

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

unsigned long long setInterval() {
	unsigned long long interval;
	std::cout << "Enter interval: ";
	std::cin >> interval;
	return interval;
}

unsigned long long setIterations() {
	unsigned long long iterations;
	std::cout << "Enter iterations: ";
	std::cin >> iterations;
	return iterations;
}
