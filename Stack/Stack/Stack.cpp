#include <iostream>
using namespace std;
template <typename T>
class Stack
{
private:
	T* stack, * top;
public:
	Stack(int size);
	~Stack();
	bool isEmpty();
	void push(T data);
	void pop();
	int size();
	void display();
};


template <typename T>
Stack<T>::Stack(int size) {
	stack = new T[size];
	top = NULL;
}

template <typename T>
Stack<T>::~Stack()
{
}

template <typename T>
void Stack<T> ::push(T data) {
	if (top == NULL) {
		top = stack;
	}
	if (top == *(&stack + 1)) {
		cout << "Stack overflow" << endl;
		return;
	}
	*(top++) = data;
}
template <typename T>
void Stack<T> ::pop() {
	if (top == NULL) {
		cout << "Stack underflow" << endl;
		return;
	}
	if (top == stack) {
		top = NULL;
		return;
	}
	top--;
}

template <typename T>
bool Stack<T> ::isEmpty() {
	return bool(top == NULL);
}

template <typename T>
int Stack<T> ::size() {
	if (top == NULL) return 0;
	return (top - stack);
}

template <typename T>
void Stack<T> ::display() {
	T* ptr = stack;
	if (top == NULL) {
		cout << "Empty Stack\n";
		return;
	}
	while (ptr != top) {
		cout << *(ptr++) << " ";
	}
	cout << endl;
}
int main()
{
	Stack<int> st(10);
	cout << st.size() << endl;
	st.push(0);
	cout << st.size() << endl;
	st.display();
}
