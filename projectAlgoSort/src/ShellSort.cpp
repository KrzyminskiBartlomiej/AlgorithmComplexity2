/**
 * Name        : ShellSort.cpp
 * Description : C++ program for implementation of Shell Sort
 *
 */


#include"ShellSort.hpp"

/**
 *A method that is responsible for setting
 *initial size of gap variable based on vector's size.
 */

unsigned int ShellSort::setGap(unsigned long long sizeOfVector){
    unsigned long long gap = 1;
    while(gap<sizeOfVector){
        gap = gap*3+1;
    }
    gap/=9;
    return gap;
}

/**
 * A method that is responsible for the calculation of actual
 * processing time and transitions number of the sorting program
 * according to type and size of the vector passed to the function
 * as an argument.
 *
 * A sorting algorithm used in the program is Shell Sort.
 * It is a generalization of sorting by insertion (insertion sort).
 * The method starts by sorting pairs of elements far apart from each other using variable gap
 * that defines distance between elements that are being compared.
 * The gap gets divided by three it every iteration until it equal one.
 */

void ShellSort::sort(std::vector<int> toSort) {
	unsigned long long sizeOfVector = toSort.size();
	clock_t start, stop;
	start = clock();
	int i, x, j;
	unsigned long long gap, transitions = 0;
	gap=setGap(sizeOfVector);

    while(gap){
        for(j = sizeOfVector - gap - 1; j >= 0; j--){
                x = toSort[j];
                i = j + gap;
            while((i < sizeOfVector) && (x > toSort[i])){
                toSort[i - gap] = toSort[i];
                i += gap;
                transitions++;
            }
            toSort[i - gap] = x;
            transitions++;
        }
            gap /= 3;
    }
	stop = clock();

	mTime = (double) (stop - start) / CLOCKS_PER_SEC;
	mTransitions = transitions;
}
