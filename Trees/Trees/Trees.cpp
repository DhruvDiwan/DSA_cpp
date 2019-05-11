#include <iostream>
using namespace std;

#include<genericTrees.h>

int main()
{
	tree<int> tr;

	// testing lastAdded error throwing
	try {
		cout << "Last added " << tr.lastAdded() << endl;
	}
	catch (invalid_argument) {
		cout << "No element added" << endl;
	}

	// testing insert() on empty tree : root gets created , then printing last added
	tr.insert(0);
	try {
		cout << "Last added " << tr.lastAdded() << endl;
	}
	catch (invalid_argument) {
		cout << "No element added" << endl;
	}

	// testing displayElements , isIn , isRoot , Size()  WITH ONLY ROOT PRESENT
	tr.displayElements();
	cout << tr.isIn(0) << endl;
	cout << tr.isRoot(0) << endl;
	cout << "size : " << tr.Size() << endl << endl;


	// testing after adding second node
	tr.insert(1);
	cout << "Last added " << tr.lastAdded() << endl;
	tr.displayElements();
	cout << tr.isIn(1) << endl;
	cout << tr.isRoot(1) << endl;
	cout << "size : " << tr.Size() << endl << endl;

	cout << "Root : " << tr.getRoot() << endl << endl << endl << endl;

	// testing search function for 2 node tree
	cout << tr.test(1) << endl;
	cout << tr.test(0) << endl;
	cout << tr.test(3) << endl;
	cout << tr.test(-1) << endl;

	// adding 5 nodes through insert
	for (int i = 2; i < 7; i++)
	{
		tr.insert(i);
	}
	tr.printChildren(0);
	for (int i = 1; i < 7; i++)
	{
		cout << i << "'s parent is " << tr.getParent(i) << endl;
	}
	//testing getParent function
	cout << endl << endl << "Parent of 1 is " << tr.getParent(1) << endl;
	cout << tr.test(2) << endl;
	// testing insert function
	//cout << tree.isIn(2) << endl;
	tr.insert(2, 10);
	tr.printChildren(2);
	tr.displayElements();
	for (int i = 0; i < 7; i++)
	{
		if (tr.isInternal(i)) {
		cout << i << " is internal\n";
		}
		else {
			cout << i << " is a leaf\n";
		}
	}
	if (tr.isInternal(10)) {
		cout << "10 is internal\n";
	}
	else {
		cout << "10 is a leaf\n";
	}

	cout << "New tree \n\n";

	tree<int> t;
	t.insert(0);
	for (int i = 0; i < 7 ; i++)
	{
		t.insert(i, i + 1);
	}
	t.displayElements();
	for (int i = 1; i < 8; i++)
	{
		cout << i << "'s parent is " << t.getParent(i) << endl;
	}
}
