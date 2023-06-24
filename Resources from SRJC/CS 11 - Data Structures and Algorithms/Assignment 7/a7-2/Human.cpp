/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2018
Assignment 7 - 2
Human.cpp

*/

#include <stdio.h>
#include <iostream>
#include "Human.h"
#include <string>

namespace cs_creature
{
   Human::Human() : Creature()
   {
   }






   Human::Human( int newStrength, int newHitpoints )

   : Creature( newStrength, newHitpoints )
{
}






   std::string Human::getSpecies() const
   {

       std::string species = "Human";
       return species;
   }





}
