#ifndef POPULATION_H
#define POPULATION_H

#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include "DNA.h"

class Population
{
private:
    std::string target;
    int popsize;
    int mutrate;
    int fitest;
    std::vector<DNA> population;

    int getParent();
    
public:
    Population(std::string target, int popsize, int mutrate);
    
    void calcFitness();
    void generate();
    bool evaluate();

    std::string getFittest();
};

#endif /* POPLUATION_H */
