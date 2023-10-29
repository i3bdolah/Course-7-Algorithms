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

void FillArrayWithOrdered(int arr[3][3], short rows, short cols) {
	int counter = 1;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = counter++;
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

void MultiblyTwoMetrices(int firstArr[3][3], int secArr[3][3], int resultArr[3][3], short rows, short cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			resultArr[i][j] = firstArr[i][j] * secArr[i][j];
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int myArr[3][3], myArr2[3][3], myArr3[3][3];
	FillTwoDimsArrayRandom(myArr, 3, 3);
	FillTwoDimsArrayRandom(myArr2, 3, 3);

	PrintMatrix(myArr, 3, 3);
	cout << "_______________________________" << endl;
	PrintMatrix(myArr2, 3, 3);

	cout << "_______________________________The Answer_______________________________" << endl;
	MultiblyTwoMetrices(myArr, myArr2, myArr3, 3, 3);
	PrintMatrix(myArr3, 3, 3);
}
