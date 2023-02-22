
#pragma once
#include "KnapsackProblem.h"

class Individual
{
public:
	Individual();
	Individual(KnapsackProblem* newProblem);
	Individual(std::vector<int>*genotype, KnapsackProblem* newProblem);
	~Individual();
	void setFitness();
	void mute(double muteProbabilty);
	std::vector<Individual*> cross(Individual& otherIndividual, int cut, double crossoverProbability);
	std::vector<int>* getGenes();
	double getFitness();
	Individual* Clone();
	Individual(const Individual& pcOther);
	void PrintGenes();
	void operator=(const Individual& other);
private:
	std::vector<int>* genes; //vector if an item is in the knapsack or not
	KnapsackProblem* problem;
	double fitness;
};

