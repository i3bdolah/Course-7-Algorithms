#include <iostream>
#include <string>
using namespace std;

char EnterChar() {
	char temp;
	cout << "Enter The Char : " << endl;
	cin >> temp;

	return temp;
}

char InvertChar(char chr) {
	return isupper(chr) ? tolower(chr) : toupper(chr);
}

int main()
{
	char chr = EnterChar();

	cout << "\InvertChar : \n";
	cout << InvertChar(chr) << endl;
}