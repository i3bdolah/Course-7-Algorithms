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

void PrintTwoDimsArray(int arr[3][3], short rows, short cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

int SumRowElements(int arr[3][3], short ColNumber, short row) {
	int Sum = 0;
	for (int i = 0; i < row; i++)
	{
		Sum += arr[i][ColNumber];
	}
	return Sum;
}

void PrintColSumOfTwoDimsArray(int arr[3][3], short rows, short cols) {
	cout << "\n";
	for (int i = 0; i < cols; i++)
	{
		cout << "Columns " << i + 1 << " Sum = " << SumRowElements(arr, i, rows) << endl;
	}
}


int main()
{
	srand((unsigned)time(NULL));

	int TwoDimsArray[3][3];

	FillTwoDimsArrayRandom(TwoDimsArray, 3, 3);
	PrintTwoDimsArray(TwoDimsArray, 3, 3);
	cout << "__________________________\n";
	PrintColSumOfTwoDimsArray(TwoDimsArray, 3, 3);

}