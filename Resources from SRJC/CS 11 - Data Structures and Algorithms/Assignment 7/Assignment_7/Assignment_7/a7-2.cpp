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
    srand( time( 0 ) );

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

	system("pause");
}






/*
 The void battleArena function gets two Creatures objects parameters, and battles the two creatures battle until 
 both their hitpoints = 0, or one of them has 0 or less hitpoints using a while loop to test if creature1.getHitpoints and
 creature2.getHitpoints are > 0. int damage1, damage2, hitpoints1, and hitpoints2 are initalized within the loop.
 The values of hitpoints1 and damage1 are assigned from Creature1.getHitpoints and Creature1.getDamage.  
 The values of hitpoints2 and damage 2 are assigned from Creature2.getHitpoints and Creature2.getDamage. 
 The values in damage2 are subtracted from hitpoints1.
 The values in damage1 are subtracted from hitpoints2. 
 The changeHitpoints function gets the new hitpoints of creature1 and creature2. 
 Finally, If else statements test whether or not there is a draw or win conditions, and displays the results.
*/
    void battleArena( Creature &Creature1, Creature& Creature2 )
    {


        while( Creature1.getHitpoints() > 0 && Creature2.getHitpoints() > 0 )
        {
            int damage1 = 0;
            int damage2 = 0;
            int hitpoints1 = 0;
            int hitpoints2 = 0;
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
The Elf attacks for 23 points!
The Balrog attacks for 44 points!
Balrog speed attack inflicts 8 additional damage points!
Balrog Won
default Human strength/hitpoints: 10/10
default Elf strength/hitpoints: 10/10
default Cyberdemon strength/hitpoints: 10/10
default Balrog strength/hitpoints: 10/10
non-default Human strength/hitpoints: 20/30
non-default Elf strength/hitpoints: 40/50
non-default Cyberdemon strength/hitpoints: 60/70
non-default Balrog strength/hitpoints: 80/90


Examples of Human damage:
The Human attacks for 5 points!
Total damage = 5

The Human attacks for 16 points!
Total damage = 16

The Human attacks for 16 points!
Total damage = 16

The Human attacks for 1 points!
Total damage = 1

The Human attacks for 16 points!
Total damage = 16

The Human attacks for 13 points!
Total damage = 13

The Human attacks for 20 points!
Total damage = 20

The Human attacks for 13 points!
Total damage = 13

The Human attacks for 4 points!
Total damage = 4

The Human attacks for 3 points!
Total damage = 3


Examples of Elf damage:
The Elf attacks for 24 points!
Magical attack inflicts 24 additional damage points!
Total damage = 48

The Elf attacks for 37 points!
Total damage = 37

The Elf attacks for 25 points!
Magical attack inflicts 25 additional damage points!
Total damage = 50

The Elf attacks for 26 points!
Magical attack inflicts 26 additional damage points!
Total damage = 52

The Elf attacks for 20 points!
Total damage = 20

The Elf attacks for 12 points!
Total damage = 12

The Elf attacks for 39 points!
Total damage = 39

The Elf attacks for 26 points!
Magical attack inflicts 26 additional damage points!
Total damage = 52

The Elf attacks for 8 points!
Total damage = 8

The Elf attacks for 16 points!
Magical attack inflicts 16 additional damage points!
Total damage = 32


Examples of CyberDemon damage:
The CyberDemon attacks for 54 points!
Total damage = 54

The CyberDemon attacks for 49 points!
Total damage = 49

The CyberDemon attacks for 39 points!
Total damage = 39

The CyberDemon attacks for 21 points!
Demonic attack inflicts 50 additional damage points!
Total damage = 71

The CyberDemon attacks for 33 points!
Total damage = 33

The CyberDemon attacks for 27 points!
Total damage = 27

The CyberDemon attacks for 16 points!
Demonic attack inflicts 50 additional damage points!
Total damage = 66

The CyberDemon attacks for 23 points!
Total damage = 23

The CyberDemon attacks for 27 points!
Demonic attack inflicts 50 additional damage points!
Total damage = 77

The CyberDemon attacks for 59 points!
Total damage = 59


Examples of Balrog damage:
The Balrog attacks for 72 points!
Balrog speed attack inflicts 26 additional damage points!
Total damage = 98

The Balrog attacks for 59 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 9 additional damage points!
Total damage = 118

The Balrog attacks for 62 points!
Balrog speed attack inflicts 59 additional damage points!
Total damage = 121

The Balrog attacks for 36 points!
Balrog speed attack inflicts 22 additional damage points!
Total damage = 58

The Balrog attacks for 17 points!
Balrog speed attack inflicts 56 additional damage points!
Total damage = 73

The Balrog attacks for 25 points!
Balrog speed attack inflicts 55 additional damage points!
Total damage = 80

The Balrog attacks for 42 points!
Balrog speed attack inflicts 20 additional damage points!
Total damage = 62

The Balrog attacks for 40 points!
Balrog speed attack inflicts 52 additional damage points!
Total damage = 92

The Balrog attacks for 63 points!
Balrog speed attack inflicts 65 additional damage points!
Total damage = 128

The Balrog attacks for 31 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 48 additional damage points!
Total damage = 129


Press any key to continue . . .
*/
