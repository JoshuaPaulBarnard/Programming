/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2018
Assignment 7 - 2
Balrog.cpp


 The Balrog class is derived from the Demon class, sets the species name to Balrog, and aquires all of the
 Demon inherited members. 
 The class calulates the damage done by a Balrog.

 Balrog();
 post: Creates a Balrog object.

 Balrog( int newStrength, int newHitpoints );
 post: Creates a Balrog object initalized using newStrength and NewHitpoints.

 std::string getSpecies() const;
 post: The string species "Balrog" is returned.

 int getDamage() const;
 post: Damage is returned.

 */

#ifndef Balrog_h
#define Balrog_h
#include "Demon.h"
namespace cs_creature
{
    class Balrog : public Demon
    {
        public:
            Balrog();
            Balrog( int, int );
            std:: string getSpecies() const;
            int getDamage() const;
    };
}


#endif /* Balrog_h */
