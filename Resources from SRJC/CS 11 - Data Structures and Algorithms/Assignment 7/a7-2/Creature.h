/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2018
Assignment 7 - 2
Creature.h




 The Creature class is designed  to be a base class of a generic creature, having all the atributes all creatures will have.
 It Allows you to get and change the data memmbers using mutators and accesors. Also using Virtual functions so the compiler
 knows what fucntion to call at run time.

 Creature();
 post: a Creature object is created and initialized to strength = 10 and hitpoints = 10.

 Creature(int newStrength, int newHitpoints);
 post: a Creature object is initalized to newStrength and newHitPoints

 virtual int getDamage() const;
 post: The damage is calculated and a message announcing the attck and by who did it is displayed and damage is returned.

 virtual std::string getSpecies() const = 0;
 post: string species "Creature" is returned

 void changeStrength(const int& newStrength);
 post:Mutator created, strength is assigned the value passe in as newStrength

 void changeHitpoints(const int& newHitpoints);
 post: Mutator created, hitpoints is assigned the value passe in as newHitpoints

 int getHitpoints() const;
 post: hitpoints is returned

 int getStrength() const;
 post: strength is returned

*/

#ifndef Creature_h
#define Creature_h
#include <string>

namespace cs_creature
{
    class Creature
    {
        private:
            int strength;
            int hitpoints;

        public:
            Creature();
            Creature( int newStrength, int newHitpoints );
            virtual int getDamage() const;
            virtual std::string getSpecies() const = 0;
            void changeStrength(const int& newStrength);
            void changeHitpoints(const int& newHitpoints);
            int getHitpoints() const;
            int getStrength() const;
    };
}
#endif /* Creature_h */
