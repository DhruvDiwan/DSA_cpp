#include <iostream>
#include<BST.h>

int main()
{
	bst<int> tree;
	tree.display();
	tree.display();
	tree.insert(10);
	tree.insert(4);
	tree.insert(17);
	tree.insert(1);
	tree.insert(5);
	tree.insert(16);
	tree.insert(21);
	tree.display();
	tree.inOrder();
	tree.preOrder();
	tree.postOrder();
	cout << tree.search(10) << endl;
	cout << tree.search(4) << endl;
	cout << tree.search(17) << endl;
	cout << tree.search(99) << endl;
	cout << "Minimum is " << tree.getMinimum() << endl;
	cout << "Maximum is " << tree.getMaximum() << endl;
	cout << "Successor of 1 is " << tree.getSuccessor(1) << endl;
	cout << "Successor of 5 is " << tree.getSuccessor(5) << endl;
	cout << "Predecessor of 21 is " << tree.getPredecessor(21) << endl;
	cout << "Predecessor of 16 is " << tree.getPredecessor(16) << endl;
	cout << "Predecessor of 10 is " << tree.getPredecessor(10) << endl;
	tree.del(21);
	tree.display();
	tree.del(17);
	tree.display();
	tree.del(10);
	tree.display();
	tree.del(5);
	tree.display();
	tree.del(1);
	tree.display();
	tree.del(4);
	tree.display();
	tree.del(16);
	tree.display();
}