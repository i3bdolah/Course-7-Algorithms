#include <iostream>
#include <string>
#include <vector>
using namespace std;

string EnterString(string msg) {
	string temp;
	cout << msg << endl;
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

void PrintVector(vector <string> vector) {

	cout << '\n';
	cout << "Tokens = " << vector.size() << endl;
	for (string &elementInVector : vector)
	{
		cout << '|' << elementInVector << '|' << endl;
	}
}

int main()
{
	string sentence = EnterString("Enter your sentence : ");
	//string seperator = EnterString("Enter your seperator : ");

	PrintVector(splitToVector(sentence, " "));
}