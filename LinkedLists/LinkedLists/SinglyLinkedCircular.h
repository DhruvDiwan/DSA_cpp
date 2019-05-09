#pragma once
#include<Node.h>
#include<iostream>
using namespace std;

template <typename T>
class SinglyLinkedCircular
{
private:
	Node<T>* head, * tail;
	int size;
public:
	SinglyLinkedCircular();
	void insertHead(T data);
	void insertRear(T data);
	void display();
	void insertAfter(T matchData, T data);
	void delHead();
	void delRear();
	void del(T data);
	T getHead();
	T getTail();
};


template <typename T>
SinglyLinkedCircular<T> ::SinglyLinkedCircular() {
	head = NULL;
	tail = NULL;
	size = 0;
}
template <typename T>
void SinglyLinkedCircular<T> ::insertHead(T data) {
	size++;
	if (!head) {
		head = new Node<T>;
		head->data = data;
		tail = head;
		tail->next = head;
		head->next = tail;
		return;
	}
	Node<T>* temp = new Node<T>;
	temp->data = data;
	temp->next = head;
	tail->next = temp;
	head = temp;
}

template <typename T>
void SinglyLinkedCircular<T> ::insertRear(T data) {
	size++;
	if (!head) {
		head = new Node<T>;
		head->data = data;
		tail = head;
		tail->next = head;
		head->next = tail;
		return;
	}
	tail->next = new Node<T>;
	tail->next->data = data;
	tail = tail->next;
	tail->next = head;
}

template <typename T>
void SinglyLinkedCircular<T> ::display() {
	if (!head) {
		cout << "Empty Linked List" << endl;
		return;
	}
	Node<T>* curr = head;
	for (int i = 0; i < size; i++)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
}

template <typename T>
void SinglyLinkedCircular<T> ::insertAfter(T matchData, T data) {
	if (!head) {
		cout << "Empty linked list , '" << matchData << "' not found" << endl;
		return;
	}
	size++;
	if (head->data == matchData) {
		if (head == tail) {
			head->next = new Node<T>;
			head->next->data = data;
			tail = head->next;
			tail->next = head;
			return;
		}
		Node<T>* copy = head->next;
		head->next = new Node<T>;
		head->next->data = data;
		head->next->next = copy;
		return;
	}
	Node<T>* curr = head;
	do
	{
		if (curr->data == matchData) break;
		curr = curr->next;
	} while (curr != head);
	if (curr == head) {
		cout << "'" << matchData << "' not found" << endl;
		size--;
		return;
	}
	if (curr == tail) {
		tail->next = new Node<T>;
		tail = tail->next;
		tail->data = data;
		tail->next = head;
		return;
	}
	Node<T>* copy = curr->next;
	curr->next = new Node<T>;
	curr = curr->next;
	curr->data = data;
	curr->next = copy;
}

template <typename T>
void SinglyLinkedCircular<T> ::delHead() {
	if (!head) {
		cout << "Empty Linked List" << endl;
		return;
	}
	size--;
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
void SinglyLinkedCircular<T> ::delRear() {
	if (!head) {
		cout << "Empty Linked List" << endl;
		return;
	}
	size--;
	if (head == tail) {
		head = NULL;
		tail = NULL;
		return;
	}
	Node<T>* curr = head;
	while (curr->next != tail) curr = curr->next;
	Node<T> * copy = tail;
	tail = curr;
	tail->next = NULL;
	delete copy;
}

template <typename T>
void SinglyLinkedCircular<T>::del(T data) {
	if (!head) {
		cout << "Empty Linked List" << endl;
		return;
	}
	size--;
	if (head->data == data) {
		if (head == tail) {
			head = NULL;
			tail = NULL;
			return;
		}
		Node<T>* copy = head;
		head = head->next;
		delete copy;
		return;
	}
	Node<T>* prev = NULL;
	Node<T>* curr = head;
	do
	{
		if (curr->data == data) break;
		prev = curr;
		curr = curr->next;
	} while (curr != head);
	if (curr == head) {
		cout << "'" << data << "' not found" << endl;
		size++;
		return;
	}
	if (curr == tail) {
		size++;
		delRear();
		return;
	}
	Node<T>* copy = curr->next;
	prev->next = copy;
	delete curr;
}


template <typename T>
T SinglyLinkedCircular<T>::getHead() {
	return head->data;
}

template <typename T>
T SinglyLinkedCircular<T>::getTail() {
	return tail->data;
}