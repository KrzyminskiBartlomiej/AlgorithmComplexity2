#include "Logic.hpp"

Logic::Logic(){
	setAlgorithmsNumber();
	setselectedAlgorithms();
	setVectorType();
	setInitialVectorSize();
	setInterval();
	setIterations();
	fillVector();
}

void Logic::setAlgorithmsNumber(){
	mAlgorithmsNumber = mSetter.setAlgorithmsNumber();
}

void Logic::setselectedAlgorithms(){
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

void Logic::setVectorType(){
	mSelectedVector = mSetter.setVectorType();
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

void Logic::fillVector(){
	mFiller.fillVector(mVectorToSort, mSelectedVector);
}

void Logic::logVectorTypes(){
	for (int i = 0; i < mAlgorithmsNumber; i++) {
		mLogger.openFile(mSelectedAlgorithms[i]);
		mLogger.logVectorType(mSelectedVector);
		mLogger.closeFile();
	}
}

void Logic::extendVector(){
	mExtender.extendVector(mVectorToSort, mSelectedVector, mInterval);
}

void Logic::logSortingResults(int algorithmIndex, int iteration){
	mLogger.openFile(mSelectedAlgorithms[algorithmIndex]);
	mLogger.logSortingResults(mVectorSize + (iteration * mInterval), mSortingAlgorithm->getTime(), mSortingAlgorithm->getTransitions());
	mLogger.closeFile();
}

void Logic::sort(){
	for(unsigned int i = 0; i <= mIterations; i++) {
		if (i) {
			extendVector();
		}
		for (int j = 0; j < mAlgorithmsNumber; j++) {
			mSortingAlgorithm = mAlgorithmSetter.setSortingAlgorithm(mSelectedAlgorithms[j]);
			mSortingAlgorithm->sort(mVectorToSort);
			logSortingResults(j,i);
		}
	}
}

Logic::~Logic(){
	delete mSortingAlgorithm;
	delete[] mSelectedAlgorithms;
}

