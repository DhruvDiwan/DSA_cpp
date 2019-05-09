#include<iostream>
#include<SinglyLinkedLinear.h>
using namespace std;





int main() {
	SinglyLinkedLinear<int> ll;
	ll.display();
	ll.insertHead(1);
	ll.display();
	ll.insertRear(2);
	ll.display();
	ll.insertAfter(2, 3);
	ll.display();
	ll.del(3);
	ll.display();
	ll.del(1);
	ll.display();
	ll.del(2);
	ll.display();
	return 0;
}