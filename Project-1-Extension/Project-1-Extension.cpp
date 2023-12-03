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
	Transactions = 6,
};

enum TransactionsOperation
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

int isAccountExist(vector <stBankAccount> StructuresFromFile, string AccountNum);
vector <stBankAccount> LoadAndStructurizeDataFromFile(string FilePath);

// Adding Client
stBankAccount ReadNewClient() {
	stBankAccount client;
	vector <stBankAccount> AllClients = LoadAndStructurizeDataFromFile(FilePath);

	cout << "Enter your bank account : ";
	getline(cin, client.bank_acc);

	if (isAccountExist(AllClients, client.bank_acc) >= 0)
	{
		do
		{
			cout << "\nThe Entered Bank Acc. Already Exist!";
			cout << "\nRe-Enter your bank account : ";
			getline(cin, client.bank_acc);
		} while (isAccountExist(AllClients, client.bank_acc) >= 0);
	}

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
	cout << "\t\t" << headline << endl;
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
		Headline("Update Client");
		string AccountNum = EnterString("Enter The Account Number : ");
		vector <stBankAccount> StructuresFromFile = LoadAndStructurizeDataFromFile(FilePath);

		UpdateAndPrintTheClient(StructuresFromFile, AccountNum);
		SaveDataToFile(FilePath, StructuresFromFile); // Sync Changes

		CheckCharInput(isContinued, "\n- Continue Updating [Y / N] : ");
	} while (toupper(isContinued) == 'Y');

	cout << "\nThank you, See you soon!\n\n";
}

// Transations

void QuickClinetPrint(stBankAccount client) {
	cout << "Account Number = " << client.bank_acc << endl;
	cout << "Pin Code = " << client.pin_code << endl;
	cout << "Name = " << client.name << endl;
	cout << "Phone = " << client.phone << endl;
	cout << "Balance = " << client.acc_balance << endl;
}

void DepositOperation() {
	double depositValue;
	vector <stBankAccount> StructuresFromFile = LoadAndStructurizeDataFromFile(FilePath);
	int Index = isAccountExist(StructuresFromFile, EnterString("Enter The Account Number : "));

	if (Index >= 0)
	{
		// Printing Quick Info
		HugeLine();
		QuickClinetPrint(StructuresFromFile[Index]);
		HugeLine();

		cout << "Deposit Value : ";
		cin >> depositValue;

		StructuresFromFile[Index].acc_balance += depositValue;
		SaveDataToFile(FilePath, StructuresFromFile);
		cout << "Data Saved Successfully." << endl;
	}
	else
	{
		cout << "Account Number Not Exist!" << endl;
	}
}

void WithdrawalOperation() {
	double withdrawalValue;
	vector <stBankAccount> StructuresFromFile = LoadAndStructurizeDataFromFile(FilePath);
	int Index = isAccountExist(StructuresFromFile, EnterString("Enter The Account Number : "));

	if (Index >= 0)
	{
		// Printing Quick Info
		HugeLine();
		QuickClinetPrint(StructuresFromFile[Index]);
		HugeLine();

		cout << "Withdrawal Value : ";
		cin >> withdrawalValue;

		if (withdrawalValue <= StructuresFromFile[Index].acc_balance)
		{

		StructuresFromFile[Index].acc_balance -= withdrawalValue;
		SaveDataToFile(FilePath, StructuresFromFile);
		cout << "Data Saved Successfully." << endl;
		}
		else {
			cout << "More than current balance!" << endl;
		}
	}
	else
	{
		cout << "Account Number Not Exist!" << endl;
	}
	system("pause");
}

void ShowAllBalanceOperation() {
	vector <stBankAccount> StructuresFromFile = LoadAndStructurizeDataFromFile(FilePath);

	HugeLine();
	cout << "\n| " << left << setw(20) << "Account Number";
	cout << "| " << left << setw(20) << "Client Name";
	cout << "| " << left << setw(20) << "Balance" << endl;
	HugeLine();
	for (stBankAccount& C : StructuresFromFile) {
		cout << "| " << left << setw(20) << C.bank_acc;
		cout << "| " << left << setw(20) << C.name;
		cout << "| " << left << setw(20) << C.acc_balance << endl;
	}
	HugeLine();

	system("pause");
}

void TransactionsDecisionsFlow(TransactionsOperation EnteredNum) {
	switch (EnteredNum)
	{
	case TransactionsOperation::Deposit:
		system("cls"); // Clean Terminal
		Headline("Deposit");
		DepositOperation();
		system("pause");
		break;
	case TransactionsOperation::Withdrawal:
		system("cls"); // Clean Terminal
		Headline("Withdrawal");
		WithdrawalOperation();
		break;
	case TransactionsOperation::ShowAllBalance:
		system("cls"); // Clean Terminal
		Headline("Show Clients Balance");
		ShowAllBalanceOperation();
		break;
	}

}

void ClientTransactions() {
	int EnteredNum;
	do
	{
		system("cls");
		Headline("Transactions");
		cout << setw(50) << left << "[1] Deposit" << endl;
		cout << setw(50) << left << "[2] Withdrawal" << endl;
		cout << setw(50) << left << "[3] Show Clients Balance" << endl;
		cout << setw(50) << left << "[4] Main Menu" << endl;
		LineOfEquals();
		cout << setw(20) << left << "Enter The Service Number : ";
		cin >> EnteredNum;
		cin.ignore();

		// Decisions
		TransactionsDecisionsFlow((TransactionsOperation)EnteredNum);
	} while (EnteredNum != 4);
}

/////////////////////////////////////////////////////////////////

void DecisionsFlow(Operations EnteredNum) {
	switch (EnteredNum)
	{
	case Operations::ShowAll:
		system("cls"); // Clean Terminal
		Headline("Show Client List");
		ReadClients();
		system("pause");
		break;
	case Operations::Add:
		system("cls"); // Clean Terminal
		Headline("Add Client");
		AddClients();
		break;
	case Operations::Delete:
		system("cls"); // Clean Terminal
		Headline("Delete Client");
		DeleteClient();
		break;
	case Operations::Update:
		system("cls"); // Clean Terminal
		Headline("Update Client");
		UpdateClient();
		break;
	case Operations::Find:
		system("cls"); // Clean Terminal
		Headline("Find Client");
		FindClient();
		system("pause");
		break;
	case Operations::Transactions:
		system("cls"); // Clean Terminal
		Headline("Transactions");
		ClientTransactions();
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
		cout << setw(50) << left << "[6] Transactions" << endl;
		cout << setw(50) << left << "[7] Exit" << endl;
		LineOfEquals();
		cout << setw(20) << left << "Enter The Service Number : ";
		cin >> EnteredNum;
		cin.ignore();

		// Decisions
		DecisionsFlow((Operations)EnteredNum);
	} while (EnteredNum != 7);
}

int main()
{
	ClientOperations();
}
