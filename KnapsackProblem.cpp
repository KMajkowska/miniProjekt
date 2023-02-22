#include "KnapsackProblem.h"
#include "Individual.h"

KnapsackProblem::KnapsackProblem() {
	numberOfItems = 0;
	size = 0;
	itemsSize;
	itemsValue;
};

KnapsackProblem::KnapsackProblem(int newNumberOfItems, double newKnapsackSize, std::vector<double> newItemsSize, std::vector<double> newValues)
{
	if (checkAttributes(newNumberOfItems, newKnapsackSize, newItemsSize, newValues)) {
		numberOfItems = newNumberOfItems;
		itemsSize = newItemsSize;
		itemsValue = newValues;
		size = newKnapsackSize;
	}
	else
		std::cout << "Error";
}


KnapsackProblem :: ~KnapsackProblem() { //empty destructror, because everything  is static
	
}

double KnapsackProblem::getSolutionValue(std::vector<int>* genes)
{
	double solutionSize = 0;
	double solutionValue = 0;
	for (int i = 0; i < numberOfItems; i++)
	{
		if (genes->at(i) == 1)
		{
			solutionValue += itemsValue[i];
			solutionSize += itemsSize[i];
		}
	}
	if (solutionSize <= size)
		return solutionValue;
	else
		return 0;

}

bool KnapsackProblem::checkAttributes(int newNumberOfItems, int newKnapsackSize, std::vector<double> newItemsSize, std::vector<double> newValues)
{
	if (newNumberOfItems < 0) return false;
	if (newKnapsackSize < 0) return false;
	for (int i = 0; i < newNumberOfItems; i++) {
		if (newItemsSize[i] < 0) return false;
		if (newValues[i] < 0) return false;
	}
}

bool KnapsackProblem::readFromFile(std::string fileName)
{
	std::fstream file;
	int newNumberOfItems;
	double newKnapsackSize;
	std::vector<double>newItemsSize;
	std::vector<double>newItemsValue;
	file.open(fileName, std::ios::in);
	if (file.good()){
		file >> newNumberOfItems;
		file >> newKnapsackSize;
		double helperToRead;
		while (!file.eof()){
			file >> helperToRead;
			newItemsValue.push_back(helperToRead);
			file >> helperToRead;
			newItemsSize.push_back(helperToRead);
		}
		file.close();
		if (checkAttributes(newNumberOfItems, newKnapsackSize, newItemsSize, newItemsValue) )
		{

			itemsSize = newItemsSize;
			itemsValue = newItemsValue;
			size = newKnapsackSize;
			numberOfItems = newNumberOfItems;
			return true;
		}
		else 
			return false;
	}
	else {
		return false;
	}
}

void KnapsackProblem::setVectorSize(std::vector<double> newSizeVector)
{
	itemsSize = newSizeVector;
}

void KnapsackProblem::setVectorValue(std::vector<double> newValueVector)
{
	itemsValue = newValueVector;
}

void KnapsackProblem::setNumberOfItems(int newNumberSize)
{
	numberOfItems = newNumberSize;
}

void KnapsackProblem::setSize(double newSize)
{
	size = newSize;
}

int KnapsackProblem::getNumberOfItems()
{
	return numberOfItems;
};

double KnapsackProblem::getSize()
{
	return size;
};

double KnapsackProblem::getValue(int offset)
{
	return itemsValue[offset];
}

double KnapsackProblem::getWeight(int offset)
{
	return itemsSize[offset];
};


