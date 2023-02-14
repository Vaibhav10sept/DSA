#include <bits/stdc++.h>
using namespace std;

int uniquePathsRecursive(int i, int j, int n, int m, vector<vector<int>> &dp) {
	if (i == n - 1 and j == m - 1) { //we have reached the destination, so return 1
		return 1;
	}
	if (i >= n or j >= m) {
		return 0;
	}
	//BC ends

	//memoization
	if (dp[i][j] != -1) return dp[i][j];

	//recursive calls
	dp[i][j] = uniquePathsRecursive(i, j + 1, n, m, dp) + uniquePathsRecursive(i + 1, j, n, m, dp);
	return dp[i][j];
}

int uniquePaths(int n, int m) {
	vector<vector<int>> dp(n, vector<int>(m, -1));
	return uniquePathsRecursive(0, 0, n, m, dp);
}

int main() {
	/*********************************
	 * NOTE: this will give get submitted, a DP and recursive solution is also there
	LEETCODE: https://leetcode.com/problems/unique-paths/
	VIDEO LINK: https://www.youtube.com/watch?v=t_f0nwwdg5o
	*********************************/
	// string str = "leetcode";
	// vector<string> wordDict = {"leet", "code"};

	int m = 3;
	int n = 7;

	//here, m--> rows and n--> cols
	//so maene func call krte time change kr dia
	//so, now, n--> rows and m--> cols
	cout << uniquePaths(m, n);
}