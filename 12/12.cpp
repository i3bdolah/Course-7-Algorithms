// 9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

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

int MatrixSum(int arr[3][3], short rows, short cols) {
	int sum = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			sum += arr[i][j];
		}
	}
	return sum;
}

bool ArrayTypical(int fArr[3][3], int lArr[3][3], short rows, short cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (fArr[i][j] != lArr[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

void PrintTypicalMsg(bool status) {
	cout << "\n";
	if (!status)
	{
		cout << "No: The Two Metrices are not Typical.";
	}
	else
	{
		cout << "Yes: The Two Metrices are Typical.";
	}
	cout << "\n";
}

int main()
{
	srand((unsigned)time(NULL));

	int myArr[3][3], myArr2[3][3];
	FillTwoDimsArrayRandom(myArr, 3, 3);
	FillTwoDimsArrayRandom(myArr2, 3, 3);

	PrintMatrix(myArr, 3, 3);
	cout << "\n";
	PrintMatrix(myArr2, 3, 3);

	PrintTypicalMsg(ArrayTypical(myArr, myArr2, 3, 3));
}