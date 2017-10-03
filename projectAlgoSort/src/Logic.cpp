#include "Logic.hpp"

Logic::Logic(){
	setAlgorithmsNumber();
	setSelectedAlgorithms();
	setVectorsNumber();
	setSelectedVectors();
	setInitialVectorSize();
	setInterval();
	setIterations();
}

void Logic::setAlgorithmsNumber(){
	mAlgorithmsNumber = mSetter.setAlgorithmsNumber();
}

void Logic::setSelectedAlgorithms(){
	mSelectedAlgorithms = new unsigned int[mAlgorithmsNumber];
	if (mAlgorithmsNumber < 6) {
		for (int i = 0; i < mAlgorithmsNumber; ++i){
			mSelectedAlgorithms[i] = mSetter.setAlgorithmType(i);
		}
	} else {
		mAlgorithmsNumber = 6;
		for (int i = 0; i < mAlgorithmsNumber; ++i){
			mSelectedAlgorithms[i] = i + 1;
		}
	}
}

void  Logic::setVectorsNumber(){
	mVectorsNumber = mSetter.setVectorsNumber();
}

void  Logic::setSelectedVectors(){
	mSelectedVectors = new unsigned int[mVectorsNumber];
	if (mVectorsNumber < 5) {
		for (int i = 0; i < mVectorsNumber; ++i){
			mSelectedVectors[i] = mSetter.setVectorType(i);
		}
	} else {
		mVectorsNumber = 5;
		for (int i = 0; i < mVectorsNumber; ++i){
			mSelectedVectors[i] = i + 1;
		}
	}
}

void Logic::setInterval(){
	mInterval = mSetter.setInterval();
}

void Logic::setIterations(){
	mIterations = mSetter.setIterations();
}

void Logic::setInitialVectorSize(){
	mVectorSize = mSetter.setVectorSize();
	mVectorToSort.resize(mVectorSize);
}

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

void Logic::logVectorTypes(int n){
	for (int i = 0; i < mAlgorithmsNumber; i++) {
		mLogger.openFile(mSelectedAlgorithms[i]);
		mLogger.logVectorType(mSelectedVectors[n]);
		mLogger.closeFile();
	}
}

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

void Logic::logSortingResults(int algorithmIndex, int iteration){
	mLogger.openFile(mSelectedAlgorithms[algorithmIndex]);
	mLogger.logSortingResults(mVectorSize + (iteration * mInterval), mSortingAlgorithm->getTime(), mSortingAlgorithm->getTransitions());
	mLogger.closeFile();
}

void Logic::sort(){
	for(int k=0; k<mVectorsNumber ;++k){
		fillVector(k);
		logVectorTypes(k);
		for(unsigned int i = 0; i <= mIterations; i++) {
			if (i) {
				extendVector(k);
			}
			for (int j = 0; j < mAlgorithmsNumber; j++) {
				mSortingAlgorithm = mAlgorithmSetter.setSortingAlgorithm(mSelectedAlgorithms[j]);
				mSortingAlgorithm->sort(mVectorToSort);
				logSortingResults(j,i);
			}
		}
		mVectorToSort.resize(mVectorSize);
	}
}

Logic::~Logic(){
	delete mSortingAlgorithm;
	delete[] mSelectedAlgorithms;
	delete[] mSelectedVectors;
}

