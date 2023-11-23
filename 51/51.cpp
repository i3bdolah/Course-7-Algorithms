#include <iostream>
#include <string>
#include <vector> 
#include <fstream> 
#include <iomanip>
using namespace std;

// File path where client data is stored
const string FilePath = "C:\\Users\\Abdullah\\Desktop\\Clients-Table.txt";

// Structure to represent a bank account
struct stBankAccount
{
	string bank_acc;
	string pin_code;
	string name;
	string phone;
	double acc_balance = 0;
};

// Function to create a "not found" client structure
stBankAccount NotFoundClient() {
	stBankAccount temp;

	temp.bank_acc = "NOT FOUND";
	temp.pin_code = "NOT FOUND";
	temp.name = "NOT FOUND";
	temp.phone = "NOT FOUND";
	temp.acc_balance = 0;

	return temp;
}

// Function to input a string from the user
string EnterString(string msg) {
	string temp;
	cout << msg;
	getline(cin, temp);

	return temp;
}

// Function to input a character from the user
void CheckCharInput(char& var, string msg) {
	cout << msg;
	cin >> var;
	cout << "\n";
	cin.ignore();
}

// Function to split a string into a vector of strings based on a separator
vector <string> SplitToVector(string sentence, string separator = "#//#") {
	vector <string> wordsSeparated;
	int pos = 0;
	string strTemp;

	while ((pos = sentence.find(separator)) != string::npos)
	{
		strTemp = sentence.substr(0, pos);
		if (strTemp != separator)
		{
			wordsSeparated.push_back(strTemp.substr(0, (pos)));
		}

		sentence.erase(0, pos + separator.length());
	}

	if (sentence != "" && sentence != separator)
	{
		wordsSeparated.push_back(sentence);
	}

	return wordsSeparated;
}

// Function to convert a line from the file into a client structure
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

// Function to load data from a file and structure it into a vector
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

// Function to print a line of underscores to create a visual separation
void HugeLine() {
	cout << "____________________________________________________________________________________________________" << endl;
}

// Function to print headers for the client data table
void PrintHeaders() {
	HugeLine();
	cout << "\n| " << left << setw(20) << "Account Number";
	cout << "| " << left << setw(20) << "Pin Code";
	cout << "| " << left << setw(20) << "Client Name";
	cout << "| " << left << setw(20) << "Phone";
	cout << "| " << left << setw(20) << "Balance" << endl;
	HugeLine();
}

// Function to print a row of client data in the table
void PrintRows(stBankAccount client) {
	cout << "| " << left << setw(20) << client.bank_acc;
	cout << "| " << left << setw(20) << client.pin_code;
	cout << "| " << left << setw(20) << client.name;
	cout << "| " << left << setw(20) << client.phone;
	cout << "| " << left << setw(20) << client.acc_balance << endl;
	HugeLine();
}

// Function to print the imported lines of client data
void PrintImportedLines(stBankAccount StructuresFromFile) {
	PrintHeaders();
	PrintRows(StructuresFromFile);
}

// Function to join client data into a line for saving to the file
string JoinClientDataToLine(stBankAccount stClient, string separator = "#//#") {
	string wordsJoined = "";

	wordsJoined += stClient.bank_acc + separator;
	wordsJoined += stClient.pin_code + separator;
	wordsJoined += stClient.name + separator;
	wordsJoined += stClient.phone + separator;
	wordsJoined += to_string(stClient.acc_balance);

	return wordsJoined;
}

// Function to save updated data to the file
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

// Function to check if an account exists in the vector
int isAccountExist(vector <stBankAccount> StructuresFromFile, string AccountNum) {
	for (int i = 0; i < StructuresFromFile.size(); i++) {
		if (StructuresFromFile[i].bank_acc == AccountNum)
		{
			return i;
		}
	}
	return -1;
}

// Function to update a client's data in the vector
stBankAccount UpdateFromVectorByIndex(stBankAccount TheClient) {
	TheClient.pin_code = EnterString("Enter Pin Code : ");
	TheClient.name = EnterString("Enter Name : ");
	TheClient.phone = EnterString("Enter Phone Number : ");
	TheClient.acc_balance = stod(EnterString("Enter Balance : "));

	return TheClient;
}

// Function to update and print the client data
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

// Function to delete a client
void DeleteClient() {
	char isContinued;
	do
	{
		system("cls"); // Clear Terminal

		string AccountNum = EnterString("Enter The Account Number : ");
		vector <stBankAccount> StructuresFromFile = LoadAndStructurizeDataFromFile(FilePath);

		UpdateAndPrintTheClient(StructuresFromFile, AccountNum); // Deletion Process
		SaveDataToFile(FilePath, StructuresFromFile); // Sync Changes

		CheckCharInput(isContinued, "\n- Continue Updating [Y / N] : ");
	} while (toupper(isContinued) == 'Y');

	cout << "\nThank you, See you soon!\n\n";
}

// Main function
int main()
{
	DeleteClient();
}
