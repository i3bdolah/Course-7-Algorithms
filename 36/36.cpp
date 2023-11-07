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

int CountNumberOfWord(string str) {

	string delim = " ";
	string stringInRange = "";
	int pos = 0;
	int counter = 0;

	while ((pos = str.find(delim)) != string::npos)
	{
		stringInRange = str.substr(0, pos);
		if (stringInRange != " ")
		{
			//cout << '|' << stringInRange << '|' << endl;
			counter++;
		}

		str.erase(0, pos + delim.length());
	}
	if (str != "")
	{
		//cout << '|' << str << '|' << endl;
		counter++;
	}
	return counter;
}

int main()
{
	string entered = EnterString("Enter The Letter : ");
	cout << "\n\Number Of Words = " << CountNumberOfWord(entered) << endl;

}