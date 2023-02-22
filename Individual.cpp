#include "Individual.h"

Individual::Individual()
{
	problem = NULL;
	fitness = 0;
}

Individual::~Individual()
{
	delete genes;
}

Individual::Individual(KnapsackProblem* newProblem)
{
	problem = newProblem;
	genes= new std::vector<int>();
	for (int i = 0; i < problem->getNumberOfItems(); i++) //firstly, we will randomly put things to the backpack
	{
		if (rand() % 2 == 0)
		{
			genes->push_back(1);
		}
		else
		{
			genes->push_back(0);
		}

	}
	setFitness();
};


Individual::Individual(std::vector<int>*genotype, KnapsackProblem* newProblem)
{
	genes = genotype;
	problem = newProblem;
	setFitness();
}

double Individual::getFitness()
{
	return fitness;
}

void Individual::setFitness()
{
	fitness = problem->getSolutionValue(genes);
}


void Individual::mute(double muteProbabilty)
{
	for (int i = 0; i < genes->size(); i++)
	{
			if (((double)rand() / (double)(RAND_MAX)) <= muteProbabilty)
			{
				if (genes->at(i) == 1)
					(*genes)[i] = 0;
				else
					(*genes)[i] = 1;
			}
	}
	setFitness();
};

Individual* Individual::Clone()
{
	return new Individual(*this);
}

Individual::Individual(const Individual& pcOther)
{
	genes = new std::vector<int>;
	fitness = pcOther.fitness;
	problem = pcOther.problem;
	for (int i = 0; i < pcOther.genes->size(); i++)
	{
		genes->push_back(pcOther.genes->at(i));
	}
}

std::vector<int>* Individual::getGenes()
{
	return genes;
}

void Individual::PrintGenes()
{
	for (int i = 0; i < genes->size(); i++)
	{
		std::cout << genes->at(i) << " ";
	}
	std::cout << std::endl;
}


std::vector<Individual*> Individual::cross(Individual& otherIndividual, int cut, double crossoverProbability)
{
	std::vector<Individual*> newChildren;
	std::vector<int>* first= new std::vector<int>;
	std::vector<int>* second= new std::vector<int>;
	if (((double)rand() / (double)(RAND_MAX)) <= crossoverProbability) {
		for (int i = 0; i < cut; i++)
		{
				first->push_back(genes->at(i));
				second->push_back(otherIndividual.genes->at(i));
		}
		for(int i=cut; i<genes->size(); i++)
		{
			first->push_back(otherIndividual.genes->at(i));
			second->push_back(genes->at(i));
		}
	
		newChildren.push_back(new Individual(first, problem));
		(*newChildren.at(0)).setFitness();
		newChildren.push_back(new Individual(second, problem));
		(*newChildren.at(1)).setFitness();
		first = NULL;
		second = NULL;
	}
	else
	{
		newChildren.push_back(otherIndividual.Clone());
		newChildren.push_back(this->Clone());
	}
	delete first;
	delete second;
	return newChildren;
};

