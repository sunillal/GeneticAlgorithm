# Genetic Algorithm
This repo contains implementation of binary encoded Genetic Algorithm. It uses elitism and roulette wheel selection technique.
The driver.cpp instantiates a GAEngine object to solve global optimization problem.  
The GAEngine class uses chromosome class to implement GA operations.

##Usage
For your specific optimization problem

####Modify the GA parameters in the constant.h

- GENERATION is the num of generations for GA
- CLEN is the chromosome length, equivalent to number of bits
- POP_SIZE is the population size
- MR is the mutation rate in the range [0,1]
- CR is the crossover rate in the range [0,1]

####Implement the evaluateFitness function in the driver.cpp
The driver.cpp already has code to solve 0 1 knapsack problem. You can use this as a guide to code the objective function for your optimization problem.  

Note this implementation of GA solves maximization problem by default.
If you need to solve a minimization objective function, G, transform it to maximization function, f:

f = -g + constant

####Make
simply run the make file, and execute the target file (currently set to knapsack)

