#include "Item.h"
Item::Item()
{
	weight = 0;
	value = 0;
}

Item::Item(double newWeight, double newValue)
{
	if (check(newWeight) && check(newValue)) {
		weight = newWeight;
		value = newValue;
	}
	else
	{

	}
}

Item::~Item()
{

}

double Item::getValue()
{
	return value;
}

double Item:: getWeight()
{
	return weight;
}

bool check(int variable)
{
	if (variable > 0)
		return true;
	else
		return false;
}