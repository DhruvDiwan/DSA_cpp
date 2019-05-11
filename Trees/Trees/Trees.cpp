#include <iostream>
using namespace std;

#include<genericTrees.h>

int main()
{
	tree<int> tree;
	try {
		cout << "Last added " << tree.lastAdded() << endl;
	}
	catch (invalid_argument) {
		cout << "No element added" << endl;
	}
	tree.insert(0);
	try {
		cout << "Last added " << tree.lastAdded() << endl;
	}
	catch (invalid_argument) {
		cout << "No element added" << endl;
	}
	tree.displayElements();
	cout << tree.isIn(0) << endl;
	cout << tree.isRoot(0) << endl;
	cout << "size : " << tree.Size() << endl;
}
