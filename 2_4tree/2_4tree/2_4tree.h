#pragma once
#include<string>
#include<iostream>
using namespace std;

template <typename T>
class Node
{
public:
	Node();
	~Node();
	int size;
	Node<T>* pt1, * pt2, * pt3, * pt4;
	Node<T>* parent;
	T k1, k2, k3;
};

template <typename T>
Node<T>::Node()
{
	size = 0;
	pt1 = pt2 = pt3 = pt4 = parent = NULL;
	k1 = k2 = k3 = -1234;
}

template <typename T>
Node<T>::~Node()
{
}


template<typename T>
class tree
{
public:
	tree();
	~tree();
	void insert(T data);
	void display();
	void displayHelp(Node<T>* ptr);
	//void delete();
	void setOutputStream(string outFileName);
	void setInputStream(string inFileName);
private:
	Node<T>* root;
	fstream outFile , inFile;
	streambuf* stream_buffer_cout;
	streambuf* stream_buffer_cin;

	void split_promote(Node<T>* curr, T data , Node<T>* p1, Node<T>* p2, Node<T>* p3, Node<T>* p4, Node<T>* p5);
};

template <typename T>
tree<T>::tree()
{
	root = NULL;
}

template <typename T>
tree<T>::~tree()
{
	if(inFile) inFile.close();
	if(outFile) outFile.close();
	cout.rdbuf(stream_buffer_cout);// Redirect cout back to screen
	cin.rdbuf(stream_buffer_cin);// Redirect cin back to stdin
}

template<typename T>
void tree<T>::insert(T data)
{
	if (!root) {  // null tree
		root = new Node<T>;
		root->k1 = data;
		root->size = 1;
		return;
	}
	// getting curr to point at a leaf
	Node<T>* curr = root;
	while (curr->pt1) { // while curr is not a leaf
		if ( (curr->size == 1 && curr->k1 == data) ||
			(curr->size ==2 && curr->k2 == data) ||
			(curr->size == 3 && curr->k3 == data) ) return; // data present
		// duplication not allowed
		if (data < curr->k1) curr = curr->pt1;
		else if (curr->size == 1 || data < curr->k2) curr = curr->pt2;
		else if (curr->size == 2 || data < curr->k3) curr = curr->pt3;
		else curr = curr->pt4;
	}
	if (curr->size == 1) {
		curr->size++;
		if (curr->k1 < data) {
			curr->k2 = data;
			return;
		}
		curr->k2 = curr->k1;
		curr->k1 = data;
		return;
	}
	if (curr->size == 2) {
		curr->size++;
		if (data < curr->k1) {
			curr->k3 = curr->k2;
			curr->k2 = curr->k1;
			curr->k1 = data;
			return;
		}
		else if (data < curr->k2) {
			curr->k3 = curr->k2;
			curr->k2 = data;
			return;
		}
		else {
			curr->k3 = data;
			return;
		}
	}
	split_promote(curr, data, NULL, NULL, NULL, NULL, NULL);
}


template<typename T>
void tree<T>::display()
{
	displayHelp(root);
	cout << endl;
}

template<typename T>
void tree<T>::displayHelp(Node<T>* ptr)
{
	if (!ptr) {
		cout << "[x]";
		return;
	}
	if (ptr->size == 1) cout << "["  << ptr->k1 << ",x,x]";
	if (ptr->size == 2) cout << "[" << ptr->k1 << "," << ptr->k2 << ",x]";
	if (ptr->size == 3) cout << "[" << ptr->k1 << "," << ptr->k2 << "," << ptr->k3 << "]";
	if (!ptr->pt1 && !ptr->pt2 && !ptr->pt3 && !ptr->pt4) return;
	cout << "(";
	displayHelp(ptr->pt1);
	cout << ",";
	displayHelp(ptr->pt2);
	cout << ",";
	displayHelp(ptr->pt3);
	cout << ",";
	displayHelp(ptr->pt4);
	cout << ")";
}

template<typename T>
inline void tree<T>::setOutputStream(string outFileName)
{
	outFile.open(outFileName, ios::out);
	stream_buffer_cout = cout.rdbuf();// Backup streambuffers of  cout
	streambuf* stream_buffer_file = outFile.rdbuf();// Get the streambuffer of the file
	cout.rdbuf(stream_buffer_file);// Redirect cout to file
}

template<typename T>
inline void tree<T>::setInputStream(string inFileName)
{
	inFile.open(inFileName, ios::in);
	stream_buffer_cin = cin.rdbuf();// Backup streambuffers of  cout
	streambuf* stream_buffer_file = inFile.rdbuf();// Get the streambuffer of the file
	cin.rdbuf(stream_buffer_file); // redirect cin to inFile
}

template<typename T>
void tree<T>::split_promote(Node<T>* curr, T data , Node<T>* p1, Node<T>* p2, Node<T>* p3, Node<T>* p4, Node<T>* p5) // curr is a node of size 3, prior to call
{
	T data1, data2, data3, data4;
	Node<T>* node_;
	//if (!curr) return; // redundant
	data1 = curr->k1;
	data2 = curr->k2;
	data3 = curr->k3;
	if (data < data1) {
		data4 = data3;
		data3 = data2;
		data2 = data1;
		data1 = data;
	}
	else if (data < data2) {
		data4 = data3;
		data3 = data2;
		data2 = data;
	}
	else if (data < data3) {
		data4 = data3;
		data3 = data;
	}
	else data4 = data;
	curr->k1 = data1;
	curr->size = 1;
	node_ = new Node<T>;
	node_->k1 = data3;
	node_->k2 = data4;
	node_->size = 2;
	curr->pt1 = p1;
	if (p1) p1->parent = curr;
	curr->pt2 = p2;
	if (p2) p2->parent = curr;
	curr->pt3 = NULL;
	curr->pt4 = NULL;
	node_->pt1 = p3;
	if (p3) p3->parent;
	node_->pt2 = p4;
	if (p4) p4->parent = node_;
	node_->pt3 = p5;
	if (p5) p5->parent = node_;
	// now data1 < data2 < data3 < data4, with data stored in either one of them
	T promoted = data2;
	if (!curr->parent) {
		root = new Node<T>;
		root->k1 = promoted;
		root->size = 1;
		root->pt1 = curr;
		root->pt2 = node_;
		curr->parent = root;
		node_->parent = root;
		return;
	}
	node_->parent = curr->parent;
	Node<T>* pr = curr->parent;
	if (pr->size == 1) {
		pr->size++;
		if (pr->k1 < promoted) {
			pr->k2 = promoted;
			pr->pt2 = curr;
			pr->pt3 = node_;
			return;
		}
		pr->k2 = pr->k1;
		pr->k1 = promoted;
		pr->pt3 = pr->pt2;
		pr->pt2 = node_;
		pr->pt1 = curr;
		return;
	}
	if (pr->size == 2) {
		pr->size++;
		if (promoted < pr->k1) {
			pr->k3 = pr->k2;
			pr->k2 = pr->k1;
			pr->k1 = promoted;
			pr->pt4 = pr->pt3;
			pr->pt3 = pr->pt2;
			pr->pt2 = node_;
			pr->pt1 = curr;
			return;
		}
		else if (promoted < curr->k2) {
			pr->k3 = pr->k2;
			pr->k2 = promoted;
			pr->pt4 = pr->pt3;
			pr->pt3 = node_;
			pr->pt2 = curr;
			return;
		}
		else {
			pr->k3 = promoted;
			pr->pt4 = node_;
			pr->pt3 = curr;
			return;
		}
	}
	if (pr->pt1 == curr) split_promote(pr, promoted , curr, node_, pr->pt2, pr->pt3, pr->pt4);
	if (pr->pt2 == curr) split_promote(pr, promoted, pr->pt1, curr, node_, pr->pt3, pr->pt4);
	if (pr->pt3 == curr) split_promote(pr, promoted, pr->pt1, pr->pt2, curr, node_, pr->pt4);
	if (pr->pt4 == curr) split_promote(pr, promoted, pr->pt1, pr->pt2, pr->pt3, curr, node_);
}