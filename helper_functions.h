#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include <vector>
#include <utility>

enum Color { RED, GREEN, BLUE };

/* This is a set of helper functions for a genetic algorithm */
std::vector<std::vector<bool> > createInitialGraph(int numberOfNodes);

std::vector<std::vector<Color> > createInitialPopulation(int sizeOfPopulation, int numberOfNodes);

int fitnessFunction(std::vector<Color>, std::vector<std::vector<bool> > graph);

std::pair<std::vector<Color>, std::vector<Color> > produceOffspring(std::vector<Color> parent1, std::vector<Color> parent2);

/* Utility function */
int getRandomNumber(int min, int max);

#endif // HELPER_FUNCTIONS_H
