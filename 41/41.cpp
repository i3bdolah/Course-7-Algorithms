#include <iostream>
#include <string>
#include <vector>
using namespace std;

string EnterString(string msg) {
	string temp;
	cout << msg;
	cout << "\n\n";
	getline(cin, temp);

	return temp;
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

vector <string> ReverseVector(vector <string> vector1) {
	vector <string> newVector;

	for (int i = vector1.size() - 1; i >= 0; i--)
	{
		newVector.push_back(vector1.at(i));
	}
	return newVector;
}

string JoinVector(vector <string> vector, string seperator) {
	string wordsJoined;

	for (string& name : vector)
	{
		wordsJoined = wordsJoined + name + seperator;
	}

	return wordsJoined.substr(0, wordsJoined.length() - seperator.length());
}


int main()
{
	string sentence = EnterString("Enter your sentence : ");
	vector <string> splittedVector = splitToVector(sentence, " ");
	vector <string> reverseSplitted = ReverseVector(splittedVector);
	string joinReverseSplitted = JoinVector(reverseSplitted, " ");

	cout << "\n";
	cout << joinReverseSplitted << endl;
}