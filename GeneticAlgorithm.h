#pragma once
#include<iostream>
#include<vector>
#include "Individual.h"
class GeneticAlgorithm
{
public:
	GeneticAlgorithm();
	GeneticAlgorithm(double newMuteProbabilty, double newCrossoverProbability, int newPopulationSize, KnapsackProblem* newProblem, int newGeneration);
	~GeneticAlgorithm();
	void Print();
	int getMuteProbability();
	std::vector<Individual*>* getOldPopulation();
	std::vector<Individual*>* getNewPopulation();
	void createFirstPopulation();
	Individual* chooseParent();
	Individual* chooseRandomIndividual();
	void getBestIndividual();
	void runIteration();
	void mutation();
	void newToOldPopulation();
	void crossover();
	void PrintWholeGeneration();
private:
	double muteProbability;
	double crossoverProbability;
	KnapsackProblem* problem;
	int populationSize;
	Individual* bestSolution;
	std::vector<Individual*>*oldPopulation;
	std::vector<Individual*>*newPopulation;
	int generation;
	int generationCounter;
};

