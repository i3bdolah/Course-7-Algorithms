#include <iostream>
#include <string>
#include <vector> 
#include <fstream> 
#include <iomanip>
using namespace std;

const string FilePath = "C:\\Users\\Abdullah\\Desktop\\Clients-Table.txt";

struct sBankAccount
{
	string bank_acc;
	string pin_code;
	string name;
	string phone;
	double acc_balance;
};

string ConvertRecordToLine(sBankAccount client, string seperator = "#//#") {

	string tempRecord = "";

	tempRecord += client.bank_acc + seperator;
	tempRecord += client.pin_code + seperator;
	tempRecord += client.name + seperator;
	tempRecord += client.phone + seperator;
	tempRecord += to_string(client.acc_balance);

	return tempRecord;
}

vector <string> ImportDataFromFile(string FilePath) {
	vector <string> tempVector;
	fstream MyFile;
	MyFile.open(FilePath, ios::in);

	if (MyFile.is_open()) {
		string line;

		while (getline(MyFile, line))
		{
			tempVector.push_back(line);
		}

		MyFile.close();
	}
	return tempVector;
}

vector <string> splitToVector(string sentence, string seperator = "#//#") {
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

string JoinVector(vector <string> vector, string seperator = " ") {
	string wordsJoined;

	for (string& name : vector)
	{
		wordsJoined = wordsJoined + name + seperator;
	}

	return wordsJoined.substr(0, wordsJoined.length() - seperator.length());
}

void SplitAndJoinAllStrings(vector <string>& vLines, string seperator = "#//#", string joiner = " ") {
	for (string& line : vLines)
	{
		vector <string> vTemp = splitToVector(line);
		line = JoinVector(vTemp);
	}
}

void HugeLine() {
	cout << "____________________________________________________________________________________________________" << endl;
}

void PrintHeaders(int vectorSize) {
	cout << "\n\t\t\t\tClient List (" << vectorSize << ") Client(s)." << endl;
	HugeLine();
	cout << "\n| " << left << setw(20) << "Account Number";
	cout << "| " << left << setw(20) << "Pin Code";
	cout << "| " << left << setw(20) << "Client Name";
	cout << "| " << left << setw(20) << "Phone";
	cout << "| " << left << setw(20) << "Balance" << endl;
	HugeLine();
}

void PrintColumns(vector <string> splittedLineToWords) {
	cout << "| " << left << setw(20) << splittedLineToWords.at(0);
	cout << "| " << left << setw(20) << splittedLineToWords.at(1);
	cout << "| " << left << setw(20) << splittedLineToWords.at(2);
	cout << "| " << left << setw(20) << splittedLineToWords.at(3);
	cout << "| " << left << setw(20) << splittedLineToWords.at(4) << endl;
}

void PrintImportedLines(vector <string> LinesFromFile) {
	PrintHeaders(LinesFromFile.size());
	for (string& line : LinesFromFile)
	{
		vector <string> splittedLineToWords = splitToVector(line);
		PrintColumns(splittedLineToWords);
	}
	HugeLine();
}

void ReadClients() {
	vector <string> LinesFromFile = ImportDataFromFile(FilePath);
	PrintImportedLines(LinesFromFile);
}

int main()
{
	ReadClients();
}