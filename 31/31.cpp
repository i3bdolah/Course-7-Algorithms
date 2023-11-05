#include <iostream>
#include <string>
using namespace std;

string EnterString(string msg) {
	string temp;
	cout << msg << endl;
	getline(cin, temp);

	return temp;
}

char EnterChar(string msg) {
	char temp;
	cout << msg << endl;
	cin >> temp;

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

int CalcCharInString(string str, char chr) {
	int count = 0;
	string str_temp = toLowerCase(str);
	char chr_temp = tolower(chr);


	for (int i = 0; i < str_temp.length(); i++)
	{
		if (str_temp[i] == chr_temp)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	string str = EnterString("Enter The String : ");
	char chr = EnterChar("\nEnter The Character To Search: ");

	cout << "\nLetter searched for is = " << chr;
	cout << "\nCount = " << CalcCharInString(str, chr);
}