/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2018
Assignment 7 - 2
Creature.cpp


CLASS INVARIANT:
The class has defined the following two private data members:

int strength;
int hitpoints;

Both strength and hitpoints are initialized to 10 for any creature.

*/
#include <stdio.h>
#include <iostream>
#include"Creature.h"
#include <string>

namespace cs_creature
{
	Creature::Creature()
	{
		strength = 10;
		hitpoints = 10;
	}






	Creature::Creature(int newStrength, int newHitpoints)
	{
		strength = newStrength;
		hitpoints = newHitpoints;

	}






	void Creature::changeStrength(const int& newStrength)
	{
		strength = newStrength;
	}





	void Creature::changeHitpoints(const int& newHitpoints)
	{
		hitpoints = newHitpoints;
	}






	int Creature::getHitpoints() const
	{
		return hitpoints;
	}






	int Creature::getStrength() const
	{
		return strength;
	}






	int Creature::getDamage() const
	{
		int damage = ( rand() % strength ) + 1;
		std::cout << "The " << getSpecies() << " attacks for " << damage << " points!" << std::endl;
		return damage;
	}






	std::string Creature::getSpecies() const
	{
		std::string Creature = "Creature";
		return Creature;
	}
}
