#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string EnterString(string msg) {
	string temp;
	cout << msg << endl;
	getline(cin, temp);

	return temp;
}

void PrintWordSeperetly(string str) {

	string delim = " ";
	string stringInRange = "";
	int pos = 0;

	while ((pos = str.find(delim)) != string::npos)
	{
		stringInRange = str.substr(0, pos);
		if (stringInRange != " ")
		{
			cout << '|' << stringInRange << '|' << endl;
		}

		str.erase(0, pos + delim.length());
	}
	if (str != "")
	{
		cout << '|' << str << '|' << endl;
	}
}

int main()
{
	string entered = EnterString("Enter The Letter : ");
	cout << "\n\nSeperated Words : -" << endl;
	PrintWordSeperetly(entered);

}