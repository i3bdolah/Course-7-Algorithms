#include <iostream>
#include <string>
using namespace std;

string EnterString() {
	string temp;
	cout << "Enter The String : " << endl;
	getline(cin, temp);

	return temp;
}

string toLowerCase(string str) {
	bool isFirstLetter = true;

	for (int i = 0; i < str.length(); i++)
	{
		str[i] = tolower(str[i]);
	}
	return str;
}

string toUpperCase(string str) {
	bool isFirstLetter = true;

	for (int i = 0; i < str.length(); i++)
	{
		str[i] = toupper(str[i]);
	}
	return str;
}

int main()
{
	string str = EnterString();

	cout << "\ntoLowerCase : \n";
	cout << toLowerCase(str) << endl;

	cout << "\ntoUpperCase : \n";
	cout << toUpperCase(str) << endl;
}