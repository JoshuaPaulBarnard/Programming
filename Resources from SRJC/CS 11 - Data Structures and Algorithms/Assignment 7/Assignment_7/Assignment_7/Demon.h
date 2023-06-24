/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2018
Assignment 7 - 2
Demon.h

 The Demon class is derived from the Creature class, sets the species name to Demon, and aquires all of the
 Creature inherited members. 
 The class calulates the damage done by a Demon.


 Demon();
 post: Creates a Demon object.

 Demon( int newStrength, int newHitpoints );
 post: Creates a Demon object initalized using newStrength and NewHitpoints.

 std::string getSpecies() const;
 post: The string species "Demon" is returned.

 int getDamage() const;
 post: Damage is returned.

 */

#ifndef Demon_h
#define Demon_h
#include "Creature.h"
namespace cs_creature
{
    class Demon : public Creature
    {
        public:
            Demon();
            Demon( int newStrength, int newHitpoints );
            std:: string getSpecies() const;
            int getDamage() const;
    };
}


#endif /* Demon_h */
