// red_black_tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<red_black.h>
#include<vector>
#include<algorithm>
#include <ctime> 
#include <cstdlib>


int randomize()
{
	return (rand() % 1000);
}



int main()
{
	RBT<int> rb;
	srand(time(NULL));
	vector<int> vect(10);  
	generate(vect.begin(), vect.end(), randomize);

	for (int i = 0; i < 10; i++)
	{
		output << vect[i] << " ";
	}
	output << endl;

	for (int i = 0; i < vect.size(); i++) {
		output << "Inserting " << vect[i] << endl;
		rb.insert(vect[i]);
		//rb.insert(i);
		rb.display();
		output << endl;
	}
	
	cout << "Check output \n";

}

