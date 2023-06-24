/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2018
Assignment 7 - 2
Creature.h


Creature class is the base class of the generic creature class, containing the atributes all the creatures will inherent.
Mutators and accesors allows you to get and change the data members, and virtual functions so the compiler
knows what fucntion to call at run time.

Creature();
post: A Creature object is created and initialized to strength = 10 and hitpoints = 10.

Creature( int newStrength, int newHitpoints );
post: Initializes a Creature object to newStrength and newHitPoints.

virtual int getDamage() const;
post: Calculates damage, and announces the attack and its damage.

virtual std::string getSpecies() const = 0;
post: A string species "Creature" is returned.

void changeStrength( const int& newStrength );
post: Creates Mutator, assigns newStrength to strength.

void changeHitpoints( const int& newHitpoints );
post: Creates Mutator, assigns newHitpoints to hitpoints.

int getHitpoints() const;
post:  Returns hitpoints.

int getStrength() const;
post:  Returns hitpoints.

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
		Creature(int newStrength, int newHitpoints);
		virtual int getDamage() const;
		virtual std::string getSpecies() const = 0;
		void changeStrength(const int& newStrength);
		void changeHitpoints(const int& newHitpoints);
		int getHitpoints() const;
		int getStrength() const;
	};
}
#endif /* Creature_h */
#pragma once
