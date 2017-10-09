/**
* Name        : Logic.cpp
* Description : C++ program for implementation of Bubble Sort
*
*/
#include "Logic.hpp"

Logic::Logic(){
	setAlgorithmsNumber();
	setSelectedAlgorithms();
	setVectorsNumber();
	setSelectedVectors();
	setInitialVectorSize();
	setInterval();
	setIterations();
	openFiles();
}

/**
* Method responsible for setting the number of sorting
* algorithms used in the program.
*
*/
void Logic::setAlgorithmsNumber(){
	mAlgorithmsNumber = mSetter.setAlgorithmsNumber();
}
/**
* Method responsible for selecting of sorting algorithms
* used in the program and validating user's input.
*
*/
void Logic::setSelectedAlgorithms(){
	mSelectedAlgorithms = new unsigned int[mAlgorithmsNumber];
	int alreadySelectedAlgorithms=0;
	bool newAlgorithm;
	if (mAlgorithmsNumber < 6) {
		for (int i = 0; i < mAlgorithmsNumber; ++i){
			newAlgorithm = true;
			mSelectedAlgorithms[i] = mSetter.setAlgorithmType(i);
			for(int k = 0; k<alreadySelectedAlgorithms; ++k){
				if(mSelectedAlgorithms[i]==mSelectedAlgorithms[k]){
					std::cout<<"Algorithm already selected. Please select another algorithm"<<std::endl;
					--i;
					newAlgorithm = false;
					break;
				}
			}
			if(newAlgorithm){
			++alreadySelectedAlgorithms;
			}
		}
	} else {
		mAlgorithmsNumber = 6;
		for (int i = 0; i < mAlgorithmsNumber; ++i){
			mSelectedAlgorithms[i] = i + 1;
		}
	}
}

/**
* Method responsible for setting the number of vectors
* used in the program.
*
*/
void  Logic::setVectorsNumber(){
	mVectorsNumber = mSetter.setVectorsNumber();
}
/**
* Method responsible for selecting of vectors used in
* the program and validating user's input.
*
*/
void  Logic::setSelectedVectors(){
	mSelectedVectors = new unsigned int[mVectorsNumber];
	int alreadySelectedVectors=0;
	bool newVector;
	if (mVectorsNumber < 5) {
		for (int i = 0; i < mVectorsNumber; ++i){
			mSelectedVectors[i] = mSetter.setVectorType(i);
			newVector= true;
			for(int k = 0; k<alreadySelectedVectors; ++k){
				if(mSelectedVectors[i]==mSelectedVectors[k]){
					std::cout<<"Vector already selected. Please select another vector"<<std::endl;
					--i;
					newVector = false;
					break;
				}
			}
				if(newVector){
				++alreadySelectedVectors;
				}
		}
	} else {
		mVectorsNumber = 5;
		for (int i = 0; i < mVectorsNumber; ++i){
			mSelectedVectors[i] = i + 1;
		}
	}
}
/**
* Method responsible for setting the interval used to increase vector.
*
*/
void Logic::setInterval(){
	mInterval = mSetter.setInterval();
}
/**
* Method responsible for setting the number of
* iterations in which vector is increased.
*
*/
void Logic::setIterations(){
	mIterations = mSetter.setIterations();
}

/**
* Method responsible for setting the initial size of the
* vector.
*
*/
void Logic::setInitialVectorSize(){
	mVectorSize = mSetter.setVectorSize();
	mVectorToSort.resize(mVectorSize);
}
/**
* Method for filling the vector with integers.
*
*/

void Logic::fillVector(int n){
	switch (mSelectedVectors[n]) {
	case 1:
		mGenerator.createSortedSet(mVectorToSort);
		break;
	case 2:
		mGenerator.createRandomSet(mVectorToSort);
		break;
	case 3:
		mGenerator.createBackwardSortedSet(mVectorToSort);
		break;
	case 4:
		mGenerator.createSortedSetWithFirstRandomValue(mVectorToSort);
		break;
	case 5:
		mGenerator.createBackwardSortedSetWithLastRandomValue(mVectorToSort);
		break;
	default:
		std::cout << "Vector filling failed!" << std::endl;
		break;
	}
}

/**
* Method responsible for opening files.
*
*/

void Logic::openFiles(){
	for (int i = 0; i < mAlgorithmsNumber; i++) {
			mLogger.openFile(mSelectedAlgorithms[i]);
	}
}

/**
* Method responsible for logging names of selected vectors.
*
*/

void Logic::logVectorTypes(int n){
	for (int i = 0; i < mAlgorithmsNumber; i++) {
		mLogger.logVectorType(mSelectedVectors[n],mSelectedAlgorithms[i]);
	}
}

/**Method responsible for printing information regarding sorting process being in progress to the console.
 *
 */

void Logic::printSortingInProgress(int algorithmNumber, int vectorNumber){
	std::string algorithmType, vectorType;

	switch (vectorNumber) {
		case 1:
			vectorType = "Sorted set";
			break;
		case 2:
			vectorType = "Random set";
			break;
		case 3:
			vectorType = "Backward sorted set";
			break;
		case 4:
			vectorType = "Sorted set with first random value";
			break;
		case 5:
			vectorType = "Backward sorted set with last random value";
			break;
		default:
			std::cout << "Unknown vector type" << std::endl;
			break;
		}

	switch (algorithmNumber) {
		case 1:
			algorithmType = "Bubble sort";
			break;
		case 2:
			algorithmType = "Quick sort";
			break;
		case 3:
			algorithmType = "Insertion sort";
			break;
		case 4:
			algorithmType = "Merge sort";
			break;
		case 5:
			algorithmType = "Counting sort";
			break;
		case 6:
			algorithmType = "Heap sort";
			break;
		default:
			std::cout << "Unknown vector type" << std::endl;
			break;
		}

	std::cout<<"Sorting in progress: "<<algorithmType<<" on "<<vectorType<<std::endl;
}

/**
* Method responsible for extension of the vector and
* filling it with integers.
*
*/

void Logic::extendVector(int n){
	switch (mSelectedVectors[n]) {
		case 1:
			mGenerator.extendSortedSet(mVectorToSort, mInterval);
			break;
		case 2:
			mGenerator.extendRandomSet(mVectorToSort, mInterval);
			break;
		case 3:
			mGenerator.extendBackwardSortedSet(mVectorToSort, mInterval);
			break;
		case 4:
			mGenerator.extendSortedSetWithFirstRandomValue(mVectorToSort, mInterval);
			break;
		case 5:
			mGenerator.extendBackwardSortedSetWithLastRandomValue(mVectorToSort, mInterval);
			break;
		default:
			std::cout << "Vector extension failed!" << std::endl;
			break;
		}
}

/**
* Method responsible for logging sorting results into a CSV file.
*
*/

void Logic::logSortingToFile(int algorithmIndex, int iteration){
	mLogger.logSortingResults(mVectorSize + (iteration * mInterval), mSortingAlgorithm->getTime(), mSortingAlgorithm->getTransitions(),mSelectedAlgorithms[algorithmIndex]);
}

/**
* Method responsible for filling vector, sorting it and calling logging method.
*
*/

void Logic::sort(){
	for(int k=0; k<mVectorsNumber; ++k){
		fillVector(k);
		logVectorTypes(k);
		for(unsigned int i = 0; i <= mIterations; i++) {
			if (i) {
				extendVector(k);
			}
			for (int j = 0; j < mAlgorithmsNumber; j++) {
				mSortingAlgorithm = mAlgorithmSetter.setSortingAlgorithm(mSelectedAlgorithms[j]);
				printSortingInProgress(mSelectedAlgorithms[j], mSelectedVectors[k]);
				mSortingAlgorithm->sort(mVectorToSort);
				logSortingToFile(j,i);
			}
		}
		mVectorToSort.resize(mVectorSize);
	}
}

/**
* Dectructor responsible for deletion of dynamically
* allocated variables/arrays.
*
*/

Logic::~Logic(){
	delete mSortingAlgorithm;
	delete[] mSelectedAlgorithms;
	delete[] mSelectedVectors;
}

