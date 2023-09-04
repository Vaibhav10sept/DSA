#include <bits/stdc++.h>
using namespace std;
void displayMatrix(vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

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

int main() {
	/*********************************
	 * APPLICATION QUESTION: minimum insertion to make string pallindromic
	 * APPLICATION QUESTION: minimum Deletions and Insertions to convert string a to b.
	 * NOTE: a recursive code is also there.
	LEETCODE: https://leetcode.com/problems/longest-common-subsequence/
	VIDEO LINK: https://www.youtube.com/watch?v=NPZn9jBrX8U&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=26
	*********************************/
	string text1 = "aa";
	string text2 = "aa";

	cout << longestCommonSubsequence(text1, text2);
}