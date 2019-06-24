#include<2_4tree.h>
#include<fstream>
#include <sstream>


void test(string testName)
{
	tree<int> tr;
	string tmpTestName = testName;
	string outTestFileName = testName.append("-out.txt");
	string inTestFileName = tmpTestName.append("-in.txt");
	tr.setOutputStream(outTestFileName);
	tr.setInputStream(inTestFileName);
	string line;
	tr.display();
	while (getline(cin, line))
	{
		istringstream iss(line);
		string cmd;
		int a;
		if (!(iss >> cmd >> a)) { break; } // error
		if (cmd == "insert") tr.insert(a);
		if (cmd == "delete") continue;
		tr.display();
	}
}

bool compare(string fileName1, string fileName2) {
	ifstream in1(fileName1);
	ifstream in2(fileName2);
	string line1, line2;
	while (getline(in1, line1)) {
		getline(in2, line2);
		if (!line2.length())
			return false;
		if (line1 != line2)
			return false;
	}
	getline(in2, line2);
	if (line1.length() || line2.length())
		return false;
	return true;
}

int main() {
	test("test-001");
	bool result = compare("test-001-expected.txt", "test-001-out.txt");
	if (result)
		cout << "pass";
	else
		cout << "fail";
	cout << "\n";
	return 0;
}