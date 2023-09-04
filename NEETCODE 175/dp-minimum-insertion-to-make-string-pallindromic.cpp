#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string str1, string str2) {
	//WV highly recommended
	//NOTE: this is not 2d DP solution, recursive solution is also there
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
				dp[i][j] = max( dp[i - 1][j], dp[i][j - 1]);
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

int minInsertionToMakeStringPallindromic(string str) {
	//WV
	//NOTE: just find the Longest pallindromic subsequence and then substract it with the lenght of the given string(think, CS, WV)
	int n = str.size();
	int lenghtOfLongestPallindromicSubsequence = longestPallindromicSubsequence(str);
	return n - lenghtOfLongestPallindromicSubsequence;
}

int main() {
	/*********************************
	 * EXTENDED QUESTION OF: longest common subsequence and longest pallindromic subsequence.
	LEETCODE: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
	VIDEO LINK: https://www.youtube.com/watch?v=xPBLEj41rFU&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=30
	*********************************/
	string s = "mbadm";

	cout << minInsertionToMakeStringPallindromic(s);
}