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
			//printf("% *d ", 3, arr[i][j]);
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

int SumRowElements(int arr[3][3], short RowNumber, short column) {
	int Sum = 0;
	for (int i = 0; i < column; i++)
	{
		Sum += arr[RowNumber][i];

	}
	return Sum;
}

void PushSumToArray(int arr[3][3], short rows, short cols, int sumArr[3]) {
	cout << "\n";

	for (int i = 0; i < rows; i++)
	{
		sumArr[i] = SumRowElements(arr, i, cols);
	}
}

void PrintArray(int arr[3], int length) {
	for (int i = 0; i < length; i++)
	{
		cout << "Row " << i + 1 << " Sum = " << arr[i] << endl;
	}
}


int main()
{
	srand((unsigned)time(NULL));

	int TwoDimsArray[3][3];
	int SumRowsArr[3];

	FillTwoDimsArrayRandom(TwoDimsArray, 3, 3);
	PrintTwoDimsArray(TwoDimsArray, 3, 3);
	cout << "__________________________\n";
	PushSumToArray(TwoDimsArray, 3, 3, SumRowsArr);
	PrintArray(SumRowsArr, 3);

}