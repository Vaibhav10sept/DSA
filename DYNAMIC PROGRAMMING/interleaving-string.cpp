#include <bits/stdc++.h>
using namespace std;

int interleavingStringDp(string s1, string s2, string s3) {
	// WV recommended.
	// edge case
	if (s1.size() + s2.size() != s3.size()) return false;

	bool dp[s1.length() + 1][s2.length() + 1];
	//STORAGE: dp[i][j] --> hold the true/false for the substring from 0 to ith for s1 and 0 to jth index for s2 and 0 to i+j index for s3.
	//IMP NOTE: index of the stings is one less than the index of dp(i and j)
	for (int i = 0; i < s1.length() + 1; i++)
		for (int j = 0; j < s2.length() + 1; j++) {
			if (i == 0 && j == 0)
				dp[i][j] = true;
			else if (i == 0)
				dp[i][j] = ( dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			else if (j == 0)
				dp[i][j] = ( dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
			else
				dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1] ) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1] );
		}

	return dp[s1.length()][s2.length()];
}

int main()
{
	/***************************
	 * NOTE; this is dp solution, A memoized solution is also there
	VIDEO LINK: https://www.youtube.com/watch?v=3Rw3p9LrgvE
	QUESTION LINK: https://leetcode.com/problems/interleaving-string/
	//**************************************************/
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbcbcac";

	bool ans = interleavingStringDp(s1, s2, s3);
	if (ans) cout << "true";
	else cout << "false";
}