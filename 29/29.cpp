#include <iostream>
#include <string>
using namespace std;

string EnterString() {
	string temp;
	cout << "Enter The String : " << endl;
	getline(cin, temp);

	return temp;
}

bool isLowercaseLetter(char chr) {
	return (char(chr) >= 97 && char(chr) <= 122) ? true : false;
}

bool isUppercaseLetter(char chr) {
	return (char(chr) >= 65 && char(chr) <= 90) ? true : false;
}

int CalcUppercaseLetters(string str) {
	int uppercase = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if (isUppercaseLetter(str[i]))
		{
			uppercase++;
		}
	}
	return uppercase;
}

int CalcLowercaseLetters(string str) {
	int lowercase = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if (isLowercaseLetter(str[i]))
		{
			lowercase++;
		}
	}
	return lowercase;
}

int main()
{
	string str = EnterString();

	int length = str.length();
	int upperCount = CalcUppercaseLetters(str);
	int lowerCount = CalcLowercaseLetters(str);
	int otherCount = length - (upperCount + lowerCount);

	cout << "\nString Length = " << length;
	cout << "\nString Uppercase count = " << upperCount;
	cout << "\nString Lowercase count = " << lowerCount;
	cout << "\nOthers characters count = " << otherCount;
}