/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2017
Assignment 3 - 1
a3_1.cpp

This program has tests predefined mathematical equations using a new class called Fraction
*/

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class Fraction
{
public:
	Fraction( int getDividend = 0, int getDivisor = 1 );
	friend ostream& operator<<(std::ostream& out, const Fraction& right);
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
	Fraction operator+=( const Fraction& right );
	Fraction operator-=( const Fraction& right );
	Fraction operator*=( const Fraction& right );
	Fraction operator/=( const Fraction& right );
	Fraction operator++();
	Fraction operator++( int );
	Fraction operator--();
	Fraction operator--( int );
private:
	int dividend;
	int divisor;
};





Fraction::Fraction(int getDividend, int getDivisor)
{
	assert( getDivisor != 0 );

	dividend = getDividend;
	divisor = getDivisor;
}





ostream& operator<<( ostream& out, const Fraction& right )
{
	out << right.dividend << " / " << right.divisor;

	return out;
}





bool operator<( const Fraction& left, const Fraction& right )
{
	bool status;
	if ( ( left.dividend * right.divisor ) < ( right.dividend * left.divisor ) )
	{
		status = true;
	}
	else
	{
		status = false;
	}
	return status;
}





bool operator<=( const Fraction& left, const Fraction& right )
{
	bool status;
	if ( ( left.dividend * right.divisor ) <= ( right.dividend * left.divisor ) )
	{
		status = true;
	}
	else
	{
		status = false;
	}
	return status;
}





bool operator>( const Fraction& left, const Fraction& right )
{
	bool status;
	if ((left.dividend * right.divisor) > (right.dividend * left.divisor))
	{
		status = true;
	}
	else
	{
		status = false;
	}
	return status;
}





bool operator>=( const Fraction& left, const Fraction& right )
{
	bool status;
	if ((left.dividend * right.divisor) >= (right.dividend * left.divisor))
	{
		status = true;
	}
	else
	{
		status = false;
	}
	return status;
}





bool operator==( const Fraction& left, const Fraction& right )
{
	bool status;
	if ( ( left.dividend * right.divisor ) - ( right.dividend * left.divisor ) == 0 )
	{
		status = true;
	}
	else
	{
		status = false;
	}
	return status;
}





bool operator!=( const Fraction& left, const Fraction& right )
{
		bool status;
	if ( ( left.dividend * right.divisor ) - ( right.dividend * left.divisor ) != 0 )
	{
		status = true;
	}
	else
	{
		status = false;
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

	return temp;
}





Fraction operator-( const Fraction& left, const Fraction& right )
{
	Fraction temp;
	if (left.divisor == right.divisor)
	{
		temp.dividend = left.dividend - right.dividend;
		temp.divisor = left.divisor;
	}
	else
	{
		temp.dividend = (left.dividend * right.divisor) - (right.dividend * left.divisor);
		temp.divisor = left.divisor * right.divisor;
	}

	return temp;
}





Fraction operator*( const Fraction& left, const Fraction& right )
{
	Fraction temp;

	temp.dividend = left.dividend * right.dividend;
	temp.divisor = left.divisor * right.divisor;

	return temp;
}





Fraction operator/( const Fraction& left, const Fraction& right )
{
	Fraction temp;

	temp.dividend = left.dividend * right.divisor;
	temp.divisor = left.dividend * right.dividend;

	return temp;
}





Fraction Fraction::operator+=( const Fraction& right )
{
	*this = *this + right;

	return *this;
}





Fraction Fraction::operator-=( const Fraction& right )
{
	*this = *this - right;

	return *this;

}





Fraction Fraction::operator*=( const Fraction& right )
{
	*this = *this * right;

	return *this;

}





Fraction Fraction::operator/=( const Fraction& right )
{
	*this = *this / right;

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





Fraction Fraction::operator--(int)
{
	Fraction temp(dividend, divisor);
	dividend = dividend - divisor;

	return temp;
}





void BasicTest();
void RelationTest();
void BinaryMathTest();
void MathAssignTest();
string boolString(bool convertMe);

int main()
{
	BasicTest();
	RelationTest();
	BinaryMathTest();
	MathAssignTest();
}





void BasicTest()
{
	cout << "\n----- Testing basic Fraction creation & printing\n";

	const Fraction fr[] = { Fraction(4, 8), Fraction(-15,21),
		Fraction(10), Fraction(12, -3),
		Fraction(), Fraction(28, 6), Fraction(0, 12) };

	for (int i = 0; i < 7; i++) {
		cout << "Fraction [" << i << "] = " << fr[i] << endl;
	}
}





string boolString(bool convertMe) {
	if (convertMe) {
		return "true";
	}
	else {
		return "false";
	}
}


void RelationTest()
{
	cout << "\n----- Testing relational operators between Fractions\n";

	const Fraction fr[] = { Fraction(3, 6), Fraction(1,2), Fraction(-15,30),
		Fraction(1,10), Fraction(0,1), Fraction(0,2) };

	for (int i = 0; i < 5; i++) {
		cout << "Comparing " << fr[i] << " to " << fr[i + 1] << endl;
		cout << "\tIs left < right? " << boolString(fr[i] < fr[i + 1]) << endl;
		cout << "\tIs left <= right? " << boolString(fr[i] <= fr[i + 1]) << endl;
		cout << "\tIs left > right? " << boolString(fr[i] > fr[i + 1]) << endl;
		cout << "\tIs left >= right? " << boolString(fr[i] >= fr[i + 1]) << endl;
		cout << "\tDoes left == right? " << boolString(fr[i] == fr[i + 1]) << endl;
		cout << "\tDoes left != right ? " << boolString(fr[i] != fr[i + 1]) << endl;
	}

	cout << "\n----- Testing relations between Fractions and integers\n";
	Fraction f(-3, 6);
	int num = 2;
	cout << "Comparing " << f << " to " << num << endl;
	cout << "\tIs left < right? " << boolString(f < num) << endl;
	cout << "\tIs left <= right? " << boolString(f <= num) << endl;
	cout << "\tIs left > right? " << boolString(f > num) << endl;
	cout << "\tIs left >= right? " << boolString(f >= num) << endl;
	cout << "\tDoes left == right? " << boolString(f == num) << endl;
	cout << "\tDoes left != right ? " << boolString(f != num) << endl;

	Fraction g(1, 4);
	num = -3;
	cout << "Comparing " << num << " to " << g << endl;
	cout << "\tIs left < right? " << boolString(num < g) << endl;
	cout << "\tIs left <= right? " << boolString(num <= g) << endl;
	cout << "\tIs left > right? " << boolString(num > g) << endl;
	cout << "\tIs left >= right? " << boolString(num >= g) << endl;
	cout << "\tDoes left == right? " << boolString(num == g) << endl;
	cout << "\tDoes left != right ? " << boolString(num != g) << endl;
}





void BinaryMathTest()
{
	cout << "\n----- Testing binary arithmetic between Fractions\n";

	const Fraction fr[] = { Fraction(1, 6), Fraction(1,3),
		Fraction(-2,3), Fraction(5), Fraction(-4,3) };

	for (int i = 0; i < 4; i++) {
		cout << fr[i] << " + " << fr[i + 1] << " = " << fr[i] + fr[i + 1] << endl;
		cout << fr[i] << " - " << fr[i + 1] << " = " << fr[i] - fr[i + 1] << endl;
		cout << fr[i] << " * " << fr[i + 1] << " = " << fr[i] * fr[i + 1] << endl;
		cout << fr[i] << " / " << fr[i + 1] << " = " << fr[i] / fr[i + 1] << endl;
	}

	cout << "\n----- Testing arithmetic between Fractions and integers\n";
	Fraction f(-1, 2);
	int num = 4;
	cout << f << " + " << num << " = " << f + num << endl;
	cout << f << " - " << num << " = " << f - num << endl;
	cout << f << " * " << num << " = " << f * num << endl;
	cout << f << " / " << num << " = " << f / num << endl;

	Fraction g(-1, 2);
	num = 3;
	cout << num << " + " << g << " = " << num + g << endl;
	cout << num << " - " << g << " = " << num - g << endl;
	cout << num << " * " << g << " = " << num * g << endl;
	cout << num << " / " << g << " = " << num / g << endl;
}






void MathAssignTest()
{
	cout << "\n----- Testing shorthand arithmetic assignment on Fractions\n";

	Fraction fr[] = { Fraction(1, 6), Fraction(4),
		Fraction(-1,2), Fraction(5) };

	for (int i = 0; i < 3; i++) {
		cout << fr[i] << " += " << fr[i + 1] << " = ";
		cout << (fr[i] += fr[i + 1]) << endl;
		cout << fr[i] << " -= " << fr[i + 1] << " = ";
		cout << (fr[i] -= fr[i + 1]) << endl;
		cout << fr[i] << " *= " << fr[i + 1] << " = ";
		cout << (fr[i] *= fr[i + 1]) << endl;
		cout << fr[i] << " /= " << fr[i + 1] << " = ";
		cout << (fr[i] /= fr[i + 1]) << endl;
	}

	cout << "\n----- Testing shorthand arithmetic assignment using integers\n";
	Fraction f(-1, 3);
	int num = 3;
	cout << f << " += " << num << " = ";
	cout << (f += num) << endl;
	cout << f << " -= " << num << " = ";
	cout << (f -= num) << endl;
	cout << f << " *= " << num << " = ";
	cout << (f *= num) << endl;
	cout << f << " /= " << num << " = ";
	cout << (f /= num) << endl;

	cout << "\n----- Testing increment/decrement prefix and postfix\n";
	Fraction g(-1, 3);
	cout << "Now g = " << g << endl;
	cout << "g++ = " << g++ << endl;
	cout << "Now g = " << g << endl;
	cout << "++g = " << ++g << endl;
	cout << "Now g = " << g << endl;
	cout << "g-- = " << g-- << endl;
	cout << "Now g = " << g << endl;
	cout << "--g = " << --g << endl;
	cout << "Now g = " << g << endl;
}


/*
----- Testing basic Fraction creation & printing
Fraction [0] = 4 / 8
Fraction [1] = -15 / 21
Fraction [2] = 10 / 1
Fraction [3] = 12 / -3
Fraction [4] = 0 / 1
Fraction [5] = 28 / 6
Fraction [6] = 0 / 12

----- Testing relational operators between Fractions
Comparing 3 / 6 to 1 / 2
Is left < right? false
Is left <= right? true
Is left > right? false
Is left >= right? true
Does left == right? true
Does left != right ? false
Comparing 1 / 2 to -15 / 30
Is left < right? false
Is left <= right? false
Is left > right? true
Is left >= right? true
Does left == right? false
Does left != right ? true
Comparing -15 / 30 to 1 / 10
Is left < right? true
Is left <= right? true
Is left > right? false
Is left >= right? false
Does left == right? false
Does left != right ? true
Comparing 1 / 10 to 0 / 1
Is left < right? false
Is left <= right? false
Is left > right? true
Is left >= right? true
Does left == right? false
Does left != right ? true
Comparing 0 / 1 to 0 / 2
Is left < right? false
Is left <= right? true
Is left > right? false
Is left >= right? true
Does left == right? true
Does left != right ? false

----- Testing relations between Fractions and integers
Comparing -3 / 6 to 2
Is left < right? true
Is left <= right? true
Is left > right? false
Is left >= right? false
Does left == right? false
Does left != right ? true
Comparing -3 to 1 / 4
Is left < right? true
Is left <= right? true
Is left > right? false
Is left >= right? false
Does left == right? false
Does left != right ? true

----- Testing binary arithmetic between Fractions
1 / 6 + 1 / 3 = 9 / 18
1 / 6 - 1 / 3 = -3 / 18
1 / 6 * 1 / 3 = 1 / 18
1 / 6 / 1 / 3 = 3 / 1
1 / 3 + -2 / 3 = -1 / 3
1 / 3 - -2 / 3 = 3 / 3
1 / 3 * -2 / 3 = -2 / 9
1 / 3 / -2 / 3 = 3 / -2
-2 / 3 + 5 / 1 = 13 / 3
-2 / 3 - 5 / 1 = -17 / 3
-2 / 3 * 5 / 1 = -10 / 3
-2 / 3 / 5 / 1 = -2 / -10
5 / 1 + -4 / 3 = 11 / 3
5 / 1 - -4 / 3 = 19 / 3
5 / 1 * -4 / 3 = -20 / 3
5 / 1 / -4 / 3 = 15 / -20

----- Testing arithmetic between Fractions and integers
-1 / 2 + 4 = 7 / 2
-1 / 2 - 4 = -9 / 2
-1 / 2 * 4 = -4 / 2
-1 / 2 / 4 = -1 / -4
3 + -1 / 2 = 5 / 2
3 - -1 / 2 = 7 / 2
3 * -1 / 2 = -3 / 2
3 / -1 / 2 = 6 / -3

----- Testing shorthand arithmetic assignment on Fractions
1 / 6 += 4 / 1 = 25 / 6
25 / 6 -= 4 / 1 = 1 / 6
1 / 6 *= 4 / 1 = 4 / 6
4 / 6 /= 4 / 1 = 4 / 16
4 / 1 += -1 / 2 = 7 / 2
7 / 2 -= -1 / 2 = 8 / 2
8 / 2 *= -1 / 2 = -8 / 4
-8 / 4 /= -1 / 2 = -16 / 8
-1 / 2 += 5 / 1 = 9 / 2
9 / 2 -= 5 / 1 = -1 / 2
-1 / 2 *= 5 / 1 = -5 / 2
-5 / 2 /= 5 / 1 = -5 / -25

----- Testing shorthand arithmetic assignment using integers
-1 / 3 += 3 = 8 / 3
8 / 3 -= 3 = -1 / 3
-1 / 3 *= 3 = -3 / 3
-3 / 3 /= 3 = -3 / -9

----- Testing increment/decrement prefix and postfix
Now g = -1 / 3
g++ = -1 / 3
Now g = 2 / 3
++g = 5 / 3
Now g = 5 / 3
g-- = 5 / 3
Now g = 2 / 3
--g = -1 / 3
Now g = -1 / 3
Press any key to continue . . .
*/
