#include <iostream>
#include <string>
#include <vector> 
using namespace std;

string removePunctuations(string str) {
	for (int i = 0; i < str.length(); i++)
	{
		if (ispunct(str[i])) {
			str.erase(i, 1);
		}
	}
	return str;
}

int main()
{

	string str = "Hi, Im Abdullah working in JEDCO. Abdullah .";


	cout << "\n";
	cout << str << endl;
	cout << removePunctuations(str) << endl;
}