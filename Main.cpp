#include <iostream>
#include"GeneticAlgorithm.h"
#include"KnapsackProblem.h"


int main()
{
    srand(time(NULL));
    KnapsackProblem problem;
    if (problem.readFromFile("knapsack.txt")) {
        GeneticAlgorithm AG = GeneticAlgorithm(0.10, 0.60, 4, &problem, 100);
        AG.runIteration();
        AG.Print();
    }
 }
