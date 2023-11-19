#include <iostream>
#include <string>
#include <vector> 
#include <fstream> 
#include <iomanip>
using namespace std;

const string FilePath = "C:\\Users\\Abdullah\\Desktop\\Clients-Table.txt";

struct stBankAccount
{
	string bank_acc;
	string pin_code;
	string name;
	string phone;
	double acc_balance = 0;
};

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

stBankAccount LineToClientStructure(string line) {
	vector <string> splittedLine;
	stBankAccount readyClient;
	splittedLine = splitToVector(line);

	readyClient.bank_acc = splittedLine[0];
	readyClient.pin_code = splittedLine[1];
	readyClient.name = splittedLine[2];
	readyClient.phone = splittedLine[3];
	readyClient.acc_balance = stod(splittedLine[4]);

	return readyClient;
}

vector <stBankAccount> LoadDataFromFile(string FilePath) {
	vector <stBankAccount> vClients;
	fstream MyFile;

	MyFile.open(FilePath, ios::in);

	if (MyFile.is_open()) {
		string line;
		stBankAccount client1;
		while (getline(MyFile, line))
		{
			client1 = LineToClientStructure(line);
			vClients.push_back(client1);
		}
		MyFile.close();
	}
	return vClients;
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

void PrintRows(stBankAccount client) {
	cout << "| " << left << setw(20) << client.bank_acc;
	cout << "| " << left << setw(20) << client.pin_code;
	cout << "| " << left << setw(20) << client.name;
	cout << "| " << left << setw(20) << client.phone;
	cout << "| " << left << setw(20) << client.acc_balance << endl;
}

void PrintImportedLines(vector <stBankAccount> StructuresFromFile) {
	HugeLine();
	PrintHeaders(StructuresFromFile.size());
	for (stBankAccount& structure : StructuresFromFile)
	{
		PrintRows(structure);
	}
	HugeLine();
}

void ReadClients() {
	vector <stBankAccount> StructuresFromFile = LoadDataFromFile(FilePath);
	PrintImportedLines(StructuresFromFile);
}

int main()
{
	ReadClients();
}