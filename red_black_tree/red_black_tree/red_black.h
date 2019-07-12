#pragma once
#include <iostream>
#include <fstream>

using namespace std;
ofstream output;


template<typename T>
class Node
{
public:
	Node<T>* lf, * rt , *parent;
	T data;
	char c; // r is red , b is black , n is null / uncoloured
	Node() {
		lf = NULL;
		rt = NULL;
		parent = NULL;
		c = 'n';
		data = 1234567890;
	}
	~Node() {}
private:
};

template<typename T>
class RBT
{
public:
	RBT();
	~RBT() {}
	int count();
	int root_data();
	void display();
	void insert(T data);
	void del(T data);

private:
	int nodes; // nodes is number of nodes in the tree
	Node<T>* root;
	void delNode(Node<T>* ptr);
	Node<T>* find_ptr(Node<T>* curr , T data);
	void display_help(Node<T>* ptr);
	void refactor(Node<T>* ptr);
};

template<typename T>
inline RBT<T>::RBT()
{
	output.open("output10.txt");
	root = NULL;
	nodes = 0;
}


template<typename T>
inline int RBT<T>::count()
{
	return nodes;
}

template<typename T>
inline int RBT<T>::root_data()
{
	if (root) return root->data;
	return -1235467890;
}

template<typename T>
inline void RBT<T>::display()
{
	display_help(root);
	output << endl;
}

template<typename T>
inline void RBT<T>::insert(T data)
{
	if (!root) {
		root = new Node<T>;
		root->data = data;
		root->c = 'b';
		nodes = 1;
		return;
	}
	Node<T>* curr = root;
	Node<T>* prev = NULL;
	while (curr) {
		if (curr->data == data) return;
		prev = curr;
		if (curr->data > data) curr = curr->lf;
		else curr = curr->rt;
	}
	nodes++;
	curr = new Node<T>;
	curr->c = 'r';
	curr->parent = prev;
	curr->data = data;
	if (prev->data > data) {
		prev->lf = curr;
	}
	else {
		prev->rt = curr;
	}
	if (prev->c == 'b') return;
	refactor(curr);
}

template<typename T>
inline void RBT<T>::delNode(Node<T>* ptr)
{
}

template<typename T>
inline Node<T>* RBT<T>::find_ptr(Node<T>* curr, T data)
{
	if (!curr) return NULL;
	if (curr->data == data) return curr;
	Node<T>* temp1 = find_ptr(curr->lf, data);
	Node<T>* temp2 = find_ptr(curr->rt, data);
	if (temp1) return temp1;
	if (temp2) return temp2;
	return NULL;
}

template<typename T>
inline void RBT<T>::display_help(Node<T>* ptr)
{
	if (!ptr) {
		output << "x";
		return;
	}
	if (!ptr->lf && !ptr->rt){
		output << ptr->data << "-" << ptr->c; 
	}
	else
	{
		output << ptr->data << "-" << ptr->c << "(";
		display_help(ptr->lf);
		output << ",";
		display_help(ptr->rt);
		output << ")";
	}
}

//template<typename T>
//inline void RBT<T>::display_help(Node<T>* ptr)
//{
//	if (!ptr) return;
//	cout << ptr->data << "-" << ptr->c;
//	if (ptr->lf &&  !ptr->rt) {
//		cout << "("; display_help(ptr->lf); cout << ",x)";
//	}
//	else if (!ptr->lf && ptr->rt) {
//		cout << "(x,"; display_help(ptr->rt); cout << ")";
//	}
//	else if (ptr->lf && ptr->rt) {
//		cout << "("; display_help(ptr->lf); cout << ","; display_help(ptr->rt); cout << ")";
//	}
//
//}

template<typename T>
inline void RBT<T>::refactor(Node<T>* ptr)
{
	if (!ptr) return;
	Node<T>* k = ptr;
	Node<T>* a = k->parent;
	if (!a) {
		k->c = 'b';
		return;
	}
	Node<T>* b = a->parent;
	if (!b) return;
	a->c = 'b';
	b->c = 'r';
	bool is_a_rt = false;
	bool is_k_rt = false;
	if (b->rt == a) is_a_rt = true;
	if (a->rt == k) is_k_rt = true;
	Node<T>* c = b->rt;
	// k : new node , a : parent , b : grandparent , c : uncle / parent's sibling
	if (is_a_rt) c = b->lf;
	if (!c || (c && c->c == 'b')) { // sibling of a is either black or null
		if (is_a_rt && is_k_rt) { // right-right case
			b->rt = a->lf;
			if (a->lf) a->lf->parent = b;
			a->lf = b;
			a->parent = b->parent;
			if (b->parent) {
				if (b->parent->lf == b) b->parent->lf = a;
				else b->parent->rt = a;
			}
			else {
				root = a;
			}
			a->rt = k;
			k->parent = a;
			b->parent = a;
		}
		else if (!is_a_rt && is_k_rt) { // left-right case
			// tested
			a->c = 'r';
			k->c = 'b';
			k->parent = b->parent;
			a->parent = k;
			b->lf = k->rt;
			if (k->rt) k->rt->parent = b;
			if (b->parent) {
				if (b->parent->rt == b) b->parent->rt == k;
				else b->parent->lf = k;
			}
			else {
				root = k;
			}
			k->rt = b;
			b->parent = k;
			a->rt = k->lf;
			if (a->rt) a->rt->parent = a;
			k->lf = a;
		}
		else if (is_a_rt && !is_k_rt) { // right-left case
			a->c = 'r';
			k->c = 'b';
			k->parent = b->parent;
			if (b->parent) {
				if (b->parent->rt == b) b->parent->rt = k;
				else b->parent->lf = k;
			}
			else {
				root = k;
			}
			b->rt = k->lf;
			if (b->rt) b->rt->parent = k;
			k->lf = b;
			b->parent = k;
			a->lf = k->rt;
			if (a->lf) a->lf->parent = a;
			k->rt = a;
			a->parent = k;
		}
		else{ // left-left case
			a->parent = b->parent;
			if (b->parent) {
				if (b->parent->lf == b) b->parent->lf = a;
				else b->parent->rt = a;
			}
			else {
				root = a;
			}
			b->lf = a->rt;
			if (b->lf) b->lf->parent = b;
			a->rt = b;
			b->parent = a;
			a->lf = k;
			k->parent = a;
		}

	}
	else { // sibling of a is red
		c->c = 'b';
		if (b->parent && b->parent->c == 'r') refactor(b);
		if (!b->parent) b->c = 'b'; // root always black
	}
}