#include "genetic_algorithm.h"

#include "helper_functions.h"
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef vector<vector<Color> > ColorMatrix;
typedef pair<vector<Color>, vector<Color> > ColorPair;

struct FitnessChecker {
    Graph graph;
    bool operator() (vector<Color> chromosome1, vector<Color> chromosome2) {
        return (fitnessFunction(chromosome1, graph) < fitnessFunction(chromosome2, graph));
    }
} fitnessCheck;

int GeneticAlgorithm::solve() {
    // Creating the random Initial Population:
    ColorMatrix population = createInitialPopulation(sizeOfInitialPopulation, numberOfNodes);

    // Select parents to "mate" - This is the main part of the algorithm:
    for (int generation = 1; generation < numberOfGenerations; ++generation) {
        ColorMatrix children;
        random_shuffle(population.begin(), population.end());
        for (unsigned int i = 0; i < population.size(); i+=2) {
            if (i == (population.size()-1)) break;
            ColorPair offspring;
            offspring = produceOffspring(population[i], population[i+1]);
            children.push_back(offspring.first);
            children.push_back(offspring.second);
        }

        // Put all new children into current population.
        population.insert(population.end(), children.begin(), children.end());

        // Discard all the weak chromosomes (throw away bottom half)
        fitnessCheck.graph = graph; // Ugly hack.
        sort(population.begin(), population.end(), fitnessCheck);

        ColorMatrix tmpPopulation = population;
        population.clear();

        for (unsigned int i = tmpPopulation.size()/2; i < tmpPopulation.size(); ++i) {
            population.push_back(tmpPopulation[i]);
        }
    }

    return fitnessFunction(population[population.size()-1], graph);
}
