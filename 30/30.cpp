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

int CalcCharInString(string str, char chr) {
	int count = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == chr)
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