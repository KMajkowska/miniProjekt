#pragma once
#include<iostream>
#include<vector>
#include<fstream>

class KnapsackProblem 
{
public:
	KnapsackProblem();
	~KnapsackProblem();
	KnapsackProblem(int newNumberOfItems, double newKnapsackSize, std::vector<double> newItemsSize, std::vector<double> newValues);
	double getValue(int offset);
	double getWeight(int offset);
	double getSize();
	int getNumberOfItems();
	void setNumberOfItems(int newNumberSize);
	void setSize(double newSize);
	double getSolutionValue(std::vector<int>* genes);
	void setVectorSize(std::vector<double> newSizeVector);
	void setVectorValue(std::vector<double> newValueVector);
	bool readFromFile(std::string file);
private:
	double size;
	bool checkAttributes(int newNumberOfItems, int newKnapsackSize, std::vector<double> newItemsSize, std::vector<double> newValues);
	int numberOfItems;
	std::vector<double> itemsValue;
	std::vector<double> itemsSize;
};

