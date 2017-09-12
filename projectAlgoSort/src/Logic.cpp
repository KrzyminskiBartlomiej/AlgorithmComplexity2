#include "Logic.hpp"

void logic(){
	unsigned int vectorSize;
	int vectorsNumber, algorithmsNumber;
	unsigned long long interval, iterations;
	SortingAlgorithm* sortingAlgorithm;
	Logger logger;
	srand(time(NULL));
	vectorsNumber = setVectorsNumber();
	algorithmsNumber = setAlgorithmsNumber();
	vectorSize = setVectorSize();
	interval = setInterval();
	iterations = setIterations();
	std::vector<int>vectorToSort(vectorSize);
	unsigned int selectedVectors[vectorsNumber];
	unsigned int selectedAlgorithms[algorithmsNumber];

	for(int i=0; i<vectorsNumber; ++i){
		selectedVectors[i]=setVectorType(i);
	}
	for(int i=0; i<algorithmsNumber; ++i){
		selectedAlgorithms[i]=setAlgorithmType(i);
	}
	for(int i=0; i<vectorsNumber;++i){
		fillVector(vectorToSort, selectedVectors[i], vectorSize);
		for(int y=0; y<algorithmsNumber; ++y){
				logger.openFile(selectedAlgorithms[y]);
				logger.logVectorType(selectedVectors[i]);
				logger.closeFile();
		}
		for(unsigned int k=0; k<=iterations; ++k){
			if(k){
				extendVector(vectorToSort, selectedVectors[i], interval);
			}
			for(int x=0; x<algorithmsNumber; ++x){
				sortingAlgorithm = setSortingAlgorithm(selectedAlgorithms[x]);
				sortingAlgorithm->sort(vectorToSort);
//				printSortingResults(sortingAlgorithm, selectedAlgorithms[x], selectedVectors[i],vectorSize+(k*interval));
				logger.openFile(selectedAlgorithms[x]);
				logger.logSortingResults(vectorSize+(k*interval), sortingAlgorithm->getTime(), sortingAlgorithm->getTransitions());
				logger.closeFile();
			}
		}
	}
	delete sortingAlgorithm;
}
