/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2017
Assignment 4 - 1
Fraction.h

Fractions Class header file.

void simplify();
Precondition: This function expects two non-negative integers.
Postcondition: Finds the greatest common factor between the two integers and reduces
 them to their lowest common factor.
*/

#ifndef Fraction_h
#define Fraction_h

#include <iostream>
#include <fstream>

namespace cs_Fraction
{
	class Fraction
	{
	public:
		Fraction( int getDividend = 0, int getDivisor = 1 );

		friend std::ostream &operator<<( std::ostream &out, const Fraction &right );
		friend std::istream &operator<<( std::istream &in, const Fraction &right );

		friend Fraction operator+( const Fraction& left, const Fraction& right );
		friend Fraction operator-( const Fraction& left, const Fraction& right );
		friend Fraction operator*( const Fraction& left, const Fraction& right );
		friend Fraction operator/( const Fraction& left, const Fraction& right );

		friend bool operator<( const Fraction& left, const Fraction& right );
		friend bool operator<=( const Fraction& left, const Fraction& right );
		friend bool operator>( const Fraction& left, const Fraction& right );
		friend bool operator>=( const Fraction& left, const Fraction& right );
		friend bool operator==( const Fraction& left, const Fraction& right );
		friend bool operator!=( const Fraction& left, const Fraction& right );

		Fraction operator+=( const Fraction& right );
		Fraction operator-=( const Fraction& right );
		Fraction operator*=( const Fraction& right );
		Fraction operator/=( const Fraction& right );

		Fraction operator++();
		Fraction operator++(int);
		Fraction operator--();
		Fraction operator--(int);
		
	private:
		void simplify();
		int dividend;
		int divisor;
	};

}

#endif
