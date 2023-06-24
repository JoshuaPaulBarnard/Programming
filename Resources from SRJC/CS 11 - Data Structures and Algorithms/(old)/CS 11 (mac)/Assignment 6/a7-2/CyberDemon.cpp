/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2018
Assignment 7 - 2
CyberDemon.cpp

*/


#include <stdio.h>
#include <iostream>
#include "CyberDemon.h"
#include <string>

namespace cs_creature
{
    CyberDemon::CyberDemon() : Demon()
    {
    }






    CyberDemon::CyberDemon( int newStrength, int newHitpoints )

    : Demon( newStrength, newHitpoints )
    {
    }






    std::string CyberDemon::getSpecies() const
    {
        std::string speciese = "CyberDemon";
        return speciese;
    }


}
