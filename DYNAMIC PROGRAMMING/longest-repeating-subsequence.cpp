#include <bits/stdc++.h>
using namespace std;

int longestRepeatingSubsequence(string str) {
	//WV highly recommended
	string str1 = str;
	string str2 = str;
	int n = str1.size();
	int m = str2.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	//STORAGE: dp[i][j] --> stores the max length of longest repeating subsequence

	for (int i = 1; i < dp.size(); i++) {
		for (int j = 1; j < dp[0].size(); j++) {
			if (str1[i - 1] == str2[j - 1] and i != j) { //NOTE: i != j this is the only change when compared to the code of longest common subsequence.
				//NOTE: i != j this is the only change when compared to the code of longest common subsequence.

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

int main()
{
	/*
	NOTE: same code as in Longest common subsequence, just a slight variation(Think, WV)
	STRONG PREREQUISITE: Longest common subsequence
	LEETCODE: https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
	VIDEO LINK: https://www.youtube.com/watch?v=hbTaCmQGqLg
	*/
	string str = "axxzxy";
	cout << longestRepeatingSubsequence(str);
}