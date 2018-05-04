#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Population.h"

using namespace std;

int main()
{
    std::srand(std::time(0));
    string target = "To be or not to be!";
    int popsize = 200;
    int mutrate = 1;
    Population pop(target, popsize, mutrate);

    bool finished = false;
    int generation = 1;
    while(!finished)
    {
	pop.calcFitness();
	pop.generate();
	finished = pop.evaluate();
	generation++;

	cout << pop.getFittest() << '\n';
    }

    cout << "Generation: " << generation << '\n';
    
    return 0;
}
