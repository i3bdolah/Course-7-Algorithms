#include <iostream>
#include <string>
using namespace std;

string EnterString(string msg) {
	string temp;
	cout << msg << endl;
	getline(cin, temp);

	return temp;
}

bool IfVowelLetter(char chr) {
	char lowerChr = tolower(chr);

	return (lowerChr == 'a' || lowerChr == 'e' || lowerChr == 'i' || lowerChr == 'o' || lowerChr == 'u');
}

int CountVowelLetters(string str) {
	int counter = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if (IfVowelLetter(str[i]))
		{
			counter++;
		}
	}
	return counter;
}

int main()
{
	string entered = EnterString("Enter The Letter : ");

	cout << "The Number of Vowel Letters is = " << CountVowelLetters(entered) << endl;

}