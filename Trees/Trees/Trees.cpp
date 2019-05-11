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
}
