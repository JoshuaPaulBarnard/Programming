/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2018
Assignment 7 - 2
Demon.cpp

*/

#include <stdio.h>
#include <iostream>
#include "Demon.h"
#include <string>

namespace cs_creature
{
    Demon::Demon() : Creature()
    {
    }






    Demon::Demon(int newStrength, int newHitpoints)

    : Creature(newStrength, newHitpoints)
    {
    }






    std::string Demon::getSpecies() const
    {

        std::string species = "Demon";
        return species;
    }






    int Demon::getDamage() const
    {

        int damage;
        damage = Creature::getDamage();
        if ( rand() % 4 == 0 )
        {
            damage = damage + 50;
            std::cout << "Demonic attack inflicts 50 additional damage points!" << std::endl;
        }

        return damage;
    }
}
