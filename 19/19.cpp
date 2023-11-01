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

int MaxInMatrix(int myArr[3][3], short rows, short cols) {
	int temp = myArr[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (myArr[i][j] > temp) {
				temp = myArr[i][j];
			}
		}
	}
	return temp;
}


int MinInMatrix(int myArr[3][3], short rows, short cols) {
	int temp = myArr[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (myArr[i][j] < temp) {
				temp = myArr[i][j];
			}
		}
	}
	return temp;
}

int main()
{
	srand((unsigned)time(NULL));

	int myArr[3][3];
	FillTwoDimsArrayRandom(myArr, 3, 3);

	PrintMatrix(myArr, 3, 3);
	cout << "______________________________" << endl;
	cout << "\n\n";
	cout << "Max Number in Array is : " << MaxInMatrix(myArr, 3, 3);
	cout << "\n\n";
	cout << "Min Number in Array is : " << MinInMatrix(myArr, 3, 3);
	cout << "\n\n";
}