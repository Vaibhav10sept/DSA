#include <bits/stdc++.h>
using namespace std;

bool wildCardMatching(string pattern, string str) {
	int n = pattern.size();
	int m = str.size();
	vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
	//rows --> pattern
	//cols --> str
	//cell --> holds the true/false whether it's possible to match the pattern till i-1th index to str till j-1th index

	//initialization
	dp[0][0] = true; //both pattern and str is over means matched put true

	//pattern is over but not str
	for (int j = 1; j <= m; j++) dp[0][j] = false;

	//str is exhausted, but not pattern
	for (int i = 1; i <= n; i++) {
		//pattern has some characters, logic: pattern should have all * to be equal to str(which is empty)THINK.
		bool flag = true;
		for (int k = 0; k < i; k++) {
			if (pattern[k] != '*') {
				flag = false;
				break;
			}
		}
		dp[i][0] = flag;
	}
	//initialization ends

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			//match
			if (pattern[i - 1] == str[j - 1] or pattern[i - 1] == '?') {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else { //not match
				if (pattern[i - 1] == '*') { //this if is the most crucial part and trick WV recommnedne
					//case1: * is nothing("")
					bool nothing = dp[i - 1][j];

					//case2: * has one or more character(this is the most tricky part)
					//recursion tree bnao or dry run krke dekho(WV)
					bool something = dp[i][j - 1];

					dp[i][j] = nothing or something;  //dono me se ek bhi true return krega to true return hoga.
				}
			}
		}
	}
	return dp[n][m];
}

int main() {
	/*********************************
	 * NOTE: solve in order first rec solution then dp, kyoki hm rec ko dp solution me convert krte hai
	 * first solution rec then derive the dp solution.
	 * PREREQUISITE: edit distance and distinct subsequence
	 * NOTE: this question is the application of edit distance and distinct subsequence.
	LEETCODE: https://www.codingninjas.com/studio/problems/wildcard-pattern-matching_701650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videoshttps://www.youtube.com/watch?v=ZmlQ3vgAOMo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=35
	VIDEO LINK: https://www.youtube.com/watch?v=fJaKO8FbDdo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=34
	*********************************/
	string pattern = "ab*cd";
	string str = "abdefcd";

	bool ans = wildCardMatching(pattern, str);
	if (ans ) cout << "true";
	else cout << "false";
}