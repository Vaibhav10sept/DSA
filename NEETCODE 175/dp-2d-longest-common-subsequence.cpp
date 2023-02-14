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
	vector<vector<int>> dp(str1.size(), vector<int>(str2.size()));
	//STORAGE: dp[i][j] --> stores the max length of common subsequence using the str1 from ith idx to end and str2 from jth idx to end.
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (str1[i] == str2[j]) {
				dp[i][j] += 1; // + 1 think, crucial
				dp[i][j] += (i + 1 < n and j + 1 < m) ? dp[i + 1][j + 1] : 0;
			}
			else { // str1[i] != str2[j]
				if (i + 1 < n) {
					dp[i][j] = dp[i + 1][j];
				}
				if (j + 1 < m) {
					dp[i][j] = max(dp[i][j], dp[i][j + 1]);
				}
			}
		}
	}
	cout << "sdf";
	displayMatrix(dp);

	return dp[0][0];
}

int main() {
	/*********************************
	 * NOTE: a recursive code is also there.
	LEETCODE: https://leetcode.com/problems/longest-common-subsequence/
	VIDEO LINK: https://www.youtube.com/watch?v=9UEHPiK53BA
	*********************************/
	string text1 = "aa";
	string text2 = "aa";

	cout << longestCommonSubsequence(text1, text2);
}