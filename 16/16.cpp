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

int NumberOfOcuurances(int arr[3][3], short rows, short cols, int targetNum) {
	int occTimes = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] == targetNum)
			{
				occTimes++;
			}
		}
	}
	return occTimes;
}

bool CheckSparceMatrix(int arr[3][3], short rows, short cols) {
	return floor((cols * rows) / 2) >= NumberOfOcuurances(arr, rows, cols, 0);
	
}

void PrintSparceMsg(bool status) {
	cout << "\n";
	if (status)
	{
		cout << "No: The Matrix is not Sparce.";
	}
	else
	{
		cout << "Yes: The Matrix is Sparce.";
	}
	cout << "\n";
}



int main()
{
	srand((unsigned)time(NULL));

	int myArr[3][3] = { {3,0,0} ,{1,2,0},{0,0,2} };
	//FillTwoDimsArrayRandom(myArr, 3, 3);

	PrintMatrix(myArr, 3, 3);
	PrintSparceMsg(CheckSparceMatrix(myArr, 3, 3));
}