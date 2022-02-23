#include <bits/stdc++.h>
using namespace std;

int printFibonacciMemoized(int n, vector<int> &helperArray) {
	if (n == 0 || n == 1) {
		return n;
	}
	if (helperArray[n] != -1) return helperArray[n];
	helperArray[n] = printFibonacciMemoized(n - 1, helperArray) + printFibonacciMemoized(n - 2, helperArray);
	return helperArray[n];
}

int main()
{
	int n = 10;
	vector<int> helperArray(n + 1, -1);
	cout << printFibonacciMemoized(n, helperArray);
	// for (auto ele : helperArray) cout << ele << " ";
	// cout << helperArray[n];
}