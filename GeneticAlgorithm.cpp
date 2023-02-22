#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm()
{
	problem = NULL;
	populationSize = 0;
	muteProbability = 0;
	crossoverProbability = 0;
	generation = 0;
	generationCounter = 0;
	bestSolution = NULL;
	oldPopulation = NULL;
	newPopulation = NULL;
}

GeneticAlgorithm::GeneticAlgorithm(double newMuteProbabilty, double newCrossoverProbability, int newPopulationSize, KnapsackProblem* newProblem, int newGeneration)
{
	muteProbability = newMuteProbabilty;
	crossoverProbability = newCrossoverProbability;
	populationSize = newPopulationSize;
	problem = newProblem;
	bestSolution = NULL;
	generation = newGeneration;
	generationCounter = 0;
	oldPopulation = NULL;
	newPopulation = NULL;
	createFirstPopulation();
}

int GeneticAlgorithm::getMuteProbability()
{
	return muteProbability;
}

void GeneticAlgorithm::Print()
{
	for (int i = 0; i < bestSolution->getGenes()->size(); i++)
	{
		std::cout << bestSolution->getGenes()->at(i);
	}
	std::cout << std::endl;
}

std::vector<Individual*>* GeneticAlgorithm::getOldPopulation()
{
	return oldPopulation;
}

std::vector<Individual*>* GeneticAlgorithm::getNewPopulation()
{
	return newPopulation;
}

void GeneticAlgorithm::createFirstPopulation()
{
	oldPopulation = new std::vector<Individual*>();
	for (int i = 0; i < populationSize; i++)
	{
		oldPopulation->push_back(new Individual(problem));
	}
	
}

Individual* GeneticAlgorithm::chooseParent()
{
	int number1, number2;
	number1 = rand() % populationSize;
	number2 = rand() % populationSize;
	if ((*oldPopulation)[number1]->getFitness() > (*oldPopulation)[number2]->getFitness())
		return oldPopulation->at(number1);
	else
		return oldPopulation->at(number2);
}
Individual* GeneticAlgorithm::chooseRandomIndividual()
{
	int number1;
	number1 = rand() % populationSize;
	return oldPopulation->at(number1);
}

void GeneticAlgorithm::mutation()
{
	for (int i = 0; i < newPopulation->size(); i++)
	{
		newPopulation->at(i)->mute(muteProbability);
	}
}

void GeneticAlgorithm::newToOldPopulation()
{
	for (int i = 0; i < oldPopulation->size(); i++)
	{
		delete oldPopulation->at(i);
	}
	delete oldPopulation;
	oldPopulation = newPopulation;
	newPopulation = NULL;
}

void GeneticAlgorithm::getBestIndividual()
{
	if(bestSolution == NULL)
		bestSolution = oldPopulation->at(0)->Clone();
	for (int i = 0; i < (*oldPopulation).size(); i++)
	{
		if (oldPopulation->at(i)->getFitness() > bestSolution->getFitness()) {
			delete bestSolution;
			bestSolution = oldPopulation->at(i)->Clone();
		}
	}
}

void GeneticAlgorithm::crossover()
{
	std::vector<Individual*> children;
	newPopulation = new std::vector<Individual*>;
	while (oldPopulation->size() > newPopulation->size())
	{
		children = chooseParent()->cross(*chooseParent(), rand() % populationSize, crossoverProbability);
		newPopulation->push_back(children[0]);
		newPopulation->push_back(children[1]);
	}
}

void GeneticAlgorithm::runIteration()
{
	for (generationCounter = 0; generationCounter < generation; generationCounter++)
	{
		//getBestIndividual();
		crossover();
		mutation();
		//PrintWholeGeneration();
		//std::cout << std::endl;
		newToOldPopulation();
	}
	getBestIndividual();
}

void GeneticAlgorithm::PrintWholeGeneration()
{
	for (int i = 0; i < newPopulation->size(); i++)
	{
		newPopulation->at(i)->PrintGenes();
	}
}


GeneticAlgorithm::~GeneticAlgorithm()
{

	for (int i = 0; i < oldPopulation->size(); i++)
	{
		delete oldPopulation->at(i);
	}
	delete oldPopulation;
	delete newPopulation;
	delete bestSolution;
}

