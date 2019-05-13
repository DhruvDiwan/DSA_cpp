#include <iostream>
#include<BST.h>

int main()
{
	bst<int> tree;
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
}