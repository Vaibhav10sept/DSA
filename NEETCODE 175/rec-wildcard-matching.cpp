#include <bits/stdc++.h>
using namespace std;

bool rec(int i, int j, string pattern, string str, vector<vector<int>> &memo) {
	if (i < 0) { // means pattern is exhausted
		if (j < 0) { //str is also exhausted string matched return true
			return true;
		}
		else { //pattern is over but not str
			return false;
		}
	}
	if (j < 0) { //means str is exhausted
		//pattern has some characters, logic: pattern should have all * to be equal to str(which is empty)THINK.
		for (int k = 0; k <= i; k++) {
			if (pattern[k] != '*') return false;
		}
		return true;
	}
	//base case ends

	if (memo[i][j] != -1) return memo[i][j];

	if (pattern[i] == str[j] or pattern[i] == '?') {
		return rec(i - 1, j - 1, pattern, str, memo);
	}

	// pattern[i] != str[j]
	if (pattern[i] == '*') {
		//this if is the most crucial part and trick WV recommnedne
		//case1: * is nothing("")
		bool Nothing = rec(i - 1, j, pattern, str, memo);

		//case2: * has one or more character(this is the most tricky part)
		//recursion tree bnao or dry run krke dekho(WV)
		bool something = rec(i, j - 1, pattern, str, memo);

		return memo[i][j] = Nothing or something; //dono me se ek bhi true return krega to true return hoga.
	}

	return memo[i][j] = false; //match nhi kia '*' nhi hai to false return pattern and str match nhi hue
}

bool wildCardMatching(string pattern, string str) {
	vector<vector<int>> memo(pattern.size(), vector<int>(str.size(), -1));
	return rec(pattern.size() - 1, str.size() - 1, pattern, str, memo);
}

int main() {
	/*********************************
	 * NOTE: solve in order first rec solution then dp, kyoki hm rec ko dp solution me convert krte hai
	 * DP solution also there.
	 * PREREQUISITE: edit distance and distinct subsequence
	 * NOTE: this question is the application of edit distance and distinct subsequence.
	LEETCODE: https://www.codingninjas.com/studio/problems/wildcard-pattern-matching_701650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videoshttps://www.youtube.com/watch?v=ZmlQ3vgAOMo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=35
	VIDEO LINK: https://www.youtube.com/watch?v=ZmlQ3vgAOMo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=35
	*********************************/
	string pattern = "ab*cd";
	string str = "abdefcd";

	bool ans = wildCardMatching(pattern, str);
	if (ans ) cout << "true";
	else cout << "false";
}