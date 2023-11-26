#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string str1, string str2) {
	//WV highly recommended
	//NOTE: this is a 2d DP solution, recursive solution is also there
	int n = str1.size();
	int m = str2.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	//STORAGE: dp[i][j] --> stores the max length of common subsequence using the str1 from 0th index to (i-1)th index and str2 from 0th index to (j-1)th index
	for (int i = 1; i < dp.size(); i++) {
		for (int j = 1; j < dp[0].size(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] += 1; // + 1 think, crucial
				dp[i][j] += dp[i - 1][j - 1];
			}
			else { // str1[i-1] != str2[j-1]
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	return dp[n][m];
}

int longestPallindromicSubsequence(string str) {
	// WV recommended
	// nice question, think, wv, logic
	string originalString = str;
	reverse(str.begin(), str.end());

	return longestCommonSubsequence(str, originalString);
}

int main()
{
	/*
	NOTE: same code as in Longest common subsequence, just a slight variation(Think, WV)
	STRONG PREREQUISITE: Longest common subsequence
	LEETCODE: https://leetcode.com/problems/longest-palindromic-subsequence/description/
	VIDEO LINK: https://www.youtube.com/watch?v=6i_T5kkfv4A&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=29
	*/
	string str = "bbbab";
	cout << longestPallindromicSubsequence(str);
}