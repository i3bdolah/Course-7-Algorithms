#include <iostream>
#include <string>
using namespace std;

string EnterString() {
	string temp;
	cout << "Enter The String : " << endl;
	getline(cin, temp);

	return temp;
}

char InvertChar(char chr) {
	return isupper(chr) ? tolower(chr) : toupper(chr);
}

string InvertAll(string& str) {
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = InvertChar(str[i]);
	}
	return str;
}

int main()
{
	string str = EnterString();

	cout << "\nInvertAll : \n";
	cout << InvertAll(str) << endl;
}