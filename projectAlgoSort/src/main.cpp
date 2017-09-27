//============================================================================
// Name        : main.cpp
// Description : C++ program for implementation of the AlgorithmComplexity program
//============================================================================
#include<iostream>
#include<utility>
#include"Logic.hpp"

int main() {
	int key = 1;
	while (key) {
		Logic logic;
		logic.logVectorTypes();
		logic.sort();
		std::cout << "Press zero to exit program. Press any other number to continue. " << std::endl;
		std::cin >> key;
	}
	return 0;
}

