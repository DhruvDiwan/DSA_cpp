#pragma once
#include<Node.h>
#include<iostream>
using namespace std;

template <typename T>
class DoublyLinkedLinear
{
public:
	DoublyLinkedLinear();
	T getTail();
	T getHead();
	void display();
	void insertHead(T data);
	void insertRear(T data);
	void insertAfter(T matchData, T data);
	void delHead();
	void delRear();
	void del(T data);
private:
	Node<T>* head, * tail;
};

template<typename T>
DoublyLinkedLinear<T>::DoublyLinkedLinear()
{
	head = NULL;
	tail = NULL;
}

template <typename T>
T DoublyLinkedLinear<T>::getHead() {
	return head->data;
}

template <typename T>
T DoublyLinkedLinear<T>::getTail() {
	return tail->data;
}

template <typename T>
void DoublyLinkedLinear<T> :: display() {
	if (!head) {
		cout << "Empty Linked List " << endl;
		return;
	}
	Node<T>* curr = head;
	while (curr) {
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
}

template <typename T>
void DoublyLinkedLinear<T> ::insertHead(T data) {
	if (!head) {
		head = new Node<T>;
		head->data = data;
		tail = head;
		return;
	}
	Node<T>* copy = head;
	head->prev = new Node<T>;
	head = head->prev;
	head->data = data;
	head->next = copy;
}

template <typename T>
void DoublyLinkedLinear<T> ::insertRear(T data) {
	if (!head) {
		head = new Node<T>;
		head->data = data;
		tail = head;
		return;
	}
	Node<T>* copy = tail;
	tail->next = new Node<T>;
	tail = tail->next;
	tail->data = data;
	tail->prev = copy;
}

template <typename T>
void DoublyLinkedLinear<T> ::insertAfter(T matchData, T data) {
	if (!head) {
		cout << "Empty Linked List , couldn't find '" << matchData << "'" << endl;
		return;
	}
	Node<T>* curr = head;
	while (curr && curr->data != matchData) curr = curr->next;
	if (!curr) {
		cout << "'" << matchData << "' not found" << endl;
		return;
	}
	if (head == curr) {
		if (head == tail) {
			head->next = new Node<T>;
			head->next->data = data;
			head->next->prev = head;
			tail = head->next;
			return;
		}
		Node<T>* copy = head->next;
		head->next = new Node<T>;
		head->next->data = data;
		head->next->next = copy;
		copy->prev = head->next;
		head->next->prev = head;
		return;
	}
	if (curr == tail) {
		tail->next = new Node<T>;
		tail->next->data = data;
		tail->next->prev = tail;
		tail = tail->next;
		return;
	}
	Node<T>* copy = curr->next;
	curr->next = new Node<T>;
	curr->next->data = data;
	curr->next->next = copy;
	copy->prev = curr;
}

template <typename T>
void DoublyLinkedLinear<T> ::delHead() {
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
	head->prev = NULL;
	delete copy;
}

template <typename T>
void DoublyLinkedLinear<T> ::delRear() {
	if (!head) {
		cout << "Empty Linked List" << endl;
		return;
	}
	if (head == tail) {
		head = NULL;
		tail = NULL;
		return;
	}
	Node<T>* copy = tail;
	tail = tail->prev;
	tail->next = NULL;
	delete copy;
}

template <typename T>
void DoublyLinkedLinear<T> ::del(T data) {
	if (!head) {
		cout << "Empty Linked List" << endl;
		return;
	}
	Node<T>* curr = head;
	while (curr && curr->data != data) curr = curr->next;
	if (!curr) {
		cout << "'" << data << "' not found" << endl;
		return;
	}
	if (head == curr) {
		if (head == tail) {
			head = NULL;
			tail = NULL;
			return;
		}
		Node<T>* copy = head;
		head = head->next;
		head->prev = NULL;
		delete copy;
		return;
	}
	if (curr == tail) {
		Node<T>* copy = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete copy;
		return;
	}
	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;
	delete curr;
}