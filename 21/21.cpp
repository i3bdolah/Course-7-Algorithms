#include <iostream>
using namespace std;

void FibonacciSeries(short limit) {
	int prev2 = 0, prev1 = 0, curr = 1;
	for (int i = 0; i < limit; i++)
	{
		cout << curr << " ";
		prev2 = prev1;
		prev1 = curr;
		curr = prev2 + prev1;
	}
}

int main()
{
	FibonacciSeries(14);
}