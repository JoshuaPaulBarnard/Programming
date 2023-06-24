/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2018
Assignment 7 - 2
Elf.h



 The class Elf is a class derived from the Creature class it sets the species name to elf and aquires all of the
 Creature inherited members. The class calculates the damage done by a Elf.

 Elf();
 post: A Elf object is created.

 Elf(int newStrength, int newHitpoints);
 post: A Elf object is created and initalized to newStrength and NewHitpoints.

 std::string getSpecies() const;
 post: string species "Elf" is returned

 int getDamage() const;
 post: damage is returned

 */

#ifndef Elf_h
#define Elf_h
#include "Creature.h"
namespace cs_creature
{
    class Elf: public Creature
    {
        public:
            Elf();
            Elf(int newStrength, int newHitpoints);
            std::string getSpecies() const;
            int getDamage() const;
    };
}

#endif /* Elf_h */
