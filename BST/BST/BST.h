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
	bool search(T data);
	tNode<T>* searchPtr(T data);
	T getMinimum();
	T getMaximum();
	T getSuccessor(T data);
	T getPredecessor(T data);
	void del(T data);

private:
	tNode<T>* root;
	int size;
};

template <typename T>
bst<T>::bst()
{
	root = NULL;
	size = 0;
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

template<typename T>
bool bst<T>::search(T data)
{
	if (!root) return NULL;
	tNode<T>* curr = root;
	while (curr && curr->data != data) {
		if (curr->data > data) curr = curr->lf;
		else curr = curr->rt;
	}
	return bool(curr);
}

template<typename T>
tNode<T>* bst<T>::searchPtr(T data)
{
	if (!root) return NULL;
	tNode<T>* curr = root;
	while (curr && curr->data != data) {
		if (curr->data > data) curr = curr->lf;
		else curr = curr->rt;
	}
	return curr;
}


template<typename T>
T bst<T>::getMinimum()
{
	if (!root) throw bad_exception();
	tNode<T>* curr = root;
	while (curr->lf) curr = curr->lf;
	return curr->data;
}

template<typename T>
T bst<T>::getMaximum()
{
	if (!root) throw bad_exception();
	tNode<T>* curr = root;
	while (curr->rt) curr = curr->rt;
	return curr->data;
}

template<typename T>
T bst<T>::getSuccessor(T data)
{
	if (!root) throw bad_exception();
	tNode<T>* ptr = searchPtr(data);
	if (!ptr) throw bad_exception();
	if (ptr->rt) {
		ptr = ptr->rt;
		while (ptr->lf) ptr = ptr->lf;
		return ptr->data;
	}
	while (ptr && !ptr->isLeft) ptr = ptr->p;
	if (!ptr) return NULL;
	if (ptr == root && root->data > data) return root->data;
	if (ptr == root && root->data <= data) return NULL;
	return ptr->p->data;
}

template<typename T>
T bst<T>::getPredecessor(T data)
{
	if (!root) throw bad_exception();
	tNode<T>* ptr = searchPtr(data);
	if (!ptr) throw bad_exception();
	if (ptr->lf) {
		ptr = ptr->lf;
		while (ptr->rt) ptr = ptr->rt;
		return ptr->data;
	}
	while (ptr && ptr->isLeft && ptr != root) ptr = ptr->p;
	if (ptr == root && root->data > data) return root->data;
	if (ptr == root && root->data <= data) return NULL;
	return ptr->p->data;
}

template<typename T>
void bst<T>::del(T data)
{
	if (!root) throw bad_exception();
	tNode<T>* ptr = searchPtr(data);
	//if (!ptr) {
	//	cout << "Data not found" << endl;
	//}
	size--;
	// no child
	if(!ptr->lf && !ptr->rt) {
		if (ptr->isLeft) {
			if (ptr == root) {
				root = NULL;
			}
			else {
				ptr->p->lf = NULL;
			}
			delete(ptr);
		}
		else {
			if (ptr == root) {
				root = NULL;
			}
			else {
				ptr->p->rt = NULL;
			}
			delete(ptr);
		}
		return;
	}
	// 2 children
	if (ptr->lf && ptr->rt) {
		size++;
		tNode<T>* curr = ptr->rt;
		while (curr->lf) curr = curr->lf;
		int copyData = ptr->data;
		ptr->data = curr->data;
		curr->data = copyData;
		//display();
		del(copyData);
		return;
	}
	// only left child
	tNode<T>* copy = ptr;
	if (ptr->lf) {
		if (ptr == root) {
			root = root->lf;
			root->isLeft = true;
			delete copy;
			return;
		}
		if (ptr->isLeft) {
			ptr->p->lf = ptr->lf;
			ptr->lf->isLeft = true;
		}
		else {
			ptr->p->rt = ptr->lf;
			ptr->lf->isLeft = false;
		}
	}
	// only right child
	else {
		if (ptr == root) {
			root = root->rt;
			root->isLeft = false;
			delete copy;
			return;
		}
		if (ptr->isLeft) {
			ptr->p->lf = ptr->rt;
			ptr->rt->isLeft = true;
		}
		else {
			ptr->p->rt = ptr->rt;
			ptr->rt->isLeft = false;
		}
	}
	delete copy;
}