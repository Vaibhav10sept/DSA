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

int rec(int ind, string str, vector<int> &memo) {  // * NOTE: this code is written by me after WV
	if (ind == str.size()) return 0;

	if (isPallindrome(ind, str.size() - 1, str)) return 0; //think-> edge case agr ind se end tk ki puri substring hi pallindrome hogi to no need to check further, 0 cuts return kr do direct

	if (memo[ind] != -1) return memo[ind];

	int minCuts = INT_MAX;
	for (int i = ind; i < str.size(); i++) {
		if (isPallindrome(ind, i, str)) {
			minCuts = min(minCuts, 1 + rec(i + 1, str, memo));
		}
	}
	return memo[ind] = minCuts;
}

int pallindromePartitioning2(string str) {
	// * NOTE: this code is written by me after WV
	vector<int> memo(str.size(), -1); //1d memoization
	return rec(0, str, memo);
}

int main()
{
	/***************************
	 * NOTE: this code is written by me after WV
	 * NOTE: gives TLE on leetcode, dp solution submit hoga
	 * NOTE: dp solution is also there.
	STRONG PREREQUISITE: pallindrome partitioning backtracking(similar code pattern)
	video link: https://www.youtube.com/watch?v=_H8V5hJUGd0&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=54
	LEETCODE LINK: https://leetcode.com/problems/palindrome-partitioning-ii/
	//**************************************************/
	string str = "cdd";
	cout << pallindromePartitioning2(str);
}