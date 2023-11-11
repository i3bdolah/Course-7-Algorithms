#include <iostream>
#include <string>
#include <vector> 
using namespace std;

string toLowerCase(string str) {
	bool isFirstLetter = true;

	for (int i = 0; i < str.length(); i++)
	{
		str[i] = tolower(str[i]);
	}
	return str;
}

vector <string> splitToVector(string sentence, string seperator) {
	vector <string> wordsSeperated;
	int pos = 0;
	string strTemp;

	while ((pos = sentence.find(seperator)) != string::npos)
	{
		strTemp = sentence.substr(0, pos);
		if (strTemp != seperator)
		{
			wordsSeperated.push_back(strTemp.substr(0, (pos)));
		}

		sentence.erase(0, pos + seperator.length());
	}

	if (sentence != "" && sentence != seperator)
	{
		wordsSeperated.push_back(sentence);
	}

	return wordsSeperated;
}

string JoinVector(vector <string> vector, string seperator) {
	string wordsJoined;

	for (string& name : vector)
	{
		wordsJoined = wordsJoined + name + seperator;
	}

	return wordsJoined.substr(0, wordsJoined.length() - seperator.length());
}

string ReplaceWordInString(string targeted, string replacemnet, string allWords, bool isCaseSensitive = 1) {
	vector <string> splittedString = splitToVector(allWords, " ");
	
	if (isCaseSensitive)
	{
		for (string& word : splittedString)
		{
			if (word == targeted)
			{
				word = replacemnet;
			}
		}
	}
	else {
		for (string& word : splittedString)
		{
			if (toLowerCase(word) == toLowerCase(targeted))
			{
				word = replacemnet;
			}
		}
	}
	return JoinVector(splittedString, " ");
}

int main()
{

	string str = "Hi, Im Abdullah working in JEDCO. Abdullah .";
	string targetWord = "abdullah";
	string toChangeWord = "Salem";

	cout << "\n";
	cout << ReplaceWordInString(targetWord, toChangeWord, str, 1) << endl;
}