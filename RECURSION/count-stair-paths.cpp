#include <bits/stdc++.h>
using namespace std;

int countClimbStairPaths(int n) {
	if (n == 0) {
		return 1;
	}
	if (n < 0) {
		return 0;
	}

	return countClimbStairPaths(n - 1) + countClimbStairPaths(n - 2)
	       + countClimbStairPaths(n - 3);
}

int main()
{
	cout << countClimbStairPaths(5);
}