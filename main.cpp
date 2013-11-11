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

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#include "helper_functions.h"

using namespace std;

const int numberOfNodes = 100;
const int sizeOfInitialPopulation = 20;
const int numberOfGenerations = 100;
const int numberOfTests = 5;

struct FitnessChecker {
    vector<vector<bool> > graph;
    bool operator() (vector<Color> chromosome1, vector<Color> chromosome2) {
        return (fitnessFunction(chromosome1, graph)<fitnessFunction(chromosome2, graph));
    }
} fitnessCheck;

int main()
{
    // intro:
    cout << "Number of nodes: " << numberOfNodes << endl;
    cout << "Size of inital population: " << sizeOfInitialPopulation << endl;
    cout << "Number of generations " << numberOfGenerations << endl;
    cout << "Number of tests: " << numberOfTests << endl;

    // Start out by creating a graph with all nodes and edges (adjency matrix)
    vector<vector<bool> > graph = createInitialGraph(numberOfNodes);

    // This is loop is just for testing the algorithm on the same graph multiple times
    for (int test = 0; test < numberOfTests; ++test) {
        cout << "Test #" << test << endl;

        // Creating the random Initial Population:
        vector<vector<Color> > population = createInitialPopulation(sizeOfInitialPopulation, numberOfNodes);

        // Select parents to "mate" - This is the main part of the algorithm:
        for (int generation = 1; generation < numberOfGenerations; ++generation) {
            vector<vector<Color> > children;
            random_shuffle(population.begin(), population.end());
            for (unsigned int i = 0; i < population.size(); i+=2) {
                if (i == (population.size()-1)) break;
                pair<vector<Color>, vector<Color> > offspring;
                offspring = produceOffspring(population[i], population[i+1]);
                children.push_back(offspring.first);
                children.push_back(offspring.second);
            }

            // Put all new children into current population.
            population.insert(population.end(), children.begin(), children.end());

            // Discard all the weak chromosomes (throw away bottom half)
            fitnessCheck.graph = graph; // Ugly hack.
            sort(population.begin(), population.end(), fitnessCheck);

            vector<vector<Color> > tmpPopulation = population;
            population.clear();

            for (unsigned int i = tmpPopulation.size()/2; i < tmpPopulation.size(); ++i) {
                population.push_back(tmpPopulation[i]);
            }
        }
        cout << fitnessFunction(population[population.size()-1], graph) << endl;
    }

    return 0;
}

