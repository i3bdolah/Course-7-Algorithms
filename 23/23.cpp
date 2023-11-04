#include <iostream>
#include <string>
using namespace std;

string EnterString() {
	string temp;
	cout << "Enter The String : " << endl;
	getline(cin, temp);

	return temp;
}

void PrintFirstLetterInWord(string str) {
	bool isFirstLetter = true;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ' && isFirstLetter)
		{
			cout << str[i] << endl;
		}

		isFirstLetter = (str[i] == ' ' ? true : false);
	}
}

int main()
{
	PrintFirstLetterInWord(EnterString());
}