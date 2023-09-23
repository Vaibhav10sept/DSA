//recursive code hai ye---dp nhi use ki hai isme, dp code is also there.
#include <bits/stdc++.h>
using namespace std;

int rec(int i, int j, string s1, string s2, string ans, string &longestCommonSubsequenceResult) {
	if (i < 0 or j < 0) {
		if (ans.size() > longestCommonSubsequenceResult.size()) {
			longestCommonSubsequenceResult = ans;
		}
		return 0; //NOTE: return me hm size of longest common subsequence kr rhe hai
	}
	//BC ends

	if (s1[i] == s2[j]) {
		return 1 + rec(i - 1, j - 1, s1, s2, s1[i] + ans, longestCommonSubsequenceResult);
	}
	else { //s1[i] != s2[j]: think, cs, wv
		return max(rec(i - 1, j, s1, s2, ans, longestCommonSubsequenceResult), rec(i, j - 1, s1, s2, ans, longestCommonSubsequenceResult));
	}
}

int longestCommonSubsequence(string s1, string s2) {
	string longestCommonSubsequenceResult = "";
	int lenghtOfLCS = rec(s1.size() - 1, s2.size() - 1, s1, s2, "", longestCommonSubsequenceResult);
	cout << "LCS is: " << longestCommonSubsequenceResult << endl;
	return lenghtOfLCS;
}


int main() {
	/*********************************
	* NOTE: a 2D dp code is also there.
	LEETCODE: https://leetcode.com/problems/longest-common-subsequence/
	VIDEO LINK: https://www.youtube.com/watch?v=NPZn9jBrX8U&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=26
	*********************************/
	string s1 = "abc";
	string s2 = "abc";
	cout << "length of LCS: " << longestCommonSubsequence(s1, s2); //this will also print the longest common subsequence.
}