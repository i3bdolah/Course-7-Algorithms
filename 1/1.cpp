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
			arr[i][j] = GenerateRandomNumber(1, 200);
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


int main()
{
	srand((unsigned)time(NULL));

	int TwoDimsArray[3][3];

	FillTwoDimsArrayRandom(TwoDimsArray, 3, 3);
	PrintTwoDimsArray(TwoDimsArray, 3, 3);

}