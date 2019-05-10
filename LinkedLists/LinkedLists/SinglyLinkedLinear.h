#pragma once
#include<Node.h>
#include<iostream>
using namespace std;
template <typename T>
class SinglyLinkedLinear
{
private:
	Node<T>* head, * tail;
public:
	SinglyLinkedLinear();
	void insertHead(T data);
	void insertRear(T data);
	void insertAfter(T dataMatch, T data);
	void display();
	void deleteHead();
	void deleteRear();
	void del(T data);
	bool isEmpty();
	T getHead();
};

template <typename T>
T SinglyLinkedLinear<T> ::getHead() {
	return head->data;
}
template <typename T>
SinglyLinkedLinear<T>::SinglyLinkedLinear()
{
	head = NULL;
	tail = NULL;
}
template <typename T>
bool SinglyLinkedLinear<T> ::isEmpty() {
	return bool(!head);
}
template <typename T>
void SinglyLinkedLinear<T>::insertHead(T data) {
	if (!head) {
		head = new Node<T>;
		head->data = data;
		tail = head;
		return;
	}
	Node<T>* copy = head;
	head = new Node<T>;
	head->data = data;
	head->next = copy;
}

template <typename T>
void SinglyLinkedLinear<T> ::insertRear(T data) {
	if (!head) {
		head = new Node<T>;
		head->data = data;
		tail = head;
		return;
	}
	tail->next = new Node<T>;
	tail = tail->next;
	tail->data = data;
}

template <typename T>
void SinglyLinkedLinear<T>::insertAfter(T dataMatch, T data) {
	if (!head) {
		cout << "Empty Linked List" << endl;
		return;
	}
	Node<T>* curr = head;
	while (curr) {
		if (curr->data == dataMatch) break;
		curr = curr->next;
	}
	if (!curr) {
		cout << "Data not present" << endl;
		return;
	}
	if (curr == tail) {
		tail->next = new Node<T>;
		tail = tail->next;
		tail->data = data;
		return;
	}
	Node<T>* copy = curr->next;
	curr->next = new Node<T>;
	curr = curr->next;
	curr->data = data;
	curr->next = copy;
}

template <typename T>
void SinglyLinkedLinear<T>::display() {
	if (!head) {
		cout << "Empty Linked List" << endl;
		return;
	}
	Node<T>* curr = head;
	while (curr)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
}

template <typename T>
void SinglyLinkedLinear<T> ::deleteHead() {
	if (!head) {
		cout << "Empty Linked List" << endl;
		return;
	}
	if (head == tail) {
		head = NULL;
		tail = NULL;
		return;
	}
	Node<T>* copy = head;
	head = head->next;
	delete copy;
}

template <typename T>
void SinglyLinkedLinear<T>::deleteRear() {
	if (!head) {
		cout << "Empty Linked List" << endl;
		return;
	}
	if (head == tail) {
		head = NULL;
		tail = NULL;
		return;
	}
	Node<T>* curr = head;
	while (curr->next != tail) curr = curr->next;
	tail = curr;
	curr = curr->next;
	tail->next = NULL;
	delete curr;
}

template <typename T>
void SinglyLinkedLinear<T>::del(T data) {
	if (!head) {
		cout << "Empty linked list" << endl;
		return;
	}
	if (head->data == data) {
		if (head == tail) {
			head = NULL;
			tail = NULL;
			return;
		}
		Node<T>* curr = head;
		head = head->next;
		delete curr;
		return;
	}
	Node<T>* prev = NULL;
	Node<T>* curr = head;
	while (curr && curr->data != data) {
		prev = curr;
		curr = curr->next;
	}
	if (!curr) {
		cout << "data not found" << endl;
		return;
	}
	if (curr == tail) {
		tail = prev;
		prev->next = NULL;
		delete curr;
		return;
	}
	Node<T>* copy = curr->next;
	prev->next = copy;
	delete curr;
}