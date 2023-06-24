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



The class Fraction's purpose is to do logical and mathematical operations on fractions.
Fractions can read in whole numbers, mixed numbers, and fractions from a file through overloaded
 operators, and reduces the fractions.
The following operators have been overloaded:
iostream operators:  '<<, >>'.
mathematical operators: '+,-,*,/'.
incrementation/decrementation operators: '+=, -=, *=, /=, ++, ++(int), --, --(int)'.
logical equality operators: '<, >, <=, >=, ==, !='.

Fraction (int getDividend = 0, int getDivisor = 1);
post: fraction is initialized with a default values of 0 for dividend, and 1 for divisor.

friend std::ostream &operator<<( std::ostream &out, const Fraction &right );
pre: Cout works only with build in types.
post: Cout works with type Fraction and displays them as either whole numbers, mixed numbers, or fractions.

friend std::istream &operator>>( std::istream &in, Fraction &right );
pre: The Insertion operator only works with build in types.
post: The Insertion operator works with type Fraction, and read in either whole numbers, mixed numbers, or fractions 
 and turns them into a simplified fraction.

friend Fraction operator+( const Fraction& left, const Fraction& right );
post: The Fractions on the left and right of the + operator are added together and the result is simplified.

friend Fraction operator-( const Fraction& left, const Fraction& right );
post: The Fractions on the left and right of the - operator are subtracted from one another, and the result is simplified.

friend Fraction operator*( const Fraction& left, const Fraction& right );
post: The Fractions on the left and right of the * operator are multiplied together, and the result is simplified.

friend Fraction operator/( const Fraction& left, const Fraction& right );
post: The Fraction on the left of the / operator is divided by the fraction on the right, and the result is simplified.

friend bool operator<( const Fraction& left, const Fraction& right );
post: The Fraction on the left of the < is compared to the fraction on the right, if the left is less than the right
 then true is returned, otherwise false is returned.

friend bool operator>( const Fraction& left, const Fraction& right );
post: The Fraction on the left of the < is compared to the fraction on the right, if the left is less than the right
 then false is returned, otherwise true is returned.

friend bool operator<=( const Fraction& left, const Fraction& right );
post: The Fraction on the left of the <= is compared to the fraction on the right, if the left is less than or equal to
 the right then true is returned, otherwise false is returned.

friend bool operator>=( const Fraction& left, const Fraction& right );
post: The Fraction on the left of the <= is compared to the fraction on the right, if the left is less than or equal to
 the right then false is returned, otherwise true is returned.

friend bool operator==( const Fraction& left, const Fraction& right );
post: The Fraction on the left of the == is compared to the fraction on the right, if the left is equal to
 the right then true is returned, otherwise false is returned.

friend bool operator!=( const Fraction& left, const Fraction& right );
post: The Fraction on the left of the != is compared to the fraction on the right, if the left is not equal to
 the right then true is returned, otherwise false is returned.

Fraction operator+=( const Fraction& right );
post: The right operand is added to the left operand, then the value of the left operand is returned.

Fraction operator-=( const Fraction& right );
post: The right operand is subtracted by the left operand, then the value of the left operand is returned.

Fraction operator*=( const Fraction& right );
post: The right operand is multiplied by the left operand, then the value of the left operand is returned.

Fraction operator/=( const Fraction& right );
post:The right operand is divided by the left operand, then the value of the left operand is returned.

Fraction operator++();
post: The Operand is incremented by 1.

Fraction operator++(int);
pre: The value is evaluated and stored in temp.
post: The Operand is incremented by then the stored temp value is returned.

Fraction operator--();

post: The Operand is decremented by 1.

Fraction operator--(int);

pre: The value is evaluated and stored in temp.
post: The Operand is decremented by 1, then the stored temp value is returned.
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
		friend std::istream &operator>>( std::istream &in, Fraction &right );

		friend Fraction operator+(const Fraction& left, const Fraction& right);
		friend Fraction operator-(const Fraction& left, const Fraction& right);
		friend Fraction operator*(const Fraction& left, const Fraction& right);
		friend Fraction operator/(const Fraction& left, const Fraction& right);

		friend bool operator<(const Fraction& left, const Fraction& right);
		friend bool operator<=(const Fraction& left, const Fraction& right);
		friend bool operator>(const Fraction& left, const Fraction& right);
		friend bool operator>=(const Fraction& left, const Fraction& right);
		friend bool operator==(const Fraction& left, const Fraction& right);
		friend bool operator!=(const Fraction& left, const Fraction& right);

		Fraction operator+=(const Fraction& right);
		Fraction operator-=(const Fraction& right);
		Fraction operator*=(const Fraction& right);
		Fraction operator/=(const Fraction& right);

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
