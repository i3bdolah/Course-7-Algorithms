#include <iostream>
#include <iomanip>
using namespace std;


void FillArrayWithOrderedNumbers(int arr[3][3], short rows, short cols) {
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

void FillTransposedMatrix(int arr[3][3], short rows, short cols) {
	int counter = 1;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[j][i] = counter++;
		}
	}
}

int main()
{
	int myArr[3][3], myTransposedArr[3][3];
	FillArrayWithOrderedNumbers(myArr, 3, 3);
	FillTransposedMatrix(myTransposedArr, 3, 3);
	
	PrintMatrix(myArr, 3, 3);
	cout << "_______________________________" << endl;
	PrintMatrix(myTransposedArr, 3, 3);

}
