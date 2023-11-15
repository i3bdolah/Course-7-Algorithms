#include <iostream>
#include <string>
#include <vector> 
#include <fstream> 
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

sBankAccount ReadNewClient() {
	sBankAccount client;

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

string ConvertRecordToLine(sBankAccount client, string seperator = "#//#") {

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
	sBankAccount client = ReadNewClient();
	SaveDataToFile(FilePath, ConvertRecordToLine(client));
}

void AddClients() {
	char addMore = 'Y';

	while (toupper(addMore) == 'Y')
	{
		system("cls"); // Clean Terminal

		AddNewClient();


		cout << "\nClient Saved Successfully, Add more ? [Y / N] : ";
		cin >> addMore;
		cin.ignore();
	};
}

int main()
{
	AddClients();
}