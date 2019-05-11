#pragma once
#include<SinglyLinkedLinear.h>
template<typename T>
class tNode {
public:
	T data;
	tNode<T>* leftChild, *parent, * rightSibling;
	tNode() {
		leftChild = NULL;
		parent = NULL;
		rightSibling = NULL;
	}
	tNode(T val) {
		data = val;
		leftChild = NULL;
		parent = NULL;
		rightSibling = NULL;
	}
};


template<typename T>
class tree
{
public:
	tree();
	T lastAdded();
	int Size();
	SinglyLinkedLinear<T> Elements();
	void displayElements();
	bool isIn(T data);
	bool isRoot(T data);
	void insert(T data);
	void insert(T parent, T data);
	void del(T data);
	bool isInternal(T data);

private:
	int size;
	SinglyLinkedLinear<T> elements;
	tNode<T>* root, * last;
};

template<typename T>
tree<T>::tree()
{
	SinglyLinkedLinear<T> elements;
	size = 0;
	root = NULL;
	last = NULL;
}

template<typename T>
T tree<T>::lastAdded() {
	if (!size) {
		throw invalid_argument("No element added");
	}
	return last->data;
}

template<typename T>
int tree<T>::Size() {
	return size;
}

template<typename T>
SinglyLinkedLinear<T> tree<T>::Elements() {
	return elements;
}

template<typename T>
void tree<T>::displayElements() {
	elements.display();
}

template<typename T>
bool tree<T>::isIn(T data) {
	return elements.isIn(data);
}

template<typename T>
bool tree<T>::isRoot(T data) {
	if (!isIn(data)) return false;
	return bool(root->data == data);
}


template<typename T>
void tree<T>::insert(T data) {
	size++;
	elements.insertRear(data);
	if (!root) {
		root = new tNode<T>(data);
		last = root;
		return;
	}
	if (last == root) {
		root->leftChild = new tNode<T>(data);
		root->leftChild->parent = root;
		last = root->leftChild;
		return;
	}
	last->rightSibling = new tNode<T>(data);
	last->rightSibling->parent = last->parent;
	last = last->rightSibling;
}

template<typename T>
void tree<T>::insert(T parent, T data) {
	if (!isIn(parent)) {
		cout << "'" << parent << "' Not found\nUse insert(data) function to add randomly" << endl;
		return;
	}

}