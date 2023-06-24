/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2018
Assignment 7 - 2
a7-2.cpp

*/

#include <iostream>
#include "Human.h"
#include "Elf.h"
#include "Demon.h"
#include "CyberDemon.h"
#include "Balrog.h"
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace cs_creature;

void battleArena( Creature &Creature1, Creature& Creature2 );

int main()
{
    srand(time(0));

    Human h1;
    Elf e1;
    CyberDemon c1;
    Balrog b1;

    Human h( 20, 30 );
    Elf e( 40, 50 );
    CyberDemon c( 60, 70 );
    Balrog b( 80, 90 );


    Elf e2( 50,50 );
    Balrog b2( 50,50 );

    battleArena( e2, b2 );


    cout << "default Human strength/hitpoints: " << h1.getStrength() << "/" << h1.getHitpoints() << endl;
    cout << "default Elf strength/hitpoints: " << e1.getStrength() << "/" << e1.getHitpoints() << endl;
    cout << "default Cyberdemon strength/hitpoints: " << c1.getStrength() << "/" << c1.getHitpoints() << endl;
    cout << "default Balrog strength/hitpoints: " << b1.getStrength() << "/" << b1.getHitpoints() << endl;
    cout << "non-default Human strength/hitpoints: " << h.getStrength() << "/" << h.getHitpoints() << endl;
    cout << "non-default Elf strength/hitpoints: " << e.getStrength() << "/" << e.getHitpoints() << endl;
    cout << "non-default Cyberdemon strength/hitpoints: " << c.getStrength() << "/" << c.getHitpoints() << endl;
    cout << "non-default Balrog strength/hitpoints: " << b.getStrength() << "/" << b.getHitpoints() << endl;
    cout << endl << endl;

    cout << "Examples of " << h.getSpecies() << " damage: " << endl;
    for ( int i = 0; i < 10; i++ )
    {
        int damage = h.getDamage();
        cout << " Total damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;



    cout << "Examples of " << e.getSpecies() << " damage: " << endl;
    for ( int i = 0; i < 10; i++ )
    {
        int damage = e.getDamage();
        cout << " Total damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;



    cout << "Examples of " << c.getSpecies() << " damage: " << endl;
    for ( int i = 0; i < 10; i++ )
    {
        int damage = c.getDamage();
        cout << " Total damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;



    cout << "Examples of " << b.getSpecies() << " damage: " << endl;
    for ( int i = 0; i < 10; i++ )
    {
        int damage = b.getDamage();
        cout << " Total damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;
}






/*
 void battleArena function gets two Creatures objects as parameters and lets those two creatures battle till either one or
 both of their hitpoints is <= 0. battleArena using a while loop to test if creature1.getHitpoints and
 creature2.getHitpoints are > 0. inside the loop int damage1, damage2, hitpoints1, and hitpoints2 are initalized.
 damage1 and hitpoints1 are assigned the values from Creature1.getDamage and Creature1.getHitpoints and damage 2 and
 hitpoints1 are assigned the values from Creature2.getDamage and Creature2.getHitpoints. damage2 is subtracted from
 hitpoints1 and damage1 is subtracted from hitpoints2. using the changeHitpoints function get the new hitpoints of
 creature1 and creature2. If() else if statements test to see if there is a win or a tie and displays the win or tie status.
*/
    void battleArena( Creature &Creature1, Creature& Creature2 )
    {


        while( Creature1.getHitpoints() > 0 && Creature2.getHitpoints() > 0 )
        {
            int damage1;
            int damage2;
            int hitpoints1;
            int hitpoints2;
            damage1 = Creature1.getDamage();
            damage2 = Creature2.getDamage();
            hitpoints1 = Creature1.getHitpoints();
            hitpoints2 = Creature2.getHitpoints();
            hitpoints1 -= damage2;
            hitpoints2 -= damage1;
            Creature1.changeHitpoints( hitpoints1 );
            Creature2.changeHitpoints( hitpoints2 );

            if( hitpoints1 <= 0 && hitpoints2 > 0 )
            {
                std::cout << Creature2.getSpecies() << " Won" << std::endl;
            }
            else if( hitpoints2 <= 0 && hitpoints1 > 0 )
            {
                std::cout << Creature1.getSpecies() << " Won" << std::endl;
            } else if( hitpoints1 <= 0 && hitpoints2 <= 0 )
            {
                std::cout << "TIE" <<endl;
            }
        }
    }

/*
 The Elf attacks for 18 points!
 Magical attack inflicts 18 additional damage points!
 The Balrog attacks for 20 points!
 Balrog speed attack inflicts 12 additional damage points!
 The Elf attacks for 18 points!
 The Balrog attacks for 17 points!
 Balrog speed attack inflicts 23 additional damage points!
 TIE
 default Human strength/hitpoints: 10/10
 default Elf strength/hitpoints: 10/10
 default Cyberdemon strength/hitpoints: 10/10
 default Balrog strength/hitpoints: 10/10
 non-default Human strength/hitpoints: 20/30
 non-default Elf strength/hitpoints: 40/50
 non-default Cyberdemon strength/hitpoints: 60/70
 non-default Balrog strength/hitpoints: 80/90


 Examples of Human damage:
 The Human attacks for 11 points!
 Total damage = 11

 The Human attacks for 10 points!
 Total damage = 10

 The Human attacks for 18 points!
 Total damage = 18

 The Human attacks for 15 points!
 Total damage = 15

 The Human attacks for 14 points!
 Total damage = 14

 The Human attacks for 5 points!
 Total damage = 5

 The Human attacks for 17 points!
 Total damage = 17

 The Human attacks for 17 points!
 Total damage = 17

 The Human attacks for 16 points!
 Total damage = 16

 The Human attacks for 14 points!
 Total damage = 14


 Examples of Elf damage:
 The Elf attacks for 11 points!
 Magical attack inflicts 11 additional damage points!
 Total damage = 22

 The Elf attacks for 32 points!
 Magical attack inflicts 32 additional damage points!
 Total damage = 64

 The Elf attacks for 23 points!
 Total damage = 23

 The Elf attacks for 34 points!
 Magical attack inflicts 34 additional damage points!
 Total damage = 68

 The Elf attacks for 4 points!
 Total damage = 4

 The Elf attacks for 20 points!
 Magical attack inflicts 20 additional damage points!
 Total damage = 40

 The Elf attacks for 10 points!
 Magical attack inflicts 10 additional damage points!
 Total damage = 20

 The Elf attacks for 31 points!
 Total damage = 31

 The Elf attacks for 17 points!
 Magical attack inflicts 17 additional damage points!
 Total damage = 34

 The Elf attacks for 17 points!
 Magical attack inflicts 17 additional damage points!
 Total damage = 34


 Examples of CyberDemon damage:
 The CyberDemon attacks for 47 points!
 Demonic attack inflicts 50 additional damage points!
 Total damage = 97

 The CyberDemon attacks for 12 points!
 Demonic attack inflicts 50 additional damage points!
 Total damage = 62

 The CyberDemon attacks for 22 points!
 Total damage = 22

 The CyberDemon attacks for 6 points!
 Demonic attack inflicts 50 additional damage points!
 Total damage = 56

 The CyberDemon attacks for 3 points!
 Total damage = 3

 The CyberDemon attacks for 1 points!
 Total damage = 1

 The CyberDemon attacks for 53 points!
 Total damage = 53

 The CyberDemon attacks for 37 points!
 Total damage = 37

 The CyberDemon attacks for 41 points!
 Total damage = 41

 The CyberDemon attacks for 47 points!
 Total damage = 47


 Examples of Balrog damage:
 The Balrog attacks for 55 points!
 Balrog speed attack inflicts 56 additional damage points!
 Total damage = 111

 The Balrog attacks for 40 points!
 Balrog speed attack inflicts 70 additional damage points!
 Total damage = 110

 The Balrog attacks for 5 points!
 Balrog speed attack inflicts 25 additional damage points!
 Total damage = 30

 The Balrog attacks for 46 points!
 Demonic attack inflicts 50 additional damage points!
 Balrog speed attack inflicts 55 additional damage points!
 Total damage = 151

 The Balrog attacks for 24 points!
 Balrog speed attack inflicts 31 additional damage points!
 Total damage = 55

 The Balrog attacks for 26 points!
 Balrog speed attack inflicts 71 additional damage points!
 Total damage = 97

 The Balrog attacks for 14 points!
 Balrog speed attack inflicts 80 additional damage points!
 Total damage = 94

 The Balrog attacks for 15 points!
 Balrog speed attack inflicts 46 additional damage points!
 Total damage = 61

 The Balrog attacks for 44 points!
 Balrog speed attack inflicts 8 additional damage points!
 Total damage = 52

 The Balrog attacks for 43 points!
 Balrog speed attack inflicts 50 additional damage points!
 Total damage = 93


 Program ended with exit code: 0
*/
