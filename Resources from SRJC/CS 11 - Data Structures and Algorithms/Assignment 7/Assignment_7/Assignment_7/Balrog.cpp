/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2018
Assignment 7 - 2
Balrog.cpp

*/

#include <stdio.h>
#include <iostream>
#include "Balrog.h"
#include <string>

namespace cs_creature
{
    Balrog::Balrog() : Demon()
    {
    }






    Balrog::Balrog( int newStrength, int newHitpoints )

    : Demon( newStrength, newHitpoints )
    {
    }






    std::string Balrog::getSpecies() const
    {
        std::string speciese = "Balrog";
        return speciese;
    }






    int Balrog::getDamage() const
    {
        int damage1;
        int damage2 = (rand() % getStrength()) + 1;
        damage1 = Demon::getDamage();
        std::cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << std::endl;
        damage1 += damage2;
        return damage1;
    }


}
