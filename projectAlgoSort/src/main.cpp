//============================================================================
// Name        : main.cpp
// Description : C++ program for implementation of the AlgorithmComplexity program
//============================================================================
#include<iostream>
#include<utility>
#include"Logic.hpp"

// The main function of the program
int main() {
	int key = 1;
	while (key) {

		// Call logic function responsible for whole logic of the program
		logic();
		std::cout << "Press zero to exit program. Press any other number to continue. " << std::endl;
		std::cin >> key;
	}
	return 0;
}

