#include "helper_functions.h"

#include <vector>
#include <ctime>
#include <cstdlib>
#include <utility>

using namespace std;

/* Returns number of satisfied edges */
int fitnessFunction(vector<Color> chromosome, vector<vector<bool> > graph) {
    int fitnessValue = 0;

    for (unsigned int i = 0; i < graph.size(); ++i) {
        for (unsigned int j = 0; j < graph.size(); ++j) {
            if (graph[i][j] == true && chromosome[i] != chromosome[j]) {
                fitnessValue++;
            }
        }
    }

    fitnessValue = fitnessValue/2;

    return fitnessValue;
}

/* Uses to point crossover to produce offspring between two parents.
 * A part of a genetic algorithm
 */
pair<vector<Color>, vector<Color> > produceOffspring(vector<Color> parent1, vector<Color> parent2) {
    int crossOverPoint1 = getRandomNumber(0, (int)parent1.size());
    int crossOverPoint2 = getRandomNumber(0, (int)parent1.size());

    if (crossOverPoint2 < crossOverPoint1) {
        int tmp = crossOverPoint1;
        crossOverPoint1 = crossOverPoint2;
        crossOverPoint2 = tmp;
    }

    for (int i = crossOverPoint1; i <= crossOverPoint2; ++i) {
        Color tmp = parent1[i];
        parent1[i] = parent2[i];
        parent2[i] = tmp;
    }

    pair<vector<Color>, vector<Color> > children;
    children.first = parent1;
    children.second = parent2;

    return children;
}

/* Creates an inital graph for use with genetic algorithm.
 * It creates an adjency matrix that tells whetever each node has an edge between them
 */
vector<vector<bool> > createInitialGraph(int numberOfNodes) {
    vector<vector<bool> > initalGraph(numberOfNodes, vector<bool>(numberOfNodes, false));

    for (unsigned int i = 0; i < initalGraph.size(); ++i) {
        int numberOfEdges = getRandomNumber(1, numberOfNodes/4); // Number of edges for each node is [1, 5]

        for (int j = 0; j < numberOfEdges; ++j) {
            int nodeToConnect = i;
            while (nodeToConnect == (int)i) nodeToConnect = getRandomNumber(0, numberOfNodes);

            initalGraph[i][nodeToConnect] = true;
            initalGraph[nodeToConnect][i] = true;
        }
    }

    return initalGraph;
}

/* Creates an initial random population for use with genetic algorithm */
vector<vector<Color> > createInitialPopulation(int sizeOfPopulation, int numberOfNodes) {
    vector<vector<Color> > initPopulation;

    //
    for(int i = 0; i < sizeOfPopulation; ++i) {
        vector<Color> newChromosome;
        initPopulation.push_back(newChromosome);
    }

    //
    for(vector<Color> &chromosome : initPopulation) {
        for(int j = 0; j < numberOfNodes; ++j) {
            Color randomColor = Color(getRandomNumber(0, 3));
            chromosome.push_back(randomColor);
        }
    }

    return initPopulation;
}

/* Generates a random number with seed from the time it was first called */
int getRandomNumber(int min, int max) {
    if ((max+min) == 0) return 0; // We should not devide by zero

    static bool seedUsed = false;
    if (!seedUsed) { // if we havend used the seed already
        srand(time(0)); // use current time as seed for random generator
        seedUsed = true;
    }

    return rand() % max + min;
}

