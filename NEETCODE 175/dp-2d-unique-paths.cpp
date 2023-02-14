#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int n, int m) {
	//WV highly recommended
	//NOTE: this is 2d DP solution, 1d dp solution is also there
	vector<vector<int>> dp(n, vector<int>(m, 0));
	//STORAGE: dp[i][j] --> represent the no of paths from i,j to the destination(n-1,m-1)
	//DIRECTION: from n-1,m-1 to 0,0

	//intialization
	dp[n - 1][m - 1] = 1; //end se end tk jane ka ek path hota h(think, WV)
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (i == n - 1 and j == m - 1) {
				dp[i][j] = 1;
			}
			else {
				if (i + 1 < n) { //for bottom
					dp[i][j] += dp[i + 1][j];
				}
				if (j + 1 < m) { //for right
					dp[i][j] += dp[i][j + 1];
				}
			}
		}
	}

	return dp[0][0];
}

int main() {
	/*********************************
	 * NOTE: a recursive code is also there.
	LEETCODE: https://leetcode.com/problems/unique-paths/
	VIDEO LINK: https://www.youtube.com/watch?v=IlEsdxuD4lY
	*********************************/
	int m = 3;
	int n = 7;
	//here, m--> rows and n--> cols
	//so maene func call krte time change kr dia
	//so, now, n--> rows and m--> cols
	cout << uniquePaths(m, n);
}