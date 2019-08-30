#pragma once
#include<red_black.h>
template<typename T>
class Test
{
public:
	Test(Node<T>* root);
	~Test();
	bool get_result();

private:
	Node<T>* root;
	int g_count;
	bool test_main();
	bool test_node(Node<T>* n, int count);
};

template<typename T>
Test<T>::Test(Node<T>* r)
{
	g_count = -1;
	root = r;
}

template<typename T>

Test<T>::~Test()
{
}

template<typename T>
inline bool Test<T>::get_result()
{
	return test_main();
}

template<typename T>
inline bool Test<T>::test_main()
{
	return test_node(root, 0);
}

template<typename T>
inline bool Test<T>::test_node(Node<T>* n, int count)
{
	if (!n) return true;
	if ((n == root && n->c != 'b') ||
		(n->lf && (n->lf->data > n->data || (n->c == 'r' && n->lf->c == 'r'))) || 
		(n->rt && (n->rt->data <= n->data || (n->c == 'r' && n->rt->c == 'r')))
		) 
		return false;
	if (n->c == 'b') count++;
	if (!n->lf && !n->rt) {
		if (g_count == -1) g_count = count;
		else {
			if (count == g_count) return true;
			else return false;
		}
	}
	return test_node(n->lf, count) && test_node(n->rt, count);
}
