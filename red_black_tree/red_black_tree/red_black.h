#pragma once
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Node
{
public:
	Node<T>* lf, * rt, * parent;
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
	~RBT();
	int count();
	int root_data();
	void display();
	void insert(T data);
	void del(T data);

private:
	int nodes; // nodes : number of nodes in the tree
	Node<T>* root;
	Node<T>* successor(Node<T>* ptr);
	void delNode(Node<T>* ptr);
	void double_black_del(Node<T>* u, Node<T>* v);
	void recolour_double_black(Node<T>* ptr);
	Node<T>* find_ptr(T data);
	void display_help(Node<T>* ptr);
	void refactor(Node<T>* ptr);
};


template<typename T>
inline RBT<T>::RBT()
{
	root = NULL;
	nodes = 0;
}

template<typename T>
inline RBT<T>::~RBT()
{
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
	cout << endl;
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
		if (curr->data == data) {
			cout << data << " already exists in tree " << endl;
			return;
		}
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
inline void RBT<T>::del(T data)
{
	Node<T>* ptr = find_ptr(data);
	if (!ptr) {
		cout << data << " doesn't exist in tree\n";
		return;
	}
	nodes--;
	delNode(ptr);
}



template<typename T>
inline Node<T>* RBT<T>::successor(Node<T>* ptr)
{
	if (!ptr) return NULL;
	Node<T>* curr = ptr->rt;
	while (curr->lf) curr = curr->lf;
	return curr;
}

template<typename T>
inline void RBT<T>::delNode(Node<T>* ptr)
{
	if (!ptr) return;
	if (ptr->lf && ptr->rt) { // two children
		Node<T>* succ = successor(ptr);
		ptr->data = succ->data;
		delNode(succ);
		return;
	}
	Node<T>* v = ptr;
	Node<T>* u = NULL;
	if (v->lf) u = v->lf;
	if (v->rt) u = v->rt;
	// assumes null is black
	if (
		(!u && v->c == 'r') ||
		(u && !(v->c == 'b' && u->c == 'b'))
		) { // only one of u / v is red
		if (!u) {
			if (v->parent) {
				if (v->parent->rt == v) v->parent->rt = NULL;
				else v->parent->lf = NULL;
			}
			else {
				root = NULL;
			}
			delete(v);
			return;
		}
		u->c = 'b';
		u->parent = v->parent;
		if (v->parent) {
			if (v->parent->rt == v) v->parent->rt = u;
			else v->parent->lf = u;
		}
		else {
			root = u;
		}
	}
	else { // both v and u are black : v is black , u is either null or black
		double_black_del(u, v);
	}
}

template<typename T>
inline void RBT<T>::double_black_del(Node<T>* u, Node<T>* v)
{
	if (v == root) { // deletion of root
		if (u) {
			root = u;
			u->c = 'b';
			u->parent = NULL;
			delete(v);
		}
		else {
			root = NULL;
		}
		return;
	}
	Node<T>* p = NULL; // p : parent
	Node<T>* s = NULL; // s : sibling
	s = v->parent->lf == v ? v->parent->rt : v->parent->lf;
	p = v->parent;
	if (u) u->parent = p;

	if (!s) { // sibling doesn't exist
		if (p->rt == v) p->rt = NULL;
		else p->lf = u;
		if (p->c == 'r') p->c = 'b';
		else recolour_double_black(p);
	}
	else if (
		s && s->c == 'b' &&
		((s->rt && s->rt->c == 'r') || (s->lf && s->lf->c == 'r'))
		) { // sibling is black and atleast one red child
		if (p->rt == s && s->rt && s->rt->c == 'r') { // right-right case
			s->parent = p->parent;
			if (s->parent) {
				if (s->parent->lf == p) s->parent->lf = s;
				else s->parent->rt = s;
			}
			else {
				root = s;
			}
			s->rt->c = 'b';
			p->rt = s->lf;
			if (p->rt) {
				p->rt->c = 'r';
				p->rt->parent = p;
			}
			s->lf = p;
			p->parent = s;
			p->lf = u;
		}
		else if (p->lf == s && s->lf && s->lf->c == 'r') { // left-left case
			s->parent = p->parent;
			if (s->parent) {
				if (s->parent->lf == p) s->parent->lf = s;
				else s->parent->rt = s;
			}
			else {
				root = s;
			}
			s->lf->c = 'b';
			p->lf = s->rt;
			if (p->lf) {
				p->lf->c = 'r';
				p->lf->parent = p;
			}
			s->rt = p;
			p->parent = s;
			p->rt = u;
		}
		else if (p->rt == s && s->lf && s->lf->c == 'r') { // right-left case
			s->lf->parent = p->parent;
			if (p->parent) {
				if (p->parent->rt == p) p->parent->rt = s->lf;
				else p->parent->lf = s->lf;
			}
			else {
				root = s->lf;
			}
			s->lf->rt = s;
			s->lf->lf = p;
			p->parent = s->lf;
			s->parent = s->lf;
			s->lf = NULL;
			s->parent->c = 'b';
			p->lf = u;
			p->rt = NULL;
		}
		else if (p->lf == s && s->rt && s->rt->c == 'r') { // left-right case
			s->rt->parent = p->parent;
			if (p->parent) {
				if (p->parent->rt == p) p->parent->rt = s->rt;
				else p->parent->lf = s->rt;
			}
			else {
				root = s->rt;
			}
			s->rt->lf = s;
			s->rt->rt = p;
			p->parent = s->rt;
			s->parent = s->rt;
			s->rt = NULL;
			s->parent->c = 'b';
			p->rt = u;
			p->lf = NULL;
		}
	}
	else if (
		s && s->c == 'b' &&
		!((s->rt && s->rt->c == 'r') && (s->lf && s->lf->c == 'r'))
		) { // sibling is black and both it's children are black
		s->c = 'r';
		if (v->parent->rt == v) {
			v->parent->rt = u;
		}
		else if (v->parent->lf == v) {
			v->parent->lf = u;
		}
		if (v->parent->c == 'b') {
			recolour_double_black(v->parent);
		}
		else {
			v->parent->c = 'b';
		}

	}
	else if (s && s->c == 'r') { // if sibling is red
		if (p->rt == s) { // right case
			s->parent = p->parent;
			if (p->parent) {
				if (p->parent->lf == p) p->parent->lf = s;
				else p->parent->rt = s;
			}
			else {
				root = s;
			}
			if (s->rt) s->rt->c = 'b';
			p->rt = s->lf;
			if (s->lf) {
				s->lf->parent = p;
				s->lf->c = 'r';
			}
			p->c = 'b';
			p->lf = u;
			p->parent = s;
			s->lf = p;
			s->c = 'b';
		}
		else { // left case
			s->parent = p->parent;
			if (p->parent) {
				if (p->parent->lf == p) p->parent->lf = s;
				else p->parent->rt = s;
			}
			else {
				root = s;
			}
			if (s->lf) s->lf->c = 'b';
			p->lf = s->rt;
			if (s->rt) {
				s->rt->parent = p;
				s->rt->c = 'r';
			}
			p->c = 'b';
			p->rt = u;
			p->parent = s;
			s->rt = p;
			s->c = 'b';

		}
	}
	delete(v);
}

template<typename T>
inline void RBT<T>::recolour_double_black(Node<T>* ptr)
{
	if (!ptr) return;
	Node<T>* sibling;
	if (ptr->parent) {
		if (ptr->parent->lf == ptr) sibling = ptr->parent->rt;
		else sibling = ptr->parent->lf;
	}
	else {
		ptr->c = 'b';
		return;
	}
	if (sibling && !((sibling->rt && sibling->rt->c == 'r') && (sibling->lf && sibling->lf->c == 'r'))) {
		sibling->c = 'r';
		if (ptr->parent->c == 'b') recolour_double_black(ptr->parent);
		else sibling->parent->c = 'r';
	}
}


template<typename T>
inline Node<T>* RBT<T>::find_ptr(T data)
{
	Node<T>* curr = root;
	while (curr) {
		if (data == curr->data) return curr;
		else if (curr->data > data) curr = curr->lf;
		else curr = curr->rt;
	}
	return NULL;
}

template<typename T>
inline void RBT<T>::display_help(Node<T>* ptr)
{
	if (!ptr || ptr == nullptr) {
		cout << "x";
		return;
	}
	if (!ptr->lf && !ptr->rt) {
		cout << ptr->data << "-" << ptr->c;
	}
	else
	{
		cout << ptr->data << "-" << ptr->c << "(";
		display_help(ptr->lf);
		cout << ",";
		display_help(ptr->rt);
		cout << ")";
	}
}


template<typename T>
inline void RBT<T>::refactor(Node<T>* ptr)
{
	if (!ptr) return;
	if (ptr == root) {
		root->c = 'b';
		return;
	}
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
			b->c = 'r';
			a->c = 'b';
			k->c = 'r';
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
			b->parent = a;
		}
		else if (!is_a_rt && is_k_rt) { // left-right case
			b->c = 'r';
			a->c = 'r';
			k->c = 'b';
			k->parent = b->parent;
			a->parent = k;
			b->lf = k->rt;
			if (k->rt) k->rt->parent = b;
			if (b->parent) {
				if (b->parent->rt == b) {
					b->parent->rt = k;
				}
				else {
					b->parent->lf = k;
				}
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
			b->c = 'r';
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
			if (b->rt) b->rt->parent = b;
			k->lf = b;
			b->parent = k;
			a->lf = k->rt;
			if (a->lf) a->lf->parent = a;
			k->rt = a;
			a->parent = k;
		}
		else { // left-left case
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