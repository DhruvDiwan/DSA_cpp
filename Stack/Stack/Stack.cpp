#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
	T data;
	Node* next;
	Node(T val) {
		data = val;
	}

};


//////////////////////////////////////////////////////////////////////


template <typename T>
class LinkedList {
private:
	Node<T>* head;
public:
	LinkedList();
	void insert(T data);
	void del();
	bool isEmpty();
	int size();
	void display();
};

template <typename T>
void LinkedList<T>::display() {
	if (!head) {
		cout << "Empty stack" << endl;
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
int LinkedList<T> ::size() {
	if (!head) {
		return 0;
	}
	Node<T>* curr = head;
	int count = 0;
	while (curr) {
		count++;
		curr = curr->next;
	}
	return count;
}

template <typename T>
bool LinkedList<T>::isEmpty() {
	return bool(!head);
}
template <typename T>
LinkedList<T> ::LinkedList() {
	head = NULL;
}
template <typename T>
void LinkedList<T>::insert(T data) {
	if (!head) {
		head = new Node<T>(data);
		return;
	}
	Node<T>* curr = head;
	while (curr->next) curr = curr->next;
	curr->next = new Node<T>(data);
}

template <typename T>
void LinkedList<T>::del() {
	if (!head) {
		cout << "Empty stack" << endl;
		return;
	}
	if (!(head->next)) {
		head = NULL;
		return;
	}
	Node<T>* curr = head;
	while (curr->next->next) curr = curr->next;
	Node<T>* deletedNode = curr->next;
	delete deletedNode;
	curr->next = NULL;
}

////////////////////////////////////////////////////////////////

template <typename T>
class Stack
{
private:
	LinkedList<T> stack;
public:
	Stack();
	~Stack();
	bool isEmpty();
	void push(T data);
	void pop();
	int size();
	void display();
};


template <typename T>
Stack<T>::Stack() {
	LinkedList<T> stack;
}

template <typename T>
Stack<T>::~Stack()
{
}

template <typename T>
void Stack<T> ::push(T data) {
	stack.insert(data);
}

template <typename T>
void Stack<T> ::pop() {
	stack.del();
}

template <typename T>
bool Stack<T> ::isEmpty() {
	return stack.isEmpty();
}

template <typename T>
int Stack<T> ::size() {
	return stack.size();
}

template <typename T>
void Stack<T> ::display() {
	stack.display();
}

int main()
{
	Stack<int> st;
	cout << st.isEmpty() << endl;
	for (int i = 0; i < 10 ; i++)
	{
		st.push(i);
		st.display();
	}
	for (int i = 9; i >= 0; i--)
	{
		st.pop();
		st.display();
	}
}
