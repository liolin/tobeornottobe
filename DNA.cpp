#include "DNA.h"

DNA::DNA(int length)
{
    for(int i = 0; i < length; i++)
    {
	this->genes.push_back(this->newChar());
    }

    this->fitness = 0;
}

char DNA::operator[](const int index)
{
    return this->genes[index];
}

void DNA::calcFitness(std::string target)
{
    float score = 0;
    for(int i = 0; i < target.length(); i++)
    {
	if(this->genes[i] == target[i])
	    score++;
    }
    
    this->fitness = score / float(target.length()) * 100;
}

DNA DNA::crossOver(DNA parentB)
{
    DNA child(this->genes.size());
    int mid = std::rand() % this->genes.size();

    for(int i = 0; i < this->genes.size(); i++)
    {
	if(i < mid)
	    child.genes[i] = this->genes[i];
	else
	    child.genes[i] = parentB.genes[i];
    }

    return child;
}

void DNA::mutate(int mutrate)
{
    for(int i = 0; i < this->genes.size(); i++)
    {
	if(std::rand() % 100 < mutrate)
	{
	    this->genes[i] = this->newChar();
	}
    }
}

std::string DNA::getValue()
{
    std::stringstream ss;
    for(int i = 0; i < this->genes.size(); i++)
	ss << this->genes[i];

    return ss.str();
}

int DNA::getFitness()
{
    return this->fitness;
}

char DNA::newChar()
{
    // random between 32 and 126
    char random = (char)32 + (std::rand() % (int)(126 - 32 + 1));

    return random;
}
