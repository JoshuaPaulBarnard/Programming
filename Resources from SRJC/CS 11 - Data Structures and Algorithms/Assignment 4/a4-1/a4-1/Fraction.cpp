/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2017
Assignment 4 - 1
Fraction.cpp

Fractions Class file.
*/


#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include "Fraction.h"
using namespace std;

namespace cs_Fraction
{
	// This function receives a fraction consisting of seperate dividend and divisor integers.
	// This function will find their greatest common factor and reduce them to their lowest numbers.
	void Fraction::simplify()
	{
		int gcd = 1;
		int smallNumber, largeNumber, remainder1, remainder2;

		if ( divisor < 0 )
		{
			dividend = dividend * -1;
			divisor = divisor * -1;
		}

		if ( dividend == 0 )
		{
			divisor = 1;
		}

		if ( abs( dividend ) > abs( divisor) )
		{
			smallNumber = abs(divisor);
			largeNumber = abs(dividend);
		}
		else
		{
			smallNumber = abs(dividend);
			largeNumber = abs(divisor);
		}

		for ( int index = 1; index <= largeNumber; index++ )
		{
			remainder1 = smallNumber % index;
			remainder2 = largeNumber % index;

			if ( remainder1 == 0 && remainder2 == 0 )
			{
				gcd = index;
			}
		}

		dividend = dividend / gcd;
		divisor = divisor / gcd;
	}
	
	
	
	
	
	Fraction::Fraction( int getDividend, int getDivisor )
	{
		assert( getDivisor != 0 );

		dividend = getDividend;
		divisor = getDivisor;

		simplify();
	}





	std::ostream &operator<<( std::ostream &out, const Fraction &right )
	{		
		if( right.dividend == 0 )
		{
			out << 0;
		}
		else if( right.divisor == 1 )
		{
			out << right.dividend;
		}
		else if( abs( right.dividend ) == abs( right.divisor ) )
		{
			if( right.dividend < 0 || right.divisor < 0 )
			{
				out << -1;
			}
			else
			{
				out << 1;
			}
		}
		else if( abs( right.dividend ) > abs( right.divisor ) )
		{
			int integer = right.dividend / right.divisor;
			int remainder = right.dividend - (integer * right.divisor);
			
			if ( remainder == 0 )
			{
				out << integer;
			}
			else
			{
				out << integer << "+" << abs( remainder ) << "/" << abs( right.divisor );
			}
		}
		else
		{
			out << right.dividend << "/" << right.divisor;
		}


		return out;
	}





	std::istream &operator>>( std::istream &in, Fraction &right )
	{
		int temp1, temp2, temp3;

		in >> temp1;

		if ( in.peek() == '+' )
		{
			in.ignore();
			in >> temp2;
			in.ignore();
			in >> temp3;

			if ( temp1 < 0 )
			{
				right.dividend = -( abs( temp1 * temp3 ) + temp2 );
			}
			if ( temp1 > 0 )
			{
				right.dividend = ( temp1 * temp3 ) + temp2;
			}
			right.divisor = temp3;
			right.simplify();
		}
		else if ( in.peek() == '/' )
		{
			in.ignore();
			in >> temp2;
			right.dividend = temp1;
			right.divisor = temp2;
			right.simplify();

		}
		else
		{
			right.dividend = temp1;
			right.divisor = 1;
		}

		return in;
	}





	bool operator<( const Fraction& left, const Fraction& right )
	{
		bool status = false;
		if ( ( left.dividend * right.divisor ) < ( right.dividend * left.divisor ) )
		{
			status = true;
		}

		return status;
	}





	bool operator<=( const Fraction& left, const Fraction& right )
	{
		bool status = false;
		if ( ( left.dividend * right.divisor ) <= ( right.dividend * left.divisor ) )
		{
			status = true;
		}

		return status;
	}





	bool operator>( const Fraction& left, const Fraction& right )
	{
		bool status = false;
		if ( ( left.dividend * right.divisor ) > ( right.dividend * left.divisor ) )
		{
			status = true;
		}

		return status;
	}





	bool operator>=( const Fraction& left, const Fraction& right )
	{
		bool status = false;
		if ( ( left.dividend * right.divisor) >= ( right.dividend * left.divisor ) )
		{
			status = true;
		}

		return status;
	}





	bool operator==( const Fraction& left, const Fraction& right )
	{
		bool status = false;
		if ( ( left.dividend * right.divisor ) - ( right.dividend * left.divisor ) == 0 )
		{
			status = true;
		}

		return status;
	}





	bool operator!=( const Fraction& left, const Fraction& right )
	{
		bool status = false;
		if ( ( left.dividend * right.divisor ) - ( right.dividend * left.divisor ) != 0)
		{
			status = true;
		}

		return status;
	}





	Fraction operator+( const Fraction& left, const Fraction& right )
	{
		Fraction temp;
		if ( left.divisor == right.divisor )
		{
			temp.dividend = left.dividend + right.dividend;
			temp.divisor = left.divisor;
		}
		else
		{
			temp.dividend = ( left.dividend * right.divisor ) + ( right.dividend * left.divisor );
			temp.divisor = left.divisor * right.divisor;
		}

		temp.simplify();
		return temp;
	}





	Fraction operator-( const Fraction& left, const Fraction& right )
	{
		Fraction temp;
		if ( left.divisor == right.divisor )
		{
			temp.dividend = left.dividend - right.dividend;
			temp.divisor = left.divisor;
		}
		else
		{
			temp.dividend = ( left.dividend * right.divisor ) - ( right.dividend * left.divisor );
			temp.divisor = left.divisor * right.divisor;
		}

		temp.simplify();
		return temp;
	}





	Fraction operator*( const Fraction& left, const Fraction& right )
	{
		Fraction temp;

		temp.dividend = left.dividend * right.dividend;
		temp.divisor = left.divisor * right.divisor;

		temp.simplify();
		return temp;
	}





	Fraction operator/( const Fraction& left, const Fraction& right )
	{
		Fraction temp;

		temp.dividend = left.dividend * right.divisor;
		temp.divisor = left.divisor * right.dividend;

		temp.simplify();
		return temp;
	}





	Fraction Fraction::operator+=( const Fraction& right )
	{
		*this = *this + right;

		simplify();
		return *this;
	}





	Fraction Fraction::operator-=( const Fraction& right )
	{
		*this = *this - right;

		simplify();
		return *this;
	}





	Fraction Fraction::operator*=( const Fraction& right )
	{
		*this = *this * right;

		simplify();
		return *this;
	}





	Fraction Fraction::operator/=( const Fraction& right )
	{
		*this = *this / right;

		simplify();
		return *this;
	}





	Fraction Fraction::operator++()
	{
		dividend = dividend + divisor;

		return *this;
	}





	Fraction Fraction::operator++( int )
	{
		Fraction temp(dividend, divisor);
		dividend = dividend + divisor;

		return temp;
	}





	Fraction Fraction::operator--()
	{
		dividend = dividend - divisor;

		return *this;
	}





	Fraction Fraction::operator--( int )
	{
		Fraction temp(dividend, divisor);
		dividend = dividend - divisor;

		return temp;
	}

}

/*
----- Testing basic Fraction creation & printing
(Fractions should be in reduced form, and as mixed numbers.)
Fraction [0] = 1/2
Fraction [1] = -5/7
Fraction [2] = 10
Fraction [3] = -4
Fraction [4] = 0
Fraction [5] = 4+2/3
Fraction [6] = 0

----- Now reading Fractions from file
Read Fraction = 1/3
Read Fraction = 1/2
Read Fraction = 3/4
Read Fraction = -4/5
Read Fraction = 6
Read Fraction = 5
Read Fraction = -8
Read Fraction = 1+2/5
Read Fraction = -16+2/3
Read Fraction = 1+1/4
Read Fraction = 2
Read Fraction = -4+1/4
Read Fraction = -10+5/6

----- Testing relational operators between Fractions
Comparing 1/2 to 1/2
Is left < right? false
Is left <= right? true
Is left > right? false
Is left >= right? true
Does left == right? true
Does left != right ? false
Comparing 1/2 to -1/2
Is left < right? false
Is left <= right? false
Is left > right? true
Is left >= right? true
Does left == right? false
Does left != right ? true
Comparing -1/2 to 1/10
Is left < right? true
Is left <= right? true
Is left > right? false
Is left >= right? false
Does left == right? false
Does left != right ? true
Comparing 1/10 to 0
Is left < right? false
Is left <= right? false
Is left > right? true
Is left >= right? true
Does left == right? false
Does left != right ? true
Comparing 0 to 0
Is left < right? false
Is left <= right? true
Is left > right? false
Is left >= right? true
Does left == right? true
Does left != right ? false

----- Testing relations between Fractions and integers
Comparing -1/2 to 2
Is left < right? true
Is left <= right? true
Is left > right? false
Is left >= right? false
Does left == right? false
Does left != right ? true
Comparing -3 to 1/4
Is left < right? true
Is left <= right? true
Is left > right? false
Is left >= right? false
Does left == right? false
Does left != right ? true

----- Testing binary arithmetic between Fractions
1/6 + 1/3 = 1/2
1/6 - 1/3 = -1/6
1/6 * 1/3 = 1/18
1/6 / 1/3 = 1/2
1/3 + -2/3 = -1/3
1/3 - -2/3 = 1
1/3 * -2/3 = -2/9
1/3 / -2/3 = -1/2
-2/3 + 5 = 4+1/3
-2/3 - 5 = -5+2/3
-2/3 * 5 = -3+1/3
-2/3 / 5 = -2/15
5 + -1+1/3 = 3+2/3
5 - -1+1/3 = 6+1/3
5 * -1+1/3 = -6+2/3
5 / -1+1/3 = -3+3/4

----- Testing arithmetic between Fractions and integers
-1/2 + 4 = 3+1/2
-1/2 - 4 = -4+1/2
-1/2 * 4 = -2
-1/2 / 4 = -1/8
3 + -1/2 = 2+1/2
3 - -1/2 = 3+1/2
3 * -1/2 = -1+1/2
3 / -1/2 = -6

----- Testing shorthand arithmetic assignment on Fractions
1/6 += 4 = 4+1/6
4+1/6 -= 4 = 1/6
1/6 *= 4 = 2/3
2/3 /= 4 = 1/6
4 += -1/2 = 3+1/2
3+1/2 -= -1/2 = 4
4 *= -1/2 = -2
-2 /= -1/2 = 4
-1/2 += 5 = 4+1/2
4+1/2 -= 5 = -1/2
-1/2 *= 5 = -2+1/2
-2+1/2 /= 5 = -1/2

----- Testing shorthand arithmetic assignment using integers
-1/3 += 3 = 2+2/3
2+2/3 -= 3 = -1/3
-1/3 *= 3 = -1
-1 /= 3 = -1/3

----- Testing increment/decrement prefix and postfix
Now g = -1/3
g++ = -1/3
Now g = 2/3
++g = 1+2/3
Now g = 1+2/3
g-- = 1+2/3
Now g = 2/3
--g = -1/3
Now g = -1/3
Press any key to continue . . .
*/