/*
Joshua Barnard
CS 11 - Spring 2018
Assignment 10
sequence.cpp

*/


#include <stdio.h>
#include "sequence.h"
#include <cassert>

namespace cs_sequence 
{
    void sequence::copy( const sequence& inputData )
    {
		cursor = nullptr;
		preCursor = nullptr;
		numItems = inputData.numItems;

        if( inputData.headPtr == nullptr ) 
		{
            headPtr = nullptr;
            tailPtr = nullptr;
        } 
		else 
		{

            headPtr = new node;
            headPtr -> data = inputData.headPtr -> data;
            preCursor = nullptr;
            if( inputData.headPtr == inputData.cursor ) 
			{
                cursor = headPtr;
            } 
			else 
			{
                cursor = nullptr;
            }

            if( inputData.headPtr == inputData.preCursor )
			{
                preCursor = headPtr;
            }
            node* newList = headPtr;
            node* sourcePtr = inputData.headPtr -> next;

            while( sourcePtr != nullptr ) 
			{
                newList -> next = new node;
                if( sourcePtr == inputData.preCursor ) 
				{
                    preCursor = newList -> next;
                }
                newList = newList -> next;
                newList -> data = sourcePtr -> data;

                if( sourcePtr == inputData.cursor ) 
				{
                    cursor = newList;
                }
                sourcePtr = sourcePtr -> next;
            }

            tailPtr = newList;
            newList -> next = nullptr;
        }
        numItems = inputData.numItems;
      }





	void sequence::clear( )
    {

        node* deleteMe;
        while( headPtr != nullptr ) 
		{
            deleteMe = headPtr;
            headPtr = headPtr -> next;
            delete deleteMe;
        }
        numItems = 0;
    }



    
	
	sequence::sequence( )
    {
        numItems = 0;
        headPtr = nullptr;
        tailPtr = nullptr;
        cursor = nullptr;
        preCursor = nullptr;
    }





    sequence::sequence( const sequence& inputData )
    {
        copy( inputData );
    }





    sequence::~sequence( )
    {
        clear( );
    }
	
	
	
	
	
	sequence& sequence::operator=( const sequence& inputData )
    {
        if( this != &inputData ) 
		{
            clear( );
            copy( inputData );
        }
        return *this;
    }






    void sequence::start( )
    {
            cursor = headPtr;
            preCursor = NULL;
    }






    void sequence::advance( )
    {
        assert( is_item( ) );
        preCursor = cursor;
        cursor = cursor -> next;
		if( cursor == NULL )
		{
			preCursor = NULL;
		}
    }






    void sequence::insert( const value_type& entry ) 
	{
        numItems++;
        node* tempPtr = new node;
        tempPtr -> data = entry;

		if( cursor == nullptr || cursor == headPtr ) 
		{
            tempPtr -> next = headPtr;
            headPtr = tempPtr;
			if( numItems == 1 )
			{
				tailPtr = tempPtr;
			}
        } 
		else 
		{
            tempPtr -> next = cursor;
            preCursor -> next = tempPtr;
        }
        cursor = tempPtr;
    }






    void sequence::attach( const value_type& entry )
    {
        numItems++;
        node* tempPtr = new node;
        tempPtr -> data = entry;

        if( headPtr == NULL ) 
		{
            tempPtr -> next = NULL;
			headPtr = tempPtr;
			tailPtr = tempPtr;

        }
		else if( cursor == NULL || cursor == tailPtr ) 
		{
			tempPtr -> next = NULL;
			tailPtr -> next = tempPtr;
            preCursor = tailPtr;
			tailPtr = tempPtr;
        } 
		else 
		{
            tempPtr -> next = cursor -> next;
			cursor -> next = tempPtr;
			preCursor = cursor;
        }
        cursor = tempPtr;
    }






    void sequence::remove_current( )
    {
        assert( is_item(  ) );
        numItems--;

        if( tailPtr == headPtr )
		{
			delete headPtr;
			headPtr = NULL;
			tailPtr = NULL;
			cursor = NULL;
		}
		else if( cursor == headPtr )
		{
			headPtr = cursor -> next;
			delete cursor;
			cursor = headPtr;
		}
		else
		{
			node* tempPtr = cursor;
			preCursor -> next = cursor -> next;
			cursor = cursor -> next;
			if (cursor == NULL)
			{
				tailPtr = preCursor;
				preCursor = NULL;
			}
			delete tempPtr;
		}
    }






    sequence::size_type sequence::size( ) const
    {
        return numItems;
    }






    bool sequence::is_item( ) const
    {
        bool isItem;
        if( cursor != nullptr )
		{
            isItem = true;
        } 
		else 
		{
            isItem = false;
        }
        return isItem;
    }






    sequence::value_type sequence::current(  ) const
    {
        assert( is_item( ) );
        return cursor -> data;

    }
}


/*
Running tests for sequence Class with a linked sequence

START OF TEST 1:
Testing insert, attach, and the constant member functions (4 points).
Starting with an empty sequence.
Testing that size() returns 0 ... Passed.
Testing that is_item() returns false ... Passed.
I'll call start() and look at the items one more time...
All tests passed for this sequence.

I am now using attach to put 10 into an empty sequence.
Testing that size() returns 1 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

I am now using insert to put 10 into an empty sequence.
Testing that size() returns 1 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

I am now using attach to put 10,20,30 in an empty sequence.
Then I move the cursor to the start and insert 5.
Testing that size() returns 4 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

I am now using attach to put 10,20,30 in an empty sequence.
Then I move the cursor to the start, advance once, and insert 15.
Testing that size() returns 4 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [1] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

I am now using attach to put 10,20,30 in an empty sequence.
Then I move the cursor to the start and attach 15 after the 10.
Testing that size() returns 4 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [1] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

All tests of this first function have been passed.
Test 1 got 4 points out of a possible 4.
END OF TEST 1.

4

START OF TEST 2:
Testing situations where the cursor goes off the sequence (4 points).
Using attach to put 20 and 30 in the sequence, and then calling
advance, so that is_item should return false ... passed.
Inserting 10, which should go at the sequence's front.
Then calling advance three times to run cursor off the sequence ... passed.
Calling attach to put the numbers 40, 50, 60 ...300 at the sequence's end.
Now I will test that the sequence has 10, 20, 30, ...300.
All tests of this second function have been passed.
Test 2 got 4 points out of a possible 4.
END OF TEST 2.

8

START OF TEST 3:
Testing remove_current (4 points).
Using attach to build a sequence with 10,30.
Insert a 20 before the 30, so entire sequence is 10,20,30.
Testing that size() returns 3 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [1] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

Remove the 20, so entire sequence is now 10,30.
Testing that size() returns 2 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [1] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

Remove the 30, so entire sequence is now just 10 with no cursor.
Testing that size() returns 1 ... Passed.
Testing that is_item() returns false ... Passed.
I'll call start() and look at the items one more time...
All tests passed for this sequence.

Set the cursor to the start and remove the 10.
Testing that size() returns 0 ... Passed.
Testing that is_item() returns false ... Passed.
I'll call start() and look at the items one more time...
All tests passed for this sequence.

Using attach to build another sequence with 10,30.
Insert a 20 before the 30, so entire sequence is 10,20,30.
Testing that size() returns 3 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [1] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

Remove the 20, so entire sequence is now 10,30.
Testing that size() returns 2 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [1] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

Set the cursor to the start and remove the 10,
so the sequence should now contain just 30.
Testing that size() returns 1 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

Remove the 30 from the sequence, resulting in an empty sequence.
Testing that size() returns 0 ... Passed.
Testing that is_item() returns false ... Passed.
I'll call start() and look at the items one more time...
All tests passed for this sequence.

Build a new sequence by inserting 30, 10, 20 (so the sequence
is 20, then 10, then 30). Then remove the 20.
Testing that size() returns 2 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

Just for fun, I'll empty the sequence then fill it up, then
empty it again. During this process, I'll try to determine
whether any of the sequence's member functions access the
array outside of its legal indexes.
All tests of this third function have been passed.
Test 3 got 4 points out of a possible 4.
END OF TEST 3.

12

START OF TEST 4:
Testing the copy constructor (2 points).
Copy constructor test: for an empty sequence.
Testing that size() returns 0 ... Passed.
Testing that is_item() returns false ... Passed.
I'll call start() and look at the items one more time...
All tests passed for this sequence.

Copy constructor test: for a sequence with cursor at tail.
Testing that size() returns 60 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [59] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

Copy constructor test: with cursor near middle.
Testing that size() returns 59 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [30] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

Copy constructor test: for a sequence with cursor at front.
Testing that size() returns 59 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

Copy constructor test: for a sequence with no current item.
Testing that size() returns 59 ... Passed.
Testing that is_item() returns false ... Passed.
I'll call start() and look at the items one more time...
All tests passed for this sequence.

All tests of this fourth function have been passed.
Test 4 got 2 points out of a possible 2.
END OF TEST 4.

14

START OF TEST 5:
Testing the assignment operator (2 points).
Assignment operator test: for an empty sequence.
Testing that size() returns 0 ... Passed.
Testing that is_item() returns false ... Passed.
I'll call start() and look at the items one more time...
All tests passed for this sequence.

Assignment operator test: cursor at tail.
Testing that size() returns 60 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [59] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

Assignment operator test: with cursor near middle.
Testing that size() returns 59 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [30] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

Assignment operator test: with cursor at front.
Testing that size() returns 59 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

Assignment operator test: with no current item.
Testing that size() returns 59 ... Passed.
Testing that is_item() returns false ... Passed.
I'll call start() and look at the items one more time...
All tests passed for this sequence.

Checking correctness of a self-assignment x = x;
Testing that size() returns 59 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [1] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

All tests of this fifth function have been passed.
Test 5 got 2 points out of a possible 2.
END OF TEST 5.

16

START OF TEST 6:
Testing insert/attach for somewhat larger sequences (2 points).
Testing to see that attach works correctly when the
current capacity is exceeded.
Testing that size() returns 60 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [59] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

Testing to see that insert works correctly when the
current capacity is exceeded.
Testing that size() returns 60 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

All tests of this sixth function have been passed.
Test 6 got 2 points out of a possible 2.
END OF TEST 6.

18
If you submit this sequence to Dora now, you will have
18 points out of the 18 points from this test program.
Press any key to continue . . .
*/