#ifndef DNA_H
#define DNA_H

#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <sstream>

class DNA
{
private:
    std::vector<char> genes;
    int fitness;

    char newChar();
public:
    DNA(int length);

    std::vector<char> getGenes();
    std::string getValue();
    int getFitness();

    void calcFitness(std::string target);
    DNA crossOver(DNA parentB);
    void mutate(int mutrate);
    
    char operator[](const int index);
    DNA& operator++();
    DNA operator++(int);
};

#endif /* DNA_H */
