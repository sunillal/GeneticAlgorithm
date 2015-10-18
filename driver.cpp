/*
 *  knapsack.cpp
 *
 *  Created by Sunil Lal on 6/24/06.
 *  lal.sunil[at]gmail.com
 *
 *  Copyright 2006 All rights reserved.
 *
 */

#include "GAEngine.h"

void saveBestSolution(ofstream &, bool []);
void evaluateFitness(GAEngine *);

int main(){

	ofstream paramFile;
	bool param[CLEN];
	
	srand(time(0));
	
	GAEngine ga;
	
	//the best solution at every generation is stored in the paramFile
    paramFile.open("solutions.txt",ios::out);
	if(paramFile.fail()){
		cout<<"Error opening parameter file\n";
		exit(1);
	}
	
	for(int i=0; i<=GENERATION; i++){
	
		//evaluate fitness of all chromosomes in the current generation
        evaluateFitness(&ga);
        
		//display the average and best fitness, and save the best solution in every generation
        ga.collateResults();
		cout<<i<<"\t"<<ga.getAvgFitness()<<"\t"<<ga.getBestChromosome().getFitness()<<endl;
		ga.getBestSolution(param);
        saveBestSolution(paramFile, param);
		
        //carry GA operations (selection, crossover, mutation) based on the fitness evalution
        ga.selection();
		ga.crossover();
		ga.mutation();
	}

	paramFile.close();
	
return 0;

}

//////////////////////////////////////////////////////////////////////////////////////////////	
void evaluateFitness(GAEngine *ga){

    double fitness;
    //sample 0 1 knapsack problem dataset. The optimal solution has a value of 1458
    float weight[] = {70,73,77,80,82,87,90,94,98,106,110,113,115,118,120};
    float value[] = {135,139,149,150,156,163,173,184,192,201,210,214,221,229,240};
    float capacity = 750;
    
    double totalWeight = 0, totalValue = 0;
    
    //The chromosome is represented by binary encoding, whereby a 1 at the jth index indicates that the
    // corresponding jth item is selected to be placed in the knapsack. 0 indicates otherwise.
    bool sol[CLEN];
    
    for(int i=0; i<POP_SIZE; i++){ // for all the chromosomes in the current population
        
        ga->getSolutions(sol,i); //get the ith chromosome
        
        for (int j=0; j < CLEN; j++){
            //evaluate the total weight and value of item selection as represented by the chromosome
            totalWeight += sol[j]*weight[j];
            totalValue += sol[j]*value[j];
        }
        
    
        if(totalWeight <= capacity)
            fitness = totalValue; //total value of selected items if the capacity is not exceeded
        else
            fitness = 0; //otherwise we penalize the chromosome for breaking the knaspsack
        

        ga->setFitness(i,fitness); //tell GA engine about the fitness of the ith chromosome
        
        //prepare for the next chromosome
        totalWeight = 0;
        totalValue = 0;
        
    }

	
}

//////////////////////////////////////////////////////////////////////////////////////////////
void saveBestSolution(ofstream &outfile, bool sol[]){

	outfile<<endl;
	for(int i=0; i<CLEN; i++)
		outfile<<sol[i]<<" ";

	outfile<<endl;

}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		