/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2018
Assignment 13 - 1
binarytree.cpp

*/


#include <iostream>
#include "binarytree.h"
using namespace std;

	
bool isPrimeNumber( int num );

binarytree::binarytree() 
{
	root = nullptr;
	mSize = 0;
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

int binarytree::numPrimes() const
{
	return numPrimes_aux( root );
}

int binarytree::numPrimes_aux( const binarytree::treenode* rootptr )
{
	if( rootptr == NULL )
	{
		return 0;
	}
	else if( isPrimeNumber ( rootptr -> data ) )
	{
		return 
			(
				numPrimes_aux( rootptr -> left )
				+ numPrimes_aux( rootptr ->right )
				+1
			);
	}
	else
	{
		return
			(
				numPrimes_aux( rootptr->left )
				+ numPrimes_aux( rootptr->right )
			);
	}
}

bool isPrimeNumber( int passedInteger )
{
	for( int counter = 2; counter < passedInteger; ++counter )
	{
		if( passedInteger & counter == 0 )
		{
			return false;
		}
	}

	if( passedInteger < 2 )
	{
		return false;
	}
	else
	{
		return true;
	}
}

LL<int> binarytree::toLL() const
{
	LL<int> returnLinkedList;
	toLL_aux( returnLinkedList, root );

	return returnLinkedList;
}

void binarytree::toLL_aux(LL<int> &linkedList, const binarytree::treenode* rootptr)
{
	if( rootptr != nullptr )
	{
		toLL_aux( linkedList, rootptr -> right );
		linkedList.push_front( rootptr -> data );
		toLL_aux( linkedList, rootptr -> left );
	}
}

/*
The binary tree: 0 5 8 11 12 14 17 19 24 27 27 28 31 34 36 41 41 42 45 45
The linked list: 0 5 8 11 12 14 17 19 24 27 27 28 31 34 36 41 41 42 45 45
The original binary tree still intact: 0 5 8 11 12 14 17 19 24 27 27 28 31 34 36 41 41 42 45 45
Press any key to continue . . .
*/