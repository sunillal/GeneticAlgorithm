/*
 *  constants.h
 *
 *  Created by Sunil Lal on 9/3/2010.
 *  lal.sunil[at]gmail.com
 *
 *  Copyright 2010 All rights reserved.
 *
 */
#include <iostream>
#include <math.h>
#include <fstream>
#include <stdlib.h>
#include <time.h>

#ifndef CONSTANTS
#define CONSTANTS

using namespace std;

//GA paarmeters
const int GENERATION = 500;  //num of generations for GA
const int CLEN = 15;  //Chromosome length, equivalent to number of bits
const int POP_SIZE = 25;  //population size
const float MR = 0.15;  //mutation rate [0,1]
const float CR = 0.85;  //crossover rate [0,1]
#endif

