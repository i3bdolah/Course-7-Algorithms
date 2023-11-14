#include <iostream>
#include <string>
#include <vector> 
using namespace std;

struct sBankAccount
{
	string bank_acc;
	string pin_code;
	string name;
	string phone;
	string acc_balance;
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

string JoinVector(vector <string> vector, string seperator = "#//#") {
	string wordsJoined = "";

	for (string& name : vector)
	{
		wordsJoined = wordsJoined + name + seperator;
	}

	return wordsJoined.substr(0, wordsJoined.length() - seperator.length());
}

vector <string> ReadClientData(sBankAccount& client) {
	vector <string> client_data;

	client_data = {
		client.bank_acc = EnterString("Enter your bank account : "),
		client.pin_code = EnterString("Enter your pin code : "),
		client.name = EnterString("Enter your full name : "),
		client.phone = EnterString("Enter your phone number : "),
		client.acc_balance = to_string(EnterFloat("Enter Your Account Balance : ")),
	};
	return client_data;
}

int main()
{
	sBankAccount client1;
	vector <string> client1_data = ReadClientData(client1);

	cout << "\n\nYour Data which will be saved :" << endl;
	cout << JoinVector(client1_data) << endl;
}