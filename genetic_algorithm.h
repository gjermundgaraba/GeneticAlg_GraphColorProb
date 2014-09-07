#ifndef GENETIC_ALGORITHM_H
#define GENETIC_ALGORITHM_H

#include <vector>

typedef std::vector<std::vector<bool> > Graph;

class GeneticAlgorithm {
public:
    GeneticAlgorithm(Graph initialGraph) : graph(initialGraph) {}

    int solve();

    int sizeOfInitialPopulation = 0;
    int numberOfNodes = 0;
    int numberOfGenerations = 0;
private:
    Graph graph;
};

#endif
