#include <bits/stdc++.h>
using namespace std;

int countClimbStairPaths(int n, vector<int> &helperArray) {
	if (n == 0) {
		return 1;
	}
	if (n < 0) {
		return 0;
	}
	if (helperArray[n] != -1) return helperArray[n];

	helperArray[n] = countClimbStairPaths(n - 1, helperArray) + countClimbStairPaths(n - 2, helperArray)
	                 + countClimbStairPaths(n - 3, helperArray);

	return helperArray[n];
}

int main()
{
	int n = 5;
	vector<int> helperArray(n + 1, -1);
	cout << countClimbStairPaths(n, helperArray);
}