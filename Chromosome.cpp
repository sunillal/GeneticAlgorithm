/*
 *  Chromosome.cpp
 *
 *  Created by Sunil Lal on 6/24/06.
 *  lal.sunil[at]gmail.com
 *
 *  Copyright 2006 All rights reserved.
 *
 */

#include "Chromosome.h"

Chromosome::Chromosome(){
	

	for(int i=0; i<CLEN; i++)
		gene[i]=rand()%2;

}
			
void Chromosome::setGene(int i, bool val){

	gene[i] = val;
}

bool Chromosome::getGene(int i){

	return gene[i];
}

void Chromosome::mutate(float mr){

	float r;
	
	for(int i=0; i<CLEN; i++){
	
		r = (rand()%10001)/10000.0;
		
		if(r <= mr)
			gene[i]=!gene[i];
	}
}
			
void Chromosome::crossover(Chromosome p, Chromosome &o1, Chromosome &o2){

	int crosspos;
	
	crosspos = (rand()%(CLEN-2)) + 1;
	
	for(int i = 0; i<crosspos; i++){
		o1.setGene(i,gene[i]);
		o2.setGene(i,p.getGene(i));
	}
	
	for(int j=crosspos; j<CLEN; j++){
		o1.setGene(j,p.getGene(j));
		o2.setGene(j,gene[j]);
	}
	
}
		

double Chromosome::getFitness(){

	return fitness;
}

void Chromosome::print(){

//	for(int i=0;i<CLEN; i++)
//		cout<<gene[i];
	cout<<" "<<fitness<<endl;
}

void Chromosome::getSolution(bool sol[]){   

		
	for(int i=0; i<CLEN; i++)
		sol[i] = gene[i];
		
}


void Chromosome::setFitness(double f){

	fitness = f;
}
	