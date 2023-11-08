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

string TrimRight(string str) {
	int lastIndex = str.length() - 1;
	while (str[lastIndex] == ' ')
	{
		str.erase(lastIndex);
		lastIndex = str.length() - 1;
	}
	return str;
}

string TrimLeft(string str) {
	while (str[0] == ' ')
	{
		str.erase(0,1);
	}
	return str;
}

string TrimAll(string str) {
	return TrimLeft(TrimRight(str));
}


int main()
{
	string sentence = EnterString("Enter your sentence : ");

	cout << '|' << TrimRight(sentence) << '|' << endl;
	cout << '|' << TrimLeft(sentence) << '|' << endl;
	cout << '|' << TrimAll(sentence) << '|' << endl;

}