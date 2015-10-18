/*
 *  GAEngine.h
 *
 *  Created by Sunil Lal on 6/24/06.
 *  lal.sunil[at]gmail.com
 *
 *  Copyright 2006 All rights reserved.
 *
 */
 
#include "Chromosome.h"



class GAEngine {

	public:
			
		void selection();
		void crossover();
		void mutation();	
		void collateResults();
		
		double getAvgFitness();
		Chromosome getBestChromosome();
		void print();
		void getSolutions(bool [],int);
		void getBestSolution(bool []);
		void setFitness(int,double);
		
	private:
	
		Chromosome population[POP_SIZE], bestChromosome;
		double avgFitness;		


	
	

};

