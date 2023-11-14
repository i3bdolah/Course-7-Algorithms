#include <iostream>
#include <string>
#include <vector> 
#include <iomanip>
using namespace std;

struct sBankAccount
{
	string bank_acc;
	string pin_code;
	string name;
	string phone;
	float acc_balance;
};

string EnterString(string msg) {
	string temp;
	cout << msg;
	getline(cin, temp);

	return temp;
}

int EnterInt(string msg) {
	int temp;
	cout << msg << endl;
	cin >> temp;

	return temp;
}

float EnterFloat(string msg) {
	float temp;
	cout << msg;
	cin >> temp;

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


sBankAccount ImportLine(string record, string seperator = "#//#") {
	sBankAccount client;
	// Destructuring Record to vector.
	vector <string> client_data = splitToVector(record, seperator);

	// Sync Client Data with sClient
	client.bank_acc = client_data[0];
	client.pin_code = client_data[1];
	client.name = client_data[2];
	client.phone = client_data[3];
	client.acc_balance = stof(client_data[4]);

	return client;
}

int main()
{
	string record = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#079999#//#5270.000000";
	sBankAccount client1 = ImportLine(record);

	cout << "\n\Imported Data :" << endl;
	cout << setw(20) << "bank_acc : " << client1.bank_acc << endl;
	cout << setw(20) << "pin_code : " << client1.pin_code << endl;
	cout << setw(20) << "name : " << client1.name << endl;
	cout << setw(20) << "phone : " << client1.phone << endl;
	cout << setw(20) << "acc_balance : " << client1.acc_balance << endl;
}

