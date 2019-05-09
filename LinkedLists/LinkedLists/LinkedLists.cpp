#include<iostream>
using namespace std;

template <typename T>
class Node
{
public:
	T data;
	Node<T>* next, * prev;
	Node() {
		prev = NULL;
		next = NULL;
	}
};

template <typename T>
class SinglyLinkedLinear
{
private:


public:
	Node<T>* head, * tail;
	SinglyLinkedLinear() {
		head = NULL;
		tail = NULL;
	}

	void insertHead(T data) {
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

	void insertRear(T data) {
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

	void insertAfter(T dataMatch , T data){
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

	void display() {
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
	void deleteHead() {
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
	void deleteRear() {
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

	void del(T data) {
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
		while ((!curr) && curr->data != data) {
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
		prev->next = curr->next;
		delete curr;
	}
};

int main() {
	SinglyLinkedLinear<string> ll;
	ll.display();
	ll.insertHead("one");
	ll.display();
	ll.insertRear("two");
	ll.display();
	ll.insertAfter("two", "three");
	ll.display();
	ll.del("three");
	ll.display();
/*	ll.del("one");
	ll.display();
	ll.del("two");
	ll.display();*/

	return 0;
}