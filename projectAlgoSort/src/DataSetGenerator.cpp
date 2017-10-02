//============================================================================
// Name        : DataSetGenerator.cpp
// Description : C++ program for implementation of DataSetGenerator
//============================================================================
#include "DataSetGenerator.hpp"

void DataSetGenerator::createSortedSet(std::vector<int>&toFill){
	unsigned int valueToAdd = 0;
    for(std::vector<int>::iterator it=toFill.begin(); it!=toFill.end(); ++it){
		*it=valueToAdd++;
	}
}

void DataSetGenerator::extendSortedSet(std::vector<int>&toFill, unsigned long long toAdd){
    int lastElementIndex = toFill.size();
    int valueToAdd = toFill.back()+1;
    toFill.resize(toFill.size()+toAdd);
    for(unsigned int i=0; i<toAdd; ++i){
       toFill[lastElementIndex++]=valueToAdd++;
    }
}

void DataSetGenerator::createRandomSet(std::vector<int>& toFill){
	unsigned long long vectorSize = toFill.size();
	for(std::vector<int>::iterator it=toFill.begin(); it!=toFill.end(); ++it){
		*it=std::rand()%vectorSize;
	}
}

void DataSetGenerator::extendRandomSet(std::vector<int>& toFill, unsigned long long toAdd){
    int lastElementIndex = toFill.size();
    toFill.resize(toFill.size()+toAdd);
	for(unsigned int i=1; i<toAdd; ++i){
		toFill[lastElementIndex++]= std::rand()%toFill.size();
	}
}

void DataSetGenerator::createBackwardSortedSet(std::vector<int>& toFill){
	unsigned int valueToAdd = toFill.size()-1;
    for(std::vector<int>::iterator it=toFill.begin(); it!=toFill.end(); ++it){
		*it=valueToAdd--;
	}
}

void DataSetGenerator::extendBackwardSortedSet(std::vector<int>& toFill, unsigned long long toAdd){
	unsigned int valueToAdd=toFill.front();
    for(unsigned int i=0; i<toAdd; ++i){
    	toFill.insert(toFill.begin(),++valueToAdd);
    }
}

void DataSetGenerator::createSortedSetWithFirstRandomValue(std::vector<int>& toFill){
	toFill[0]=std::rand()%toFill.size();
	unsigned long valueToAdd = 1;
	for(std::vector<int>::iterator it=toFill.begin()+1; it!=toFill.end(); ++it){
		*it=valueToAdd++;
	}
}

void DataSetGenerator::extendSortedSetWithFirstRandomValue(std::vector<int>& toFill, unsigned long long toAdd){
	extendSortedSet(toFill,toAdd);
	toFill[0]=std::rand()%toFill.size();
}

void DataSetGenerator::createBackwardSortedSetWithLastRandomValue(std::vector<int>& toFill){
	createBackwardSortedSet(toFill);
	toFill[toFill.size()-1]= std::rand()%toFill.size();
}

void DataSetGenerator::extendBackwardSortedSetWithLastRandomValue(std::vector<int>& toFill, unsigned long long toAdd){
	  unsigned int valueToAdd=toFill.front();
      for(unsigned int i=0; i<toAdd; ++i){
	   	toFill.insert(toFill.begin(),++valueToAdd);
	  }
      toFill[toFill.size()-1]= std::rand()%toFill.size();
}
