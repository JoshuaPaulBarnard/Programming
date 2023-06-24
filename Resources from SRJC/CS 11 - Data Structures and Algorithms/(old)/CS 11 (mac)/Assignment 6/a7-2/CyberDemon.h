/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2018
Assignment 7 - 2
CyberDemon.h



 The class CyberDemon is a class derived from the Demon class it sets the species name to CybrDemon and aquires all of the
 Demon inherited members. The class calulates the damage done by a CyberDemon.


 CyberDemon();
 post: A CyberDemon object is created.

 CyberDemon(int newStrength, int newHitpoints);
 post: A CyberDemon object is created and initalized to newStrength and NewHitpoints.

 std::string getSpecies() const;
 post: string species "CyberDemon" is returned

 int getDamage() const;
 post: damage is returned

 */

#ifndef CyberDemon_h
#define CyberDemon_h
#include "Demon.h"
namespace cs_creature
{
    class CyberDemon : public Demon
    {
        public:
            CyberDemon();
            CyberDemon( int newStrength, int newHitpoints );
            std:: string getSpecies() const;
    };
}


#endif /* CyberDemon_h */
