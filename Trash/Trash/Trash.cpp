// Trash.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
	T data;
	Node<T>* leftChild, *parent, * rightSibling;
	Node() {
		leftChild = NULL;
		parent = NULL;
		rightSibling = NULL;
	}
	Node(T val) {
		data = val;
		leftChild = NULL;
		parent = NULL;
		rightSibling = NULL;
	}
};

int main()
{
	Node<int>* node = new Node<int>;
	node->data = 12;
	Node<int>* node_ = new Node<int>;
	node_ = node;
	cout << "Before nullifying node : " << node_->data << endl;
	//delete(node);
	node = NULL;
	cout << "After nullifying node : " << node_->data << endl;
	//string s = "Dhruv" + " Diwan"; // not allowed
	//cout << s;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
