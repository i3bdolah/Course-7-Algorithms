#include <iostream>
using namespace std;

char EnterChar(string msg) {
	char temp;
	cout << msg << endl;
	cin >> temp;

	return temp;
}

bool IfVowelLetter(char chr) {
	char lowerChr = tolower(chr);

	return (lowerChr == 'a' || lowerChr == 'e' || lowerChr == 'i' || lowerChr == 'o' || lowerChr == 'u');
}

int main()
{
	char entered = EnterChar("Enter The Letter : ");

	if (IfVowelLetter(entered))
	{
		cout << "YES: Letter " << entered << " is vowel." << endl;
	}
	else
	{
		cout << "NO: Letter " << entered << " is not vowel." << endl;
	}
}