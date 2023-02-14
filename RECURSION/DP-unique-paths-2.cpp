#include <bits/stdc++.h>
using namespace std;

int uniquePaths2(vector<vector<int>> arr) {
	int n = arr.size();
	int m = arr[0].size();
	vector<vector<int>> dp(n, vector<int>(m, 0));

	// dp[n - 1][m - 1] = 1; //initialization
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (i == n - 1 and j == m - 1 and arr[i][j] != 1) {
				dp[i][j] = 1;
			}
			else if (arr[i][j] == 1) {
				dp[i][j] = 0;
			}
			else {
				if (i + 1 < n) {
					dp[i][j] += dp[i + 1][j];
				}
				if (j + 1 < m) {
					dp[i][j] += dp[i][j + 1];
				}
			}
		}
	}
	return dp[0][0];
}

int main()
{
	/*****************************
	 * NOTE: this DP solution, a rec solution is also there.
	 * LEETCODE LINK: https://leetcode.com/problems/unique-paths-ii/
	 * **************************************/
	vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
	cout << uniquePaths2(obstacleGrid);

}