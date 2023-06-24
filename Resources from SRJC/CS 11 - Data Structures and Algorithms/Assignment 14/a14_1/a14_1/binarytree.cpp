/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2018
Assignment 14 - 1
binarytree.cpp

*/


#include <iostream>
#include "binarytree.h"
using namespace std;





binarytree::binarytree() 
{
	root = nullptr;
	mSize = 0;
}





void binarytree::clear( treenode*& root )
{
	if( root != NULL )
	{
		clear( root -> right );
		clear( root -> left );

		delete root;
		root = NULL;
	}
}






void binarytree::copy(treenode*& tempVar, const treenode* originalData)
{
	if (originalData == NULL)
	{
		tempVar = NULL;
	}
	else
	{
		tempVar = new treenode;
		tempVar->data = originalData->data;

		copy(tempVar->right, originalData->right);
		copy(tempVar->left, originalData->left);
	}
}





binarytree::~binarytree(  )
{
	clear( root );
}





binarytree::binarytree( const binarytree& copyData )
{
	copy( root, copyData.root );
	mSize = copyData.mSize;
}






binarytree binarytree::operator=( const binarytree& copyData )
{
	if( this != &copyData )
	{
		clear( root );
		copy( root, copyData.root );
		mSize = copyData.mSize;
	}

	return *this;
}





void binarytree::print() const {
	print_aux(root);
}


void binarytree::insert(int item) {
	insert_aux(root, item);
	++mSize;
}


binarytree::size_type binarytree::size() const {
	return mSize;
}


int binarytree::find(int target, bool& found) const {
	return find_aux(root, target, found);
}


void binarytree::del(int target, bool& found) {
	del_aux(root, target, found);
	if( found == true )
	{
		--mSize;
	}
}


void binarytree::del_aux(binarytree::treenode*& root,
	int target,
	bool& found) {

	if (root == nullptr) {
		found = false;
	}
	else if (target < root->data) {
		del_aux(root->left, target, found);
	}
	else if (target > root->data) {
		del_aux(root->right, target, found);
	}
	else if (root->left == nullptr) {
		binarytree::treenode* tempptr = root;
		root = root->right;
		delete tempptr;
		found = true;
	}
	else {
		int max;
		remove_max(root->left, max);
		root->data = max;
		found = true;
	}
}

// pre: root != nullptr

void binarytree::remove_max(binarytree::treenode*& root, int& max) {
	if (root->right == nullptr) {
		max = root->data;
		binarytree::treenode* tempptr = root;
		root = root->left;
		delete tempptr;
	}
	else {
		remove_max(root->right, max);
	}
}



int binarytree::find_aux(const treenode* root,
	int target,
	bool& found) {

	if (root == nullptr) {
		found = false;
		return 0;
	}
	else if (target == root->data) {
		found = true;
		return root->data;
	}
	else if (target < root->data) {
		return find_aux(root->left, target, found);
	}
	else {
		return find_aux(root->right, target, found);
	}
}


binarytree::size_type binarytree::size_aux(const treenode* root) {
	if (root == nullptr) {
		return 0;
	}
	else {
		return size_aux(root->left)
			+ size_aux(root->right)
			+ 1;
	}
}


void binarytree::insert_aux(treenode*& root, int item) {
	if (root == nullptr) {
		root = new binarytree::treenode;
		root->data = item;
		root->left = nullptr;
		root->right = nullptr;
	}
	else if (item <= root->data) {
		insert_aux(root->left, item);
	}
	else {
		insert_aux(root->right, item);
	}
}


void binarytree::print_aux(const treenode* root) {
	if (root != nullptr) {
		print_aux(root->left);
		cout << root->data << " ";
		print_aux(root->right);
	}
}





bool isPrimeNumber( int aInteger );


bool isPrimeNumber( int incomingInteger )
{
	if ( 
		( !( incomingInteger & 1 ) 
		&& incomingInteger != 2 ) 
		|| ( incomingInteger < 2 ) 
		|| ( incomingInteger % 3 == 0 && incomingInteger != 3 ) 
		)
	{
		return false;
	}

	for ( int index = 1; 36 * index*index - 12 * index < incomingInteger; ++index )
	{
		if( ( incomingInteger % ( 6 * index + 1 ) == 0 ) 
			|| ( incomingInteger % ( 6 * index - 1 ) == 0 )  
		)
		{
			return false;
		}
	}

	return true;
}





int binarytree::numPrimes() const
{
	return numPrimes_aux( root );
}





int binarytree::numPrimes_aux( const binarytree::treenode* incomingPointer )
{
	if( incomingPointer == NULL )
	{
		return 0;
	}

	if ( isPrimeNumber( incomingPointer -> data ) == true )
	{
		return
			(
				numPrimes_aux( incomingPointer -> left )
				+ numPrimes_aux( incomingPointer -> right )
				+ 1
			);
	}
	else
	{
		return
			(
				numPrimes_aux( incomingPointer -> left )
				+ numPrimes_aux( incomingPointer -> right )
			);
	}
}






LL<int> binarytree::toLL() const
{
	LL<int> returnLinkedList;
	toLL_aux( returnLinkedList, root );

	return returnLinkedList;
}





void binarytree::toLL_aux(LL<int> &linkedList, const binarytree::treenode* incomingPointer)
{
	if( incomingPointer != nullptr )
	{
		toLL_aux( linkedList, incomingPointer -> right );
		linkedList.push_front( incomingPointer -> data );
		toLL_aux( linkedList, incomingPointer -> left );
	}
}

/*
The binary tree: 0 5 8 11 12 14 17 19 24 27 27 28 31 34 36 41 41 42 45 45
The linked list: 0 5 8 11 12 14 17 19 24 27 27 28 31 34 36 41 41 42 45 45
The original binary tree still intact: 0 5 8 11 12 14 17 19 24 27 27 28 31 34 36 41 41 42 45 45

This program will test a linked List.
Entering a negative integer will end the current phase, and start the next step in the program.
Please Enter a Integer to add to a link list to test: 1
Please enter another Integer to insert (-# to end): 2
Please enter another Integer to insert (-# to end): 4
Please enter another Integer to insert (-# to end): 7
Please enter another Integer to insert (-# to end): 8
Please enter another Integer to insert (-# to end): -0
Please enter another Integer to insert (-# to end): -1
0 1 2 4 7 8
There are 6 items.
There are 2 prime numbers.
enter a number to find (-# to end): 0
found.  The data is 0
enter a number to find (-# to end): -1
enter a number to delete (-# to end): 1
the list is now 0 2 4 7 8
enter a number to delete (-# to end): -1
Now list 2 should be a copy of list.  Here it is: 0 2 4 7 8
After deleting a 3 from list2, list2 is now: 0 2 4 7 8
list should be unchanged.  Here it is: 0 2 4 7 8
Now list has been assigned list2 so it should match list2.  Here it is: 0 2 4 7 8
After deleting a 4 from list, list is now: 0 2 7 8
list2 should be unchanged.  Here it is: 0 2 4 7 8
There is now 2 prime numbers.
Press any key to continue . . .
*/