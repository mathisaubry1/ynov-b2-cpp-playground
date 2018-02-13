#include "human.h"
using namespace std;

Human::Human()
{
    name = (char*)"Adam";
    health = 10;
    strength = 4;
}

char*   Human::getName()
{
    return (name);
}

void    Human::setName(char* in)
{
    name = in;
}

int     Human::getHealth()
{
    return (health);
}

void    Human::setHealth(int in)
{
    health = in;
}

int     Human::getStrength()
{
    return (strength);
}

void    Human::setStrenght(int in)
{
    strength = in;
}

void    Human::punch(Human &target)
{
    target.setHealth(target.health - strength);
}

void    Human::sayBonjour()
{
    printf("%s dit bonjour\n", name);
}