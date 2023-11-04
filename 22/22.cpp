#include <iostream>
using namespace std;

void FibonacciSeries(short limit, short prev2, short prev1, short curr) {
    if (limit != 0)
    {
        cout << curr << " ";
        prev2 = prev1;
        prev1 = curr;
        curr = prev2 + prev1;
        limit--;
        FibonacciSeries(limit, prev2, prev1, curr);
    }
}

int main()
{
	FibonacciSeries(10,0,0,1);
}