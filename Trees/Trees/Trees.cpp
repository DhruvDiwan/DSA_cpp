#include <iostream>
using namespace std;

#include<genericTrees.h>

int main()
{
	tree<int> tree;

	// testing lastAdded error throwing
	try {
		cout << "Last added " << tree.lastAdded() << endl;
	}
	catch (invalid_argument) {
		cout << "No element added" << endl;
	}

	// testing insert() on empty tree : root gets created , then printing last added
	tree.insert(0);
	try {
		cout << "Last added " << tree.lastAdded() << endl;
	}
	catch (invalid_argument) {
		cout << "No element added" << endl;
	}

	// testing displayElements , isIn , isRoot , Size()  WITH ONLY ROOT PRESENT
	tree.displayElements();
	cout << tree.isIn(0) << endl;
	cout << tree.isRoot(0) << endl;
	cout << "size : " << tree.Size() << endl << endl;


	// testing after adding second node
	tree.insert(1);
	cout << "Last added " << tree.lastAdded() << endl;
	tree.displayElements();
	cout << tree.isIn(1) << endl;
	cout << tree.isRoot(1) << endl;
	cout << "size : " << tree.Size() << endl << endl;

	cout << "Root : " << tree.getRoot() << endl << endl << endl << endl;

	// testing search function for 2 node tree
	cout << tree.test(1) << endl;
	cout << tree.test(0) << endl;
	cout << tree.test(3) << endl;
	cout << tree.test(-1) << endl;

	// adding 5 nodes through insert
	for (int i = 2; i < 7; i++)
	{
		tree.insert(i);
	}
	tree.printChildren(0);
	for (int i = 1; i < 7; i++)
	{
		cout << i << "'s parent is " << tree.getParent(i) << endl;
	}
	//testing getParent function
	cout << endl << endl << "Parent of 1 is " << tree.getParent(1) << endl;
	cout << tree.test(2) << endl;
	// testing insert function
	//cout << tree.isIn(2) << endl;
	tree.insert(2, 10);
	tree.printChildren(2);
	tree.displayElements();
	for (int i = 0; i < 7; i++)
	{
		if (tree.isInternal(i)) {
		cout << i << " is internal\n";
		}
		else {
			cout << i << " is a leaf\n";
		}
	}
	if (tree.isInternal(10)) {
		cout << "10 is internal\n";
	}
	else {
		cout << "10 is a leaf\n";
	}
}
