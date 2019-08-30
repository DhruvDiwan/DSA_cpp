// red_black_tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <red_black.h>
#include<red_black_test.h>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>

int randomize()
{
	return (rand() % 10000);
}

Node<int>*  construct_tree() {
	RBT<int> rb;
	vector<int> vect(10);
	generate(vect.begin(), vect.end(), randomize);
	for (unsigned int i = 0; i < vect.size(); i++) {
		rb.insert(vect[i]);
	}
	return rb.get_root_ptr();
}

void build_destroy_tree(unsigned int tree_count) {
	RBT<int> rb;
	vector<int> vect(tree_count);
	generate(vect.begin(), vect.end(), randomize);

	for (unsigned int i = 0; i < vect.size(); i++)
	{
		cout << vect[i] << " ";
	}
	cout << endl;

	for (unsigned int i = 0; i < vect.size(); i++) {
		cout << "Inserting " << vect[i] << endl;
		rb.insert(vect[i]);
		rb.display();
		cout << "Count is " << rb.count() << endl << endl;
	}

	for (int i = vect.size() - 1; i >= 0; i--) {
		cout << "Deleting " << vect[i] << endl;
		rb.del(vect[i]);
		rb.display();
		cout << "Count is " << rb.count() << endl << endl;
	}
}

void run_tests(int test_cases, unsigned int tree_count)
{
	for (int test_number = 0; test_number < test_cases; test_number++) {
		build_destroy_tree(tree_count);
		cout << "Test " << test_number + 1 << " done\n---------------------------------\n\n";
	}
}

void cmd_pt() {
	RBT<int> rb;
	string line;
	while (getline(cin, line))
	{
		istringstream iss(line);
		string cmd; // command
		int a;
		if (!(iss >> cmd >> a)) { break; } // error
		if (cmd == "insert") {
			try
			{
				rb.insert(a);
				cout << "Insert " << a << " : "; rb.display();
			}
			catch (InsertionError e)
			{
				cout << endl << "Insert " << a << " : " << e.what() << endl;
				rb.display();
				cout << endl;
			}
		}
		else if (cmd == "delete") {
			try
			{
				rb.del(a);
				cout << "Delete " << a << " : "; rb.display();
			}
			catch (DeletionError e)
			{
				cout << endl << "Delete " << a << " : " << e.what() << endl;
				rb.display();
				cout << endl;
			}
		}
		else {
			cout << "Allowed format of input :\nInsert / Delete data\n\n";
		}
	}
}

void file_IO(string inFileName, string outFileName) { // if a outFile exists , it gets overwritten
	fstream inFile, outFile;
	streambuf* stream_buffer_cout, * stream_buffer_cin;

	inFile.open(inFileName, ios::in);
	stream_buffer_cin = cin.rdbuf();// Backup streambuffers of  cout
	streambuf* stream_buffer_in_file = inFile.rdbuf();// Get the streambuffer of the file
	cin.rdbuf(stream_buffer_in_file); // redirect cin to inFile

	outFile.open(outFileName, ios::out);
	stream_buffer_cout = cout.rdbuf();// Backup streambuffers of  cout
	streambuf* stream_buffer_out_file = outFile.rdbuf();// Get the streambuffer of the file
	cout.rdbuf(stream_buffer_out_file);// Redirect cout to file

	cmd_pt();

	inFile.close();
	outFile.close();
	cout.rdbuf(stream_buffer_cout);// Redirect cout back to screen
	cin.rdbuf(stream_buffer_cin);// Redirect cin back to stdin
}

void pair_file_IO(string testName) {
	string tmpTestName = testName;
	string inFileName = testName.append(".txt");
	string outFileName = tmpTestName.append("-result.txt");
	file_IO(inFileName, outFileName);
}


int main() {
	//run_tests(2, 15);
	//file_IO("in_1.txt", "out_1.txt");
	//pair_file_IO("test-001");
	//cmd_pt();
	for (int i = 0; i < 10; i++) {
		cout << "Test " << i + 1;
		Test<int> test(construct_tree());
		if (test.get_result()) cout << " Passed";
		else cout << " Failed";
		cout << endl;
	}
	return 0;
}
