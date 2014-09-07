GeneticAlg_GraphColorProb
=========================

Genetic Algorithm for Graph Coloring Problem

Simple program to show a simple genetic algorithm to solve the graph coloring problem.

Created as a small school project as part of a course.

---

Implements a genetic algorithm for the graph coloring problem (with three colours).

Uses the 2­points crossover

Testes the genetic algorithm on some random graphs.

Questions that is this program is trying to address:
Does the size of the initial population influence the solution quality ?
Does the number of generations ( stop criterion ) influence the solution quality ?

---
Algorithm:

A GA has the following general steps:

1-Start with a population of chromosomes ( individuals) generated at random
2-Determine the fitness of the individuals by decoding their chromosomes and applying the fitness function
3-Select parent for next generation
4-Mate selected parents to produce offspring using genetic operators
    ( Different Methods )
5-Eliminate the individuals with weak fitness
    (Different Methods )
Repeat 3-5 until ( stop)
Solution = individual with the highest fitness
