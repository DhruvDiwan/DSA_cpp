#pragma once
#include<SinglyLinkedLinear.h>

template <typename T>
class queue
{
public:
	queue();
	void enqueue(T data);
	T dequeue();
	bool isEmpty();
	void display();
private:
	SinglyLinkedLinear<T> q;
};

template <typename T>
queue<T>::queue()
{
}

template <typename T>
void queue<T>::enqueue(T data) {
	q.insertRear(data);
}

template <typename T>
T queue<T>::dequeue() {
	if (q.isEmpty()) {
		cout << "Cannot dequeue element from empty queue";
		return NULL;
	}
	T data = q.getHead();
	q.deleteHead();
	return data;
}

template <typename T>
bool queue<T>::isEmpty() {
	return q.isEmpty();
}

template <typename T>
void queue<T>::display() {
	q.display();
}