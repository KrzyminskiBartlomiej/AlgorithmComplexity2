#include "BubbleSort.hpp"

void BubbleSort::sort(std::vector<int>toSort)
{
	unsigned long long transitions=0;
	clock_t start,stop;
	bool changed=true;

	start=clock();
	while(changed){
		changed=false;
		int tmp;
		for(unsigned long long k=0; k<toSort.size(); ++k){
			if(toSort[k]>toSort[k+1]){
				tmp=toSort[k];
				toSort[k]=toSort[k+1];
				toSort[k+1]=tmp;
				changed=true;
				++transitions;
			}
		}
	}
	stop=clock();
	mTime = (double)(stop-start)/CLOCKS_PER_SEC;
	mTransitions = transitions;
}



