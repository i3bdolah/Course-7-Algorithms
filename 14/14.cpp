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

bool CheckScalarMatrix(int arr[3][3], short rows, short cols) {
	int scalarValue = arr[0][0];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == j && arr[i][j] != scalarValue)
			{
				return false;
			}
			else if (i != j && arr[i][j] != 0)
			{
				return false;
			}
		}
	}
	return true;
}

void PrintScalarMsg(bool status) {
	cout << "\n";
	if (!status)
	{
		cout << "No: The Matrix is not Scalar.";
	}
	else
	{
		cout << "Yes: The Matrix is Scalar.";
	}
	cout << "\n";
}

int main()
{
	srand((unsigned)time(NULL));

	int myArr[3][3] = { {3,0,0} ,{0,2,0},{0,0,2} };
	//FillTwoDimsArrayRandom(myArr, 3, 3);

	PrintMatrix(myArr, 3, 3);

	PrintScalarMsg(CheckScalarMatrix(myArr, 3, 3));
}