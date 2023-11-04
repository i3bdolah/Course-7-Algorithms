#include <iostream>
using namespace std;

int main()
{
	int prev2 = 0, prev1 = 0 , curr = 1;
	for (int i = 0; i < 10; i++)
	{
		cout << curr << " ";
		prev2 = prev1;
		prev1 = curr;
		curr = prev2 + prev1;

	}
}