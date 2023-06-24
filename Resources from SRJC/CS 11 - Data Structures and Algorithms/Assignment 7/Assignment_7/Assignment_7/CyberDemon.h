/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2018
Assignment 7 - 2
CyberDemon.h


The CyberDemon class is derived from the Demon class, sets the species name to CybrDemon, and aquires all of the
Demon inherited members. 
The class calulates the damage done by a CyberDemon.

CyberDemon();
post: Creates a CyberDemon object.

CyberDemon( int newStrength, int newHitpoints );
post: Creates aCyberDemon object initalized using newStrength and NewHitpoints.

std::string getSpecies() const;
post: The string species "CyberDemon" is returned.

int getDamage() const;
post: Damage is returned.

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
		CyberDemon(int newStrength, int newHitpoints);
		std::string getSpecies() const;
	};
}


#endif /* CyberDemon_h */
