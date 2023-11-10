#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReplaceWordInString(string targetWord, string toChangeWord, string allWords) {
	int pos = 0;

	while ((pos = allWords.find(targetWord)) != string::npos)
	{
		allWords.replace(pos, targetWord.length(), toChangeWord);
	}
	return allWords;
}

int main()
{

	string str = "Hi, Im Abdullah working in Jeddah Airports Company Abdullah .";
	string targetWord = "Abdullah";
	string toChangeWord = "3bdullah";

	cout << "\n";
	cout << ReplaceWordInString(targetWord,toChangeWord,str) << endl;
}