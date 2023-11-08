#include <iostream>
#include <string>
#include <vector>
using namespace std;

string EnterString(string msg) {
	string temp;
	cout << msg << endl;
	getline(cin, temp);

	return temp;
}

string JoinVector(vector <string> vector, string seperator) {
	string wordsJoined;

	for (string& name : vector)
	{
		wordsJoined = wordsJoined + name + seperator;
	}

	return wordsJoined.substr(0, wordsJoined.length() - seperator.length());
}

void PrintVector(vector <string> vector) {

	cout << '\n';
	cout << "Tokens = " << vector.size() << endl;
	for (string& elementInVector : vector)
	{
		cout << '|' << elementInVector << '|' << endl;
	}
}

int main()
{
	vector <string> names = { "Abdullah", "Mazen", "Mohammed" };

	PrintVector(names);
	cout << "\n\nAfter Join : |" << JoinVector(names, "-") << "|" << endl;
}