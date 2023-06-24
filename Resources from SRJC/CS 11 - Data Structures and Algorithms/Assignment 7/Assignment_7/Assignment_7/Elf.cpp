/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2018
Assignment 7 - 2
Elf.cpp

*/


#include <stdio.h>
#include <iostream>
#include "Elf.h"
#include <string>

namespace cs_creature
{
    Elf::Elf() : Creature()
    {
    }






    Elf::Elf( int newStrength, int newHitpoints )

    : Creature( newStrength, newHitpoints )

    {
    }






    std::string Elf::getSpecies() const
    {
        std::string species = "Elf";
        return species;
    }






    int Elf::getDamage() const
    {
        int damage = 0;
        damage = Creature::getDamage();
        if ( ( rand() % 2 ) == 0 )
        {
            std::cout << "Magical attack inflicts " << damage << " additional damage points!" << std::endl;
            damage *= 2;
        }
        return damage;
    }
}
