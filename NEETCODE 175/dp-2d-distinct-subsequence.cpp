#include <bits/stdc++.h>
using namespace std;

int distinctSubsequence(string s, string t) {
	//WV highly recommended
	int n = s.size();
	int m = t.size();

	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	//STORAGE:

	//watch video recommmeded for initialization
	//initialization --> first column
	for (int i = 0; i <= n; i++) dp[i][0] = 1;
	//initialization --> first row
	for (int j = 1; j <= m; j++) dp[0][j] = 0; //why j=1 , think, WV

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i - 1] == t[j - 1]) { //NOTE: the indx of s and t is one less than the index of dp
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
			else { //s[i-1] != t[j-1]
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << "print" << endl;
	for (auto vec : dp) {
		for (auto ele : vec) cout << ele << " ";
		cout << endl;
	}
	return dp[n][m];
}

int main() {
	/*********************************
	 * this is dp solution, a memo solution is also there
	LEETCODE: https://leetcode.com/problems/distinct-subsequences/
	VIDEO LINK: https://www.youtube.com/watch?v=nVG7eTiD2bY
	*********************************/
	string s = "rabbbit";
	string t = "rabbit";

	cout << distinctSubsequence(s, t);
}