/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2018
Assignment 2 - 1
a2_1.cpp

This program contains 6 functions, 3 of which return integers, 1 returns true/false, and 3 which
modify a character array passed into them.  
A menu prompts the user which function to use.  The user will then input 1 - 3 character arrays
depending on the function.
In the end, the invoked function will return a value, which the main program will use to output
the results from the function.
*/

#include "stdafx.h"
#include <iomanip>
#include <iostream>

using namespace std;

int lastIndexOf( const char* inString, char target );
void reverse( char* inString );
int replace( char* inString, char target, char replacementChar );
bool isPalindrome( const char* inString );
void toupper( char* inString );
int numLetters( const char* inString );


int lastIndexOf( const char* inString, char target )
{
	int i = 0;
	int index = -1;
	while ( inString[i] != '\0' )
	{
		if ( inString[i] == target )
		{
			index = i + 1;
		}
		i++;
	}

	if (index > 0)
	{
		return index;
	}
	else
	{
		return -1;
	}

}

void reverse( char* inString )
{
	int i = 0;
	int length = strlen( inString );

	while  (i < (length / 2) )
	{
		swap(inString[i], inString[length - 1 - i]);
		i++;
	}
}

int replace( char* inString, char target, char replacementChar )
{
	int i = 0;
	int tracker = 0;

	while( inString[i] != '\0' )
	{
		if( inString[i] == target )
		{
			++tracker;
			inString[i] = replacementChar;
		}
		i++;
	}

	return tracker;
}

bool isPalindrome( const char* inString )
{
	int indexForward = 0;
	int indexBackward = strlen( inString ) - 1;

	if ( indexBackward == 1 )
	{
		return true;
	}
	if( indexBackward < 1 )
	{
		return false;
	}

	for( indexForward = 0; indexForward < indexBackward; indexForward++, indexBackward-- )
	{
		if( tolower( inString[ indexForward ] ) != tolower( inString[ indexBackward ] ) )
		{
			return false;
		}

		return true;
	}

}

void toupper( char* inString )
{
	int i = 0;
	int array[25];

	// Initialize array with lowercase letters
	for ( int i = 0; i < 25; i++ )
	{
		array[i] = static_cast<char>( i + 97 );
	}

	// Replace lowercase letters with their uppercase counterparts
	while ( inString[i] != '\0' )
	{
		if ( ( inString[i] >= 97 ) && ( inString[i] <= 122 ) )
		{
			inString[i] &= 0xdf;
		}
		i++;
	}
}

int numLetters( const char* inString )
{
	int i = 0;
	int counter = 0;


	while( inString[i] != '\0' )
	{
		if( isalpha( inString[i] ) > 0 )
		{
			counter++;
		}

		i++;
	}
	return counter;

}

int main()
{
	char* inString;
	int inputOption;
	char userInput[1000];
	int index = 0;
	char target;
	char replacementChar;
	int temp = -1;

	cout << "Which function would you like to use?" << endl;
	cout << "1. Find the last index of a character in a statement." << endl;
	cout << "2. Reverse any given word." << endl;
	cout << "3. Replace every instance of a character with a new target character." << endl;
	cout << "4. Check to see if a statement is a palindrome." << endl;
	cout << "5. Convert a statement to all capital letters." << endl;
	cout << "6. Checks the numbers of letters in a statement." << endl << endl;
	cin >> inputOption;


	switch ( inputOption )
	{
	case 1:
		cout << endl << "Please enter a statement." << endl;
		cin >> userInput;
		cout << "Please enter a letter to find." << endl;
		cin >> target;

		inString = userInput;
		temp = lastIndexOf(userInput, target);
		cout << endl << "The last index of " << target << " in this statement is: " << temp << endl;
		break;

	case 2:
		cout << "Please enter a statement to reverse." << endl;
		cin >> userInput;

		inString = userInput;
		reverse(inString);
		cout << endl << "desreveR si: " << inString << endl;
		break;

	case 3:
		cout << "Please enter a statement." << endl;
		cin >> userInput;
		cout << "Please enter the target character to replace." << endl;
		cin >> target;
		cout << "Please enter the character to replace all target characters with." << endl;
		cin >> replacementChar;

		inString = userInput;
		temp = replace(userInput, target, replacementChar);
		cout << endl << "The New Statement is: " << inString << endl;
		cout << "The letter " << target << " was replaced by " << replacementChar << ", " << temp << " times." << endl;
		break;

	case 4:
		cout << "Please enter a statement to be checked for Palindromicity." << endl;
		cin >> userInput;
		inString = userInput;

		if (isPalindrome(inString) == true)
		{
			cout << endl << "This statement is indeed a Palindrome!" << endl;
		}
		else
		{
			cout << endl << "I am sorry, but this statement is not not a palindrome" << endl;
		}
		break;

	case 5:
		cout << "Please enter a statement to convert to all uppercase letters." << endl;
		cin >> userInput;
		inString = userInput;

		toupper(inString);
		cout << "Your statement is now:" << endl;
		cout << inString << endl;
		break;

	case 6:
		cout << endl << "Please enter the statement to check." << endl;
		cin >> userInput;
		inString = userInput;

		temp = numLetters(inString);
		cout << endl << "There are " << temp << " letters in this statement." << endl;
		break;
	}

	return 0;
}

/*
Which function would you like to use?
1. Find the last index of a character in a statement.
2. Reverse any given word.
3. Replace every instance of a character with a new target character.
4. Check to see if a statement is a palindrome.
5. Convert a statement to all capital letters.
6. Checks the numbers of letters in a statement.

1

Please enter a statement.
saskatchewan
Please enter a letter to find.
w

The last index of w in this statement is: 10

---------------------------------------------------------------------------------------------------------------

Which function would you like to use?
1. Find the last index of a character in a statement.
2. Reverse any given word.
3. Replace every instance of a character with a new target character.
4. Check to see if a statement is a palindrome.
5. Convert a statement to all capital letters.
6. Checks the numbers of letters in a statement.

2
Please enter a statement to reverse.
Mississippi

desreveR si: ippississiM

---------------------------------------------------------------------------------------------------------------

Which function would you like to use?
1. Find the last index of a character in a statement.
2. Reverse any given word.
3. Replace every instance of a character with a new target character.
4. Check to see if a statement is a palindrome.
5. Convert a statement to all capital letters.
6. Checks the numbers of letters in a statement.

3
Please enter a statement.
Antidisestablishmentarianism
Please enter the target character to replace.
i
Please enter the character to replace all target characters with.
q

The New Statement is: Antqdqsestablqshmentarqanqsm
The letter i was replaced by q, 5 times.

----------------------------------------------------------------------------------------------------------------

Which function would you like to use?
1. Find the last index of a character in a statement.
2. Reverse any given word.
3. Replace every instance of a character with a new target character.
4. Check to see if a statement is a palindrome.
5. Convert a statement to all capital letters.
6. Checks the numbers of letters in a statement.

4
Please enter a statement to be checked for Palindromicity.
What does Palindromicity even mean?

I am sorry, but this statement is not not a palindrome
______________________________________________________________________
Which function would you like to use?
1. Find the last index of a character in a statement.
2. Reverse any given word.
3. Replace every instance of a character with a new target character.
4. Check to see if a statement is a palindrome.
5. Convert a statement to all capital letters.
6. Checks the numbers of letters in a statement.

4
Please enter a statement to be checked for Palindromicity.
Palindrome|emordnilaP

This statement is indeed a Palindrome!

---------------------------------------------------------------------------------------------------------------

Which function would you like to use?
1. Find the last index of a character in a statement.
2. Reverse any given word.
3. Replace every instance of a character with a new target character.
4. Check to see if a statement is a palindrome.
5. Convert a statement to all capital letters.
6. Checks the numbers of letters in a statement.

5
Please enter a statement to convert to all uppercase letters.
supercalifragilisticexpialidocious
Your statement is now:
SUPERCALIFRAGILISTICEXPIALIDOCIOUS

----------------------------------------------------------------------------------------------------------------

Which function would you like to use?
1. Find the last index of a character in a statement.
2. Reverse any given word.
3. Replace every instance of a character with a new target character.
4. Check to see if a statement is a palindrome.
5. Convert a statement to all capital letters.
6. Checks the numbers of letters in a statement.

6

Please enter the statement to check.
aW26.!lo]P

There are 5 letters in this statement.
*/