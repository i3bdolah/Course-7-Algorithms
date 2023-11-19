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

stBankAccount NotFoundClient() {
	stBankAccount temp;

	temp.bank_acc = "NOT FOUND";
	temp.pin_code = "NOT FOUND";
	temp.name = "NOT FOUND";
	temp.phone = "NOT FOUND";
	temp.acc_balance = 0;

	return temp;
}

string EnterString(string msg) {
	string temp;
	cout << msg;
	getline(cin, temp);

	return temp;
}

void CheckCharInput(char& var, string msg) {
	cout << msg;
	cin >> var;
	cout << "\n";
	cin.ignore();
}

vector <string> SplitToVector(string sentence, string seperator = "#//#") {
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
	splittedLine = SplitToVector(line);

	readyClient.bank_acc = splittedLine[0];
	readyClient.pin_code = splittedLine[1];
	readyClient.name = splittedLine[2];
	readyClient.phone = splittedLine[3];
	readyClient.acc_balance = stod(splittedLine[4]);

	return readyClient;
}

vector <stBankAccount> LoadAndStructurizeDataFromFile(string FilePath) {
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

void PrintHeaders() {
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
	HugeLine();
}

void PrintImportedLines(stBankAccount StructuresFromFile) {
	PrintHeaders();
	PrintRows(StructuresFromFile);
}

string JoinClientDataToLine(stBankAccount stClient, string seperator = "#//#") {
	string wordsJoined = "";

	wordsJoined += stClient.bank_acc + seperator;
	wordsJoined += stClient.pin_code + seperator;
	wordsJoined += stClient.name + seperator;
	wordsJoined += stClient.phone + seperator;
	wordsJoined += to_string(stClient.acc_balance);

	return wordsJoined;
}

void SaveDataToFile(string FilePath, vector <stBankAccount> UpdatedStructuresFromFile) {
	fstream MyFile;
	MyFile.open(FilePath, ios::out);

	if (MyFile.is_open()) {
		for (stBankAccount& s : UpdatedStructuresFromFile)
		{
			MyFile << JoinClientDataToLine(s) << endl;
		}
		MyFile.close();
	}
	else
	{
		cout << "\nWe Couldn't open the File" << endl;
	}
}

int isAccountExist(vector <stBankAccount> StructuresFromFile, string AccountNum) {
	for (int i = 0; i < StructuresFromFile.size(); i++) {
		if (StructuresFromFile[i].bank_acc == AccountNum)
		{
			return i;
		}
	}
	return -1;
}

void DeleteFromVectorByIndex(vector <stBankAccount>& StructuresFromFile, string AccountNum) {
	StructuresFromFile.erase(StructuresFromFile.begin() + isAccountExist(StructuresFromFile, AccountNum));
}

void DeleteAndPrintTheCLient(vector <stBankAccount>& StructuresFromFile, string AccountNum) {
	char Sure;
	int TargetVectorIndex = isAccountExist(StructuresFromFile, AccountNum);

	if (isAccountExist(StructuresFromFile, AccountNum) != -1)
	{
		PrintImportedLines(StructuresFromFile[TargetVectorIndex]);

		CheckCharInput(Sure, "\n- Are You Sure [Y / N] : ");
		if (toupper(Sure) == 'Y')
		{
			DeleteFromVectorByIndex(StructuresFromFile, AccountNum);
			cout << "\nCLient Data Deleted Successfully.\n";

		}
	}
	else
	{
		PrintImportedLines(NotFoundClient());
	}
}

void DeleteClient() {
	char isContinued;
	vector <stBankAccount> StructuresFromFile = LoadAndStructurizeDataFromFile(FilePath);
	do
	{
		system("cls"); // Clean Terminal

		string AccountNum = EnterString("Enter The Account Number : ");

		DeleteAndPrintTheCLient(StructuresFromFile, AccountNum); // Deletion Process
		SaveDataToFile(FilePath, StructuresFromFile); // Sync Changes

		CheckCharInput(isContinued, "\n- Do you want to continue [Y / N] : ");
	} while (toupper(isContinued) == 'Y');

	cout << "\nThank you, See you soon!\n\n";
}

int main()
{
	DeleteClient();
}