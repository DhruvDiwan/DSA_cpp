#include<iostream>
#include<SinglyLinkedLinear.h>
#include<SinglyLinkedCircular.h>
#include<DoublyLinkedLinear.h>
using namespace std;

int main() {
// Testing singly linked linear
	//SinglyLinkedLinear<int> ll;
	//ll.display();
	//ll.insertHead(1);
	//ll.display();
	//ll.insertRear(2);
	//ll.display();
	//ll.insertAfter(2, 3);
	//ll.display();
	//ll.del(3);
	//ll.display();
	//ll.del(1);
	//ll.display();
	//ll.del(2);
	//ll.display();

// Testing singly linked circularly
	//SinglyLinkedCircular<int> cLL;
	//cLL.display();
	//cLL.insertAfter(1, 2);
	//for (int i = 10; i >= 1; i--) {
	//	cLL.insertHead(i);
	//	cLL.display();
	//}
	//for (int i = 11; i <= 15; i++) {
	//	cLL.insertRear(i);
	//	cLL.display();
	//}
	//cout << "Head " << cLL.getHead() << endl;
	//cout << "Tail " << cLL.getTail() << endl;
	//cLL.insertAfter(12, 12);
	//cLL.display();
	//cLL.insertAfter(15, 16);
	//cLL.display();
	//cout << "Tail " << cLL.getTail() << endl;
	//cLL.insertAfter(1, 1);
	//cLL.display();
	//cout << "Head " << cLL.getHead() << endl;
	//cLL.delHead();
	//cLL.display();
	//cout << "Head " << cLL.getHead() << endl;
	//cLL.delHead();
	//cLL.display();
	//cout << "Head " << cLL.getHead() << endl;
	//cLL.insertHead(1);
	//cLL.display();
	//cout << "Head " << cLL.getHead() << endl;
	//cLL.delRear();
	//cLL.display();
	//cout << "Tail " << cLL.getTail() << endl;
	//cLL.del(10);
	//cLL.display();
	//cLL.insertAfter(9, 10);
	//cLL.display();
	//cLL.del(1);
	//cLL.display();
	//cout << "Head " << cLL.getHead() << endl;
	//cLL.insertHead(1);
	//cLL.display();
	//cLL.del(15);
	//cLL.display();
	//cLL.del(12);
	//cout << "Tail " << cLL.getTail() << endl;
	//for (int i  = 14; i > 0; i--)
	//{
	//	cLL.del(i);
	//	cLL.display();
	//}

	// Testing doubly linked linear
	DoublyLinkedLinear<int> dLL;
	dLL.display();
	dLL.insertHead(10);
	dLL.display();
	cout << "Head " << dLL.getHead() << endl;
	cout << "Tail " << dLL.getTail() << endl << endl;
	dLL.insertAfter(10, 11);
	dLL.insertAfter(1, 11);
	cout << endl << endl;
	dLL.display();
	cout << "Head " << dLL.getHead() << endl;
	cout << "Tail " << dLL.getTail() << endl << endl;
	for (int i = 9; i >= 0; i--)
	{
		dLL.insertHead(i);
		dLL.display();
		cout << "Head " << dLL.getHead() << endl;
		cout << "Tail " << dLL.getTail() << endl << endl;
	}
	dLL.insertRear(12);
	dLL.display();
	cout << "Head " << dLL.getHead() << endl;
	cout << "Tail " << dLL.getTail() << endl << endl;
	dLL.insertAfter(12, 13);
	dLL.display();
	cout << "Head " << dLL.getHead() << endl;
	cout << "Tail " << dLL.getTail() << endl << endl;
	dLL.delHead();
	dLL.display();
	cout << "Head " << dLL.getHead() << endl;
	cout << "Tail " << dLL.getTail() << endl << endl;
	dLL.delRear();
	dLL.display();
	cout << "Head " << dLL.getHead() << endl;
	cout << "Tail " << dLL.getTail() << endl << endl;
	dLL.del(12);
	dLL.display();
	cout << "Head " << dLL.getHead() << endl;
	cout << "Tail " << dLL.getTail() << endl << endl;
	dLL.del(10);
	dLL.display();
	cout << "Head " << dLL.getHead() << endl;
	cout << "Tail " << dLL.getTail() << endl << endl;
	dLL.del(11);
	dLL.display();
	cout << "Head " << dLL.getHead() << endl;
	cout << "Tail " << dLL.getTail() << endl << endl;
	dLL.display();
	for (int i = 1; i < 10; i++)
	{
		dLL.del(i);
		dLL.display();
	}
	return 0;
}