#include <bits/stdc++.h>
using namespace std;

int editDistance(string str1, string str2) {
	// WV highly recommended
	int n = str1.size();
	int m = str2.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	//storage: dp[i][j] --> min no of operation(replace, insert, remove/delete) to convert str2 to str1

	//initialization
	//if str1 is exhausted we need to insert the chars for str2
	for (int i = 1; i <= n; i++) dp[i][0] = i;
	//if str2 is exhausted we need to delete the chars of str1 to make str2
	for (int j = 1; j <= m; j++) dp[0][]j = j;
	//initialization ends

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = 0 + dp[i - 1][j - 1];
			}
			else { //str1[i-1] != str2[j-1]
				int deleteOperation = dp[i - 1][j];
				int replaceOperation = dp[i - 1][j - 1];
				int insertOperation = dp[i][j - 1];
				dp[i][j] = 1 + min(min(deleteOperation, replaceOperation), insertOperation);
				//+1 coz, think CS WV
			}
		}
	}
	return dp[n][m];
}

int main() {
	/*********************************
	 * PREREQUISITE: distinct subsequence
	 * NOTE: this question is the application of distinct subsequence.
	LEETCODE: https://leetcode.com/problems/edit-distance/
	VIDEO LINK: https://www.youtube.com/watch?v=fJaKO8FbDdo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=34
	*********************************/
	string word1 = "horse";
	string word2 = "ros";

	cout << editDistance(word1, word2);
}