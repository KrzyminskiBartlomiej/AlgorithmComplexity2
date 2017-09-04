#include "DataSetGenerator.hpp"

DataSetGenerator::DataSetGenerator()
{}

void DataSetGenerator::createRandomSet(std::vector<int>& toFill, int n)
{
	for(int i=1; i<=n; ++i)
	{
		toFill.push_back(i);
	}
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(toFill.begin(),toFill.end(),std::default_random_engine(seed));
}

void DataSetGenerator::createSortedSet(std::vector<int>& toFill, int n)
{
	for(int i=1; i<=n; ++i)
	{
		toFill.push_back(i);
	}
}

void DataSetGenerator::createBackwardSortedSet(std::vector<int>& toFill, int n)
{
	for(int i=n; i>0; --i)
	{
		toFill.push_back(i);
	}
}

void DataSetGenerator::createSortedSetWithFirstRandomValue(std::vector<int>& toFill, int n)
{
	toFill.push_back(std::rand()%n);
	for(int i=1; i<n; ++i)
	{
		toFill.push_back(i);
	}
}

void DataSetGenerator::createBackwardSortedSetWithLastRandomValue(std::vector<int>& toFill, int n)
{
	for(int i=n; i>1; --i)
	{
			toFill.push_back(i);
	}
	toFill.push_back(std::rand()%n);
}




