#include <iostream>
#include <iomanip>
using namespace std;

int readNum(string msg) {
	int num = 0;
	cout << msg;
	cin >> num;
	return num;
}

int GenerateRandomNumber(int from, int to) {
	return rand() % (to - from + 1) + from;
}

void FillTwoDimsArrayRandom(int arr[3][3], short rows, short cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = GenerateRandomNumber(1, 25);
		}
	}
}

void PrintMatrix(int arr[3][3], short rows, short cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			//printf("% *d ", 3, arr[i][j]);
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

bool CheckExistInMatrix(int arr[3][3], short rows, short cols, int targetNum) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] == targetNum)
			{
				return true;
			}
		}
	}
	return false;
}

bool isPalindrome(int myArr[3][3], short rows, short cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols / 2; j++)
		{
			if (myArr[i][j] != myArr[i][cols - 1 - j])
			{
				return false;
			}
		}
	}
	return true;
}

void PalindromeMsg(bool status) {
	if (status)
	{
		cout << "Yes: The Matrix is Palindrome.\n\n";
	}
	else
	{
		cout << "No: The Matrix is NOT Palindrome.\n\n";
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int myArr[3][3] = { {0,0,0},{1,1,1},{0,0,0} };
	//FillTwoDimsArrayRandom(myArr, 3, 3);

	PrintMatrix(myArr, 3, 3);
	cout << "______________________________" << endl;
	cout << "\n\n";
	PalindromeMsg(isPalindrome(myArr, 3, 3));
}