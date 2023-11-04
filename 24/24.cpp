#include <iostream>
#include <string>
using namespace std;

string EnterString() {
	string temp;
	cout << "Enter The String : " << endl;
	getline(cin, temp);

	return temp;
}

string UppercaseForFirstLetters(string str) {
	bool isFirstLetter = true;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ' && isFirstLetter)
		{
			str[i] = toupper(str[i]);
		}

		isFirstLetter = (str[i] == ' ' ? true : false);
	}
	return str;
}

int main()
{
	string str = EnterString();

	cout << "\nAfter Conversion : \n";
	cout << UppercaseForFirstLetters(str) << endl;
}