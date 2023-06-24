/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2018
Assignment 7 - 2
Human.h



 The class Human is a class derived from the Creature class it sets the species name to human and aquires all of the
 Creature inherited members.

 Human();
 post: a Human object is created.

 Human(int newStrength, int newHitpoints);
 post: a Human object is created and initialized with newStrength and NewHitpoints.

 std:: string getSpecies() const;
 post: string "Human" is returned.

*/

#ifndef Human_h
#define Human_h
#include "Creature.h"

namespace cs_creature
{
    class Human : public Creature
    {
        public:
            Human();
            Human( int newStrength, int newHitpoints );
            std:: string getSpecies() const;
    };
}
#endif /* Human_h */
