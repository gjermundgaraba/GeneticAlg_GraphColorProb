/*
A GA has the following general steps:
3
￼1-Start with a population of chromosomes ( individuals) generated at random
2-Determine the fitness of the individuals by decoding their chromosomes and applying the fitness function
3-Select parent for next generation
4-Mate selected parents to produce offspring using genetic operators
    ( Different Methods )
5-Eliminate the individuals with weak fitness
    (Different Methods )
Repeat 3-5 until ( stop)
Solution = individual with the highest fitness
*/

#include "genetic_algorithm.h"
#include "helper_functions.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>


using namespace std;

const int numberOfNodes = 100;
const int sizeOfInitialPopulation = 20;
const int numberOfGenerations = 100;
const int numberOfTests = 5;

int main()
{
    // intro:
    cout << "Number of nodes: " << numberOfNodes << endl;
    cout << "Size of inital population: " << sizeOfInitialPopulation << endl;
    cout << "Number of generations " << numberOfGenerations << endl;
    cout << "Number of tests: " << numberOfTests << endl;

    // Start out by creating a graph with all nodes and edges (adjency matrix)
    Graph graph = createInitialGraph(numberOfNodes);

    // This is loop is just for testing the algorithm on the same graph multiple times
    for (int test = 0; test < numberOfTests; ++test) {
        cout << "Test #" << test << endl;

        GeneticAlgorithm geneticAlgorithm(graph);
        geneticAlgorithm.sizeOfInitialPopulation = sizeOfInitialPopulation;
        geneticAlgorithm.numberOfNodes = numberOfNodes;
        geneticAlgorithm.numberOfGenerations = numberOfGenerations;

        int result = geneticAlgorithm.solve();

        cout << result << endl;
    }

    return 0;
}

