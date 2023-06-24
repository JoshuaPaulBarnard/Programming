//Patrick Panelli
//factor_righttriangle.cpp
//Write a program that inputs 3 ints, the largest one last (just input that way)...
//For each int it calls a function tha finds and prints its factors {Process 3 #'s, one at a time}
//Then all 3 ints are passed into another function, that determines if they represent a right triangle, & prints a yes/no type answer.
//Main Program-does input only----Both functions-void functions, both don't pass, they print
//Loop for 4 sets of data (for loop)
//Call it 3 times and pass a, call it and pass b, call it and pass c,
//then second function-pass all 3 vars at a time
//Use 3,4,5--10,14,21--10,24,26--8,15,17

#include <iostream>
using namespace std;

void factor(int value)
{
	int n;
	cout << "The factors of " << " " << value << " are";
	for (n=1; n <= value  ;n++)
	{
		if (value % n == 0)
		{
			cout << " " << n;
		}
	}
}

char righttriangle(int a, int b, int c)
{
	int assessleft, assessright;
	char answer;
	answer = 'n';
	assessleft=c * c;
	assessright= (a * a) + (b * b);
	cout << endl << "Am I a right triangle?" << a << " " << b << " " << c;
	if (assessleft == assessright)
		cout << '\n' << 'y';
	else
		cout << '\n' << 'n';
	return (answer);
}


int main ()
{
	int first, second, third;
	char more, answer;
	first = 0;
	second = 0;
	third = 0;
	more = 'y';
	answer = 'x';
	while (more == 'y')
			{
			cout << "Please enter three positive integers, one at a time with the largest last\n";
			cin >> first >> second >> third;
			factor(first);
			factor(second);
			factor(third);
			answer = righttriangle(first,second,third);
			cout << '\n' <<  "Would you like to enter more positive integers?\n";
			cin >> more;
			}
	return 0;
}
