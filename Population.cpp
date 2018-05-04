#include "Population.h"

Population::Population(std::string target, int popsize, int mutrate)
{
    this->target = target;
    this->popsize = popsize;
    this->mutrate = mutrate;
    this->fitest = 0;

    for(int i = 0; i < this->popsize; i++)
    {
	DNA dna(this->target.length());
	this->population.push_back(dna);
    }
}

void Population::calcFitness()
{
    int score = 0;
    this->fitest = 0;
    for(int i = 0; i < this->popsize; i++)
    {
	this->population[i].calcFitness(this->target);
	if(this->population[i].getFitness() > score)
	{
	    score = this->population[i].getFitness();
	    this->fitest = i;
	}
    }
}

void Population::generate()
{
    std::vector<DNA> newGeneration;
    for(int i = 0; i < this->population.size(); i++)
    {
	DNA parentA = this->population[this->getParent()];
	DNA parentB = this->population[this->getParent()];
	DNA child = parentA.crossOver(parentB);
	child.mutate(this->mutrate);
	newGeneration.push_back(child);
    }

    this->population = newGeneration;
}

bool Population::evaluate()
{
    if(this->population[this->fitest].getValue() == this->target)
	return true;
    else
	return false;
}

std::string Population::getFittest()
{
    return this->population[this->fitest].getValue();
}


int Population::getParent()
{
    while(true)
    {
	int index = std::rand() % this->population.size();
	int random = std::rand() % 100;

	if(random < this->population[index].getFitness())
	    return index;
    }
}
