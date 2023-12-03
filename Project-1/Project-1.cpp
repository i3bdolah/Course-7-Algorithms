#include <iostream>
#include <string>
#include <vector> 
#include <fstream> 
#include <iomanip>
using namespace std;

const string FilePath = "C:\\Users\\Abdullah\\Desktop\\Clients-Table.txt";

enum Operations
{
	//None = 0,
	ShowAll = 1,
	Add = 2,
	Delete = 3,
	Update = 4,
	Find = 5,
};

enum TransactionOperation
{
	Deposit = 1,
	Withdrawal = 2,
	ShowAllBalance = 3,
	MainMenu = 4,
};

struct stBankAccount
{
	string bank_acc;
	string pin_code;
	string name;
	string phone;
	double acc_balance = 0;

	stBankAccount() = default;
};

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

// Adding Client
stBankAccount ReadNewClient() {
	stBankAccount client;

	cout << "Enter your bank account : ";
	getline(cin, client.bank_acc);

	cout << "Enter your pin code : ";
	getline(cin, client.pin_code);

	cout << "Enter your full name : ";
	getline(cin, client.name);

	cout << "Enter your phone number : ";
	getline(cin, client.phone);

	cout << "Enter Your Account Balance : ";
	cin >> client.acc_balance;

	return client;
}

string ConvertRecordToLine(stBankAccount client, string seperator = "#//#") {

	string tempRecord = "";

	tempRecord += client.bank_acc + seperator;
	tempRecord += client.pin_code + seperator;
	tempRecord += client.name + seperator;
	tempRecord += client.phone + seperator;
	tempRecord += to_string(client.acc_balance);

	return tempRecord;
}

void SaveDataToFile(string FilePath, string record) {
	fstream MyFile;
	MyFile.open(FilePath, ios::out | ios::app);

	if (MyFile.is_open()) {
		MyFile << record << endl;
		MyFile.close();
	}
	else
	{
		cout << "\nWe Couldn't open the File" << endl;
	}
}

string JoinVector(vector <string> vector, string seperator = "#//#") {
	string wordsJoined = "";

	for (string& name : vector)
	{
		wordsJoined = wordsJoined + name + seperator;
	}

	return wordsJoined.substr(0, wordsJoined.length() - seperator.length());
}

void AddNewClient() {
	stBankAccount client = ReadNewClient();
	SaveDataToFile(FilePath, ConvertRecordToLine(client));
}

void AddClients() {
	char addMore = 'Y';

	while (toupper(addMore) == 'Y')
	{
		AddNewClient();


		cout << "\nClient Saved Successfully, Add more ? [Y / N] : ";
		cin >> addMore;
		cin.ignore();
	};
}

void LineOfEquals() {
	cout << setw(50) << "==================================================" << endl;
}

void Headline(string headline) {
	LineOfEquals();
	cout <<  "\t\t" << headline << endl;
	LineOfEquals();
}

// Read Client
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
	vector <stBankAccount> StructuresFromFile = LoadAndStructurizeDataFromFile(FilePath);
	PrintImportedLines(StructuresFromFile);
}

// Find Client

stBankAccount NotFoundClient() {
	stBankAccount temp;

	temp.bank_acc = "NOT FOUND";
	temp.pin_code = "NOT FOUND";
	temp.name = "NOT FOUND";
	temp.phone = "NOT FOUND";
	temp.acc_balance = 0;

	return temp;
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

void PrintImportedLines(stBankAccount StructuresFromFile) {
	PrintHeaders();
	PrintRows(StructuresFromFile);
}

stBankAccount SearchInClients(vector <stBankAccount> StructuresFromFile, string AccountNum) {
	for (stBankAccount& structure : StructuresFromFile)
	{
		if (structure.bank_acc == AccountNum)
		{
			return structure;
		}
	}
	return NotFoundClient();
}

void FindClient() {
	string AccountNum = EnterString("Enter The Account Number : ");
	vector <stBankAccount> StructuresFromFile = LoadAndStructurizeDataFromFile(FilePath);
	stBankAccount TheClient = SearchInClients(StructuresFromFile, AccountNum);
	PrintImportedLines(TheClient);
}

// Delete Client

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

// Update Client

stBankAccount UpdateFromVectorByIndex(stBankAccount TheClient) {
	TheClient.pin_code = EnterString("Enter Pin Code : ");
	TheClient.name = EnterString("Enter Name : ");
	TheClient.phone = EnterString("Enter Phone Number : ");
	TheClient.acc_balance = stod(EnterString("Enter Balance : "));

	return TheClient;
}

void UpdateAndPrintTheClient(vector <stBankAccount>& StructuresFromFile, string AccountNum) {
	char Sure;
	int TargetVectorIndex = isAccountExist(StructuresFromFile, AccountNum);

	if (isAccountExist(StructuresFromFile, AccountNum) != -1)
	{
		PrintImportedLines(StructuresFromFile[TargetVectorIndex]);

		CheckCharInput(Sure, "\n- Proceed with this client [Y / N] : ");
		if (toupper(Sure) == 'Y')
		{
			StructuresFromFile[TargetVectorIndex] = UpdateFromVectorByIndex(StructuresFromFile[TargetVectorIndex]);
			cout << "\nClient Data Updated Successfully.\n";
		}
	}
	else
	{
		PrintImportedLines(NotFoundClient());
	}
}

void UpdateClient() {
	char isContinued;
	do
	{
		system("cls"); // Clear Terminal

		string AccountNum = EnterString("Enter The Account Number : ");
		vector <stBankAccount> StructuresFromFile = LoadAndStructurizeDataFromFile(FilePath);

		UpdateAndPrintTheClient(StructuresFromFile, AccountNum);
		SaveDataToFile(FilePath, StructuresFromFile); // Sync Changes

		CheckCharInput(isContinued, "\n- Continue Updating [Y / N] : ");
	} while (toupper(isContinued) == 'Y');

	cout << "\nThank you, See you soon!\n\n";
}

void DecisionsFlow(int EnteredNum) {
	switch (EnteredNum)
	{
	case ShowAll:
		system("cls"); // Clean Terminal
		Headline("Show Client List");
		ReadClients();
		system("pause");
		break;
	case Add:
		system("cls"); // Clean Terminal
		Headline("Add Client");
		AddClients();
		break;
	case Delete:
		system("cls"); // Clean Terminal
		Headline("Delete Client");
		DeleteClient();
		break;
	case Update:
		system("cls"); // Clean Terminal
		Headline("Update Client");
		UpdateClient();
		break;
	case Find:
		system("cls"); // Clean Terminal
		Headline("Find Client");
		FindClient();
		system("pause");
		break;
	}
}

void ClientOperations() {
	int EnteredNum;
	do
	{
		system("cls");
		Headline("Main Menu");
		cout << setw(50) << left << "[1] Show Client List" << endl;
		cout << setw(50) << left << "[2] Add Client" << endl;
		cout << setw(50) << left << "[3] Delete Client" << endl;
		cout << setw(50) << left << "[4] Update Client" << endl;
		cout << setw(50) << left << "[5] Find Client" << endl;
		cout << setw(50) << left << "[6] Exit" << endl;
		LineOfEquals();
		cout << setw(20) << left << "Enter The Operation Number : ";
		cin >> EnteredNum;
		cin.ignore();

		// Decisions
		DecisionsFlow(EnteredNum);
	} while (EnteredNum != 0);
}

int main()
{
	ClientOperations();
}
