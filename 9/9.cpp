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
			arr[i][j] = GenerateRandomNumber(1, 10);
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

void PrintMiddleRow(int arr[3][3], short rows, short cols) {
	int middleRow = rows / 2;

	for (int j = 0; j < cols; j++)
	{
		cout << setw(3) << arr[middleRow][j] << " ";
	}
	cout << '\n';
}

void PrintMiddleCol(int arr[3][3], short rows, short cols) {
	int middleCol = cols / 2;

	for (int i = 0; i < rows; i++)
	{
		cout << setw(3) << arr[i][middleCol] << " ";
	}
	cout << '\n';
}

int main()
{
	srand((unsigned)time(NULL));

	int myArr[3][3];
	FillTwoDimsArrayRandom(myArr, 3, 3);

	PrintMatrix(myArr, 3, 3);

	cout << "_______________________________The Answer_______________________________" << endl;
	cout << "\nMiddle Row :";
	PrintMiddleRow(myArr, 3, 3);
	cout << "\nMiddle Column:";
	PrintMiddleCol(myArr, 3, 3);
}