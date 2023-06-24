/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2018
Assignment 7 - 2
Balrog.cpp



 The class Balrog is a class derived from the Demon class it sets the species name to Balrog and aquires all of the
 Demon inherited members. The class calulates the damage done by a Balrog.


 Balrog();
 post: A Balrog object is created.

 Balrog(int newStrength, int newHitpoints);
 post: A Balrog object is created and initalized to newStrength and NewHitpoints.

 std::string getSpecies() const;
 post: string species "Balrog" is returned

 int getDamage() const;
 post: damage is returned

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
