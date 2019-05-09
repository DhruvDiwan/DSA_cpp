#pragma once
#include<iostream>
template <typename T>
class Node
{
public:
	T data;
	Node<T>* next, * prev;
	Node();
	~Node();
};

template <typename T>
Node<T>::Node()
{
	prev = NULL;
	next = NULL;
}

template <typename T>
Node<T>::~Node()
{
}
