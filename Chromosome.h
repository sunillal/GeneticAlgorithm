/*
 *  Chromosome.h
 *
 *  Created by Sunil Lal on 6/24/06.
 *  lal.sunil[at]gmail.com
 *
 *  Copyright 2006 All rights reserved.
 *
 */

#include "constants.h"

#ifndef _CHROMOSOME_H
#define _CHROMOSOME_H


class Chromosome {

	public:
	
	Chromosome();
	void setGene(int, bool);
	bool getGene(int);
	void mutate(float);
	void crossover(Chromosome, Chromosome &, Chromosome &);
	void setFitness(double);
	double getFitness();
	void getSolution(bool []);
	void print();
	
	
	private:
	
	bool gene[CLEN];
	double fitness;
	

};

#endif