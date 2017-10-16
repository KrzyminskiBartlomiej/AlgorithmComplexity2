/**
 * Name        : FunctionsSetter.cpp
 * Description : C++ program for implementation of functions that can be controlled by users
 *
 */

#include "FunctionsSetter.hpp"

/**
 * A method that allows to select the type of vector.
 *
 */

int FunctionsSetter::setVectorType(int n) {
	int setNumber;
	bool valueCorrect=false;

	while(!valueCorrect)
	{
		valueCorrect=true;
		std::cout << "Select " << n + 1 << " type of set. " << std::endl;
		std::cout << "1.Sorted set." << std::endl;
		std::cout << "2.Random set." << std::endl;
		std::cout << "3.Backward sorted set." << std::endl;
		std::cout << "4.Sorted set with first random value." << std::endl;
		std::cout << "5.Backward sorted set with last random value." << std::endl;
		std::cout << "Enter the number: ";
		std::cin >> setNumber;
		if (setNumber > 5||setNumber<1) {
			std::cout<<"Invalid number. Please enter the number within range 1-5."<<std::endl;
			valueCorrect=false;
		}
	}
	return setNumber;
}

/**
 * A method that allows to select the size of vector.
 *
 */

unsigned long long FunctionsSetter::setVectorSize() {
	unsigned long long vectorSize;
	while(true){
		std::cout << "Enter the initial vector's size: ";
		std::cin >> vectorSize;
		if(vectorSize){
			break;
		}
		else{
		std::cout<<"Vector's size must be greater than zero."<<std::endl;
		}
	}
	return vectorSize;
}

/**
 * A method that allows to select the number of sorting algorithms.
 *
 */

int FunctionsSetter::setAlgorithmsNumber() {
	int algorithmsNumber;
	while(true){
		std::cout << "Enter the number of algorithms you want to use. Entering the number greater than 7 will cause selecting all available algorithms: ";
		std::cin >> algorithmsNumber;
		if(algorithmsNumber>0){
			break;
		}
		else{
			std::cout<<"Selected number must be greater than zero."<<std::endl;
		}
	}
	return algorithmsNumber;
}

/**
 * A method that allows to select the number of vectors.
 *
 */

int FunctionsSetter::setVectorsNumber() {
	int vectorsNumber;
	while(true){
		std::cout << "Enter the number of vectors you want to use. Entering the number greater than 5 will cause selecting all available vectors:  ";
		std::cin >> vectorsNumber;
		if(vectorsNumber>0){
			break;
		}
		else{
			std::cout<<"Selected number must be greater than zero."<<std::endl;
		}
	}
	return vectorsNumber;
}

/**
 * A method that allows to select the type of sorting algorithm.
 *
 */

int FunctionsSetter::setAlgorithmType(int n) {
	int algorithmNumber;
	bool valueCorrect=false;
	while(!valueCorrect)
	{
		valueCorrect=true;
		std::cout << "Select " << n + 1 << " algorithm." << std::endl;
		std::cout << "1.Bubble sort." << std::endl;
		std::cout << "2.Quick sort." << std::endl;
		std::cout << "3.Insertion sort." << std::endl;
		std::cout << "4.Merge sort." << std::endl;
		std::cout << "5.Counting sort." << std::endl;
		std::cout << "6.Heap sort." << std::endl;
		std::cout << "7.Shell sort." << std::endl;
		std::cout << "Enter the number: ";
		std::cin >> algorithmNumber;
		if (algorithmNumber > 7||algorithmNumber<1) {
			std::cout<<"Invalid number. Please enter the number within range 1-7."<<std::endl;
			valueCorrect=false;
		}
	}
	return algorithmNumber;
}

/**
 * A method that allows to select the interval.
 *
 */

unsigned long long FunctionsSetter::setInterval() {
	unsigned long long interval;
	std::cout << "Enter the interval: ";
	std::cin >> interval;
	return interval;
}

/**
 * A method that allows to select the number of iterations.
 *
 */

unsigned long long FunctionsSetter::setIterations() {
	unsigned long long iterations;
	std::cout << "Enter the number of iterations: ";
	std::cin >> iterations;
	return iterations;
}
