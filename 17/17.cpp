// 9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
			arr[i][j] = GenerateRandomNumber(1, 2);
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

bool CheckExistMatrix(int arr[3][3], short rows, short cols, int targetNum) {
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

void PrintExistMsg(bool status) {
	cout << "\n";
	if (!status)
	{
		cout << "No: The Number is not Exist.";
	}
	else
	{
		cout << "Yes: The Number is Exist.";
	}
	cout << "\n";
}



int main()
{
	srand((unsigned)time(NULL));

	int myArr[3][3] = { {3,0,0} ,{1,2,0},{0,0,2} };
	//FillTwoDimsArrayRandom(myArr, 3, 3);

	PrintMatrix(myArr, 3, 3);

	int targetedNumber = readNum("Enter The Targeted Number : ");
	PrintExistMsg(CheckExistMatrix(myArr, 3, 3, targetedNumber));

}