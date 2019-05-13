#pragma once
#include<iostream>
using namespace std;

template <typename T>
class tNode
{
public:
	tNode(T val);
	~tNode();
	T data;
	tNode<T>* lf, * rt, * p;
	bool isLeft;
	int nodeHt; // node height
};

template <typename T>
tNode<T>::tNode(T val)
{
	data = val;
	lf = rt = p = NULL;
	isLeft = false;

}

template <typename T>
tNode<T>::~tNode()
{
}

/////////////////////////////////////////////////////////////////

template<typename T>
class bst
{
public:
	bst();
	~bst();
	void insert(T data);
	bool isIn(T data);
	void display();
	void displayRec(tNode<T>* ptr);
	void inOrder();
	void in(tNode<T>* ptr);
	void preOrder();
	void pre(tNode<T>* ptr);
	void postOrder();
	void post(tNode<T>* ptr);
	tNode<T>* search(T data);
	T getMinimum();
	T getMaximum();
	T getSuccessor();
	T getPredecessor();
	void del(tNode<T>* treeRoot, T data);

private:
	tNode<T>* root;
	int size, height;
};

template <typename T>
bst<T>::bst()
{
	root = NULL;
	size = 0;
	height = 0;
}

template <typename T>
bst<T>::~bst()
{
}

template<typename T>
void bst<T>::insert(T data)
{
	size++;
	if (!root) {
		root = new tNode<T>(data);
		root->nodeHt = 1;
		height = 1;
		return;
	}
	tNode<T>* curr = root;
	tNode<T>* prev = NULL;
	bool isLeft;
	while (curr) {
		prev = curr;
		if (curr->data > data) {
			curr = curr->lf;
			isLeft = true;
		}
		else {
			curr = curr->rt;
			isLeft = false;
		}
	}
	if (isLeft) {
		prev->lf = new tNode<T>(data);
		prev->lf->p = prev;
		prev->lf->isLeft = true;
		prev = prev->lf;
	}
	else {
		prev->rt = new tNode<T>(data);
		prev->rt->p = prev;
		prev->rt->isLeft = false;
		prev = prev->rt;
	}
	prev->nodeHt = prev->p->nodeHt + 1;
	if (prev->nodeHt > height) height = prev->nodeHt;
}

template<typename T>
bool bst<T>::isIn(T data) {
	tNode<T>* curr = root;
	while (curr && curr->data != data) {
		if (curr->data > data) curr = curr->lf;
		else curr = curr->rt;
	}
	if (curr) return true;
	return false;
}

template<typename T>
void bst<T>::display()
{
	displayRec(root);
	cout << endl;
}

template<typename T>
void bst<T>::displayRec(tNode<T>* ptr)
{
	if (!ptr) {
		cout << "x";
		return;
	}
	if (!ptr->lf && !ptr->rt) {
		cout << ptr->data;
		return;
	}
	cout << ptr->data << "(";
	displayRec(ptr->lf);
	cout << ",";
	displayRec(ptr->rt);
	cout << ")";
}

template<typename T>
void bst<T>::inOrder()
{
	in(root);
	cout << endl;
}

template<typename T>
void bst<T>::in(tNode<T>* ptr)
{
	if (!ptr) return;
	in(ptr->lf);
	cout << ptr->data << " ";
	in(ptr->rt);
}

template<typename T>
void bst<T>::preOrder()
{
	pre(root);
	cout << endl;
}

template<typename T>
void bst<T>::pre(tNode<T>* ptr)
{
	if (!ptr) return;
	cout << ptr->data << " ";
	pre(ptr->lf);
	pre(ptr->rt);
}

template<typename T>
void bst<T>::postOrder()
{
	post(root);
	cout << endl;
}

template<typename T>
void bst<T>::post(tNode<T>* ptr)
{
	if (!ptr) return;
	post(ptr->lf);
	post(ptr->rt);
	cout << ptr->data << " ";
}


