#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

class Human
{
    private:

    char*   name;
    int     health;
    int     strength;

    public:

    Human();
    char*   getName();
    void    setName(char* in);
    int     getHealth();
    void    setHealth(int in);
    int     getStrength();
    void    setStrenght(int in);
    void    punch(Human &target);
    void    sayBonjour();
};

int     menu();
void    printError();
void    printRules();
void    printMenu();
int     play();
int     playScene1(int sc);

#endif