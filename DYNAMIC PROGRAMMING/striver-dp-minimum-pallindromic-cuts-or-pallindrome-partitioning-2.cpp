#include <bits/stdc++.h>
using namespace std;

bool isPallindrome(int start, int end, string str) {
	if (start == end) return true; //one size string is pallindrome
	while (start < end) {
		if (str[start] != str[end]) {
			return false;
		}
		start++;
		end--;
	}

	return true;
}

int pallindromePartitioning2(string str) {
	// * NOTE: this code is written by deriving through the recursive code.
	int n = str.size();
	vector<int> dp(n + 1, 0); //1d memoization
	dp[n] = 0; //initialization

	for (int ind = n - 1; ind >= 0; ind--) {
		int minCuts = INT_MAX;
		for (int i = ind; i < str.size(); i++) {
			if (isPallindrome(ind, i, str)) {
				minCuts = min(minCuts, 1 + dp[i + 1]);
			}
		}
		dp[ind] = minCuts;
	}

	return dp[0] - 1; //-1 kyo kia ye pta h(wv, think, cs)
}

int main()
{
	/***************************
	 * NOTE: not submit on leetcode, another dp(pepcoding) solution is there, which will submit.
	 * PREREQUISITE: this is derived from the recursive solution striver-rec-minimum-pallindromic-cuts-or-pallindrome-partitioning-2
	 * NOTE: please go through the recrusive solution and then derive this dp solution from it.
	 * NOTE: this code is written by me after solving the rec code
	 * NOTE: rec solution is also there.
	video link: https://www.youtube.com/watch?v=_H8V5hJUGd0&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=54
	LEETCODE LINK: https://leetcode.com/problems/palindrome-partitioning-ii/
	//**************************************************/
	string str = "cdd";
	cout << pallindromePartitioning2(str);
}