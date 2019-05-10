// Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<queue.h>
int main()
{
	queue<int> q;
	q.display();
	q.enqueue(0);
	cout << q.isEmpty() << endl;
	q.display();
	for (int i = 1; i < 10; i++) {
		q.enqueue(i);
		q.display();
	}
	for (int i = 0; i < 10; i++)
	{
		q.dequeue();
		q.display();
	}
	cout << q.isEmpty();
}