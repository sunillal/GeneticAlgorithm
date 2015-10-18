/*
 *  GAEngine.cpp
 *
 *  Created by Sunil Lal on 6/24/06.
 *  lal.sunil[at]gmail.com
 *
 *  Copyright 2006 All rights reserved.
 *
 */

#include "GAEngine.h"


void GAEngine::selection(){

	double sum=0, r, border;
	int count,max=0;
	Chromosome newPopl[POP_SIZE];
	
	//carry forward the best sol in a given generation
	for(int i=0; i<POP_SIZE; i++){
		if(population[i].getFitness()>population[max].getFitness())
			max = i;
	}
	newPopl[0] = population[max];
	
	//using roulette wheel selection method pick individuals for performing crossover operation
	for(int i=0; i<POP_SIZE; i++)
		sum += population[i].getFitness();
	
	for(int i=1; i<POP_SIZE; i++){

		r = sum * ((rand()%10001)/10000.0);
		count=0;
		border = population[0].getFitness();

		while(border<r){
			count++;
			border += population[count].getFitness();
		}

		newPopl[i] = population[count];

	}

	for(int i=0; i<POP_SIZE; i++)
		population[i] = newPopl[i];

}

void GAEngine::crossover(){

	double r;
	Chromosome offSpring1, offSpring2;

	for(int i=1; i<POP_SIZE-1; i+=2){ //starts from 1 so as to preserve the best solution
		r = (rand()%10001)/10000.0;

		if(r <= CR){
			population[i].crossover(population[i+1],offSpring1,offSpring2);
			population[i]=offSpring1;
			population[i+1]=offSpring2;
		}
	}
}

void GAEngine::mutation(){

	double r;

	for(int i=1; i<POP_SIZE; i++){  //starts from 1 so as to preserve the best solution
		r = (rand()%10001)/10000.0;

		if(r <= MR)
			population[i].mutate(MR);
	}
}

void GAEngine::collateResults(){

	double sum=0;
	int max=0;

	for(int i=0; i<POP_SIZE; i++){
		sum+=population[i].getFitness();
		
		if(population[i].getFitness()>population[max].getFitness())
			max = i;
	}

	avgFitness = sum/POP_SIZE;

	bestChromosome = population[max];
}

double GAEngine::getAvgFitness(){

	return avgFitness;
}

Chromosome GAEngine::getBestChromosome(){

	return bestChromosome;
}			 

void GAEngine::getBestSolution(bool s[]){

	bestChromosome.getSolution(s);
}

void GAEngine::print(){

	cout<<"---\n";
	for(int i=0; i<POP_SIZE; i++)
		population[i].print();
	cout<<"---"<<endl;
}

void GAEngine::getSolutions(bool s[],int indv){

	population[indv].getSolution(s);
}

void GAEngine::setFitness(int indv, double fit){

	population[indv].setFitness(fit);
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		