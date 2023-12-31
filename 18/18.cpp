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

void PrintIntersectedElements(int myArr[3][3], int myArr2[3][3], short rows, short cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (CheckExistInMatrix(myArr2, 3, 3, myArr[i][j]))
			{
				cout << setw(3) << myArr[i][j];
			}
		}
		cout << '\n';
	}
}


int main()
{
	srand((unsigned)time(NULL));

	int myArr[3][3];
	int myArr2[3][3];
	FillTwoDimsArrayRandom(myArr, 3, 3);
	FillTwoDimsArrayRandom(myArr2, 3, 3);

	PrintMatrix(myArr, 3, 3);
	cout << "______________________________" << endl;
	PrintMatrix(myArr2, 3, 3);
	cout << "\n\n";
	PrintIntersectedElements(myArr, myArr2, 3, 3);
	cout << "\n\n";

}