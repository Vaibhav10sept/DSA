#include <bits/stdc++.h>
using namespace std;

int rec(int i, int j, vector<vector<int>> &memo) {
	if (i < 0 or j < 0) return 0;
	if (i == 0 and j == 0) return 1;

	if (memo[i][j] != -1) return memo[i][j];

	return memo[i][j] = rec(i - 1, j, memo) + rec(i, j - 1, memo);
}

int uniquePaths(int n, int m) {
	vector<vector<int>> memo(n, vector<int>(m, -1));
	return rec(n - 1, m - 1, memo);
}

int main()
{
	int n = 3;
	int m = 7;
	cout << uniquePaths(n, m);
}