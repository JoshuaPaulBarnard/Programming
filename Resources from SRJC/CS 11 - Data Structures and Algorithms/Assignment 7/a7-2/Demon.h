/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2018
Assignment 7 - 2
Demon.h



 The class Demon is a class derived from the Creature class it sets the species name to Demon and aquires all of the
 Creature inherited members. The class calulates the damage done by a Demon.


 Demon();
 post: A Demon object is created.

 Demon(int newStrength, int newHitpoints);
 post: A Demon object is created and initalized to newStrength and NewHitpoints.

 std::string getSpecies() const;
 post: string species "Demon" is returned

 int getDamage() const;
 post: damage is returned

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
