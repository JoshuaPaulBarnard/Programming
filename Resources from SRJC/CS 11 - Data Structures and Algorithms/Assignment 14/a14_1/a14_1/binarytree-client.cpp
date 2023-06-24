// Here is the file binarytree-client.cpp
// merged with the test code from assignment 13

#include <iostream>
#include "binarytree.h"
#include "LL.h"
using namespace std;

int main() 
{
	binarytree t;
	for (int i = 0; i < 20; i++) {
		t.insert(rand() % 50);
	}

	cout << "The binary tree: ";
	t.print();
	cout << endl;

	LL<int> l;
	l = t.toLL();

	cout << "The linked list: ";

	for (LL<int>::iterator i = l.begin(); i != l.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;

	cout << "The original binary tree still intact: ";
	t.print();

	cout << endl << endl;

	//-------------------------------------------------------------------------------




	binarytree list;

	int num;
	bool found;

	cout << "This program will test a linked List." << endl;
	cout << "Entering a negative integer will end the current phase, and start the next step in the program." << endl;
	cout << "Please Enter a Integer to add to a link list to test: ";
	cin >> num;
	while (num >= 0){
		list.insert(num);
		cout << "Please enter another Integer to insert (-# to end): ";
		cin >> num;
	}

	list.print();
	cout << endl;

	binarytree::size_type numItems;
	numItems = list.size();
	cout << "There are " << numItems << " items." << endl;

	binarytree::size_type numberOfPrimes;
	numberOfPrimes = list.numPrimes();
	cout << "There are " << numberOfPrimes << " prime numbers." << endl;
	
	
	cout << "enter a number to find (-# to end): ";
	cin >> num;
	while (num >= 0) {
		int result = list.find(num, found);
		if (!found) {
			cout << "not found" << endl;
		} else {
			cout << "found.  The data is " << result << endl;
		}
		cout << "enter a number to find (-# to end): ";
		cin >> num;
	}


	cout << "enter a number to delete (-# to end): ";
	cin >> num;
	while (num >= 0) {
		list.del(num, found);
		if (found) {
			cout << "the list is now ";
			list.print();
			cout << endl;
		} else {
			cout << num << " is not in the list." << endl;
		}
		cout << "enter a number to delete (-# to end): ";
		cin >> num;
	}


	binarytree list2(list);

	cout << "Now list 2 should be a copy of list.  Here it is: ";
	list2.print();
	cout << endl;
	

	list2.del(3, found);


	cout << "After deleting a 3 from list2, list2 is now: ";
	list2.print();
	cout << endl << "list should be unchanged.  Here it is: ";
	list.print();
	cout << endl;

	list = list2;

	cout << "Now list has been assigned list2 so it should match list2.  Here it is: ";
	list.print();
	cout << endl;
	
	list.del(4, found);

	cout << "After deleting a 4 from list, list is now: ";
	list.print();
	cout << endl << "list2 should be unchanged.  Here it is: ";
	list2.print();
	cout << endl;


	binarytree::size_type numberOfPrimes2;
	numberOfPrimes2 = list.numPrimes();
	cout << "There is now " << numberOfPrimes2 << " prime numbers." << endl;


	system("pause");
}