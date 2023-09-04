#include <bits/stdc++.h>
using namespace std;

int distinctSubsequenceRecursiveHelper(int i, int j, string s, string t, vector<vector<int>> &memo) {
	if (j < 0) return 1; //string t is exhausted one subsequence found so return 1.(CS, think)
	if (i < 0) return 0; //not found string s is exhausted, so return 0(think, CS)
	//BC ends

	//memoization
	if (memo[i][j] != -1) return memo[i][j];

	//recursive calls for all the possbilities(WV)
	if (s[i] == t[j]) {
		return memo[i][j] = distinctSubsequenceRecursiveHelper(i - 1, j - 1, s, t, memo) + distinctSubsequenceRecursiveHelper(i - 1, j, s, t, memo);
	}
	else { // s[i] != t[j]
		return memo[i][j] = distinctSubsequenceRecursiveHelper(i - 1, j, s, t, memo);
	}

}

int distinctSubsequenceRecursive(string s, string t) {
	//WV highly recommended
	vector<vector<int>> memo(s.size(), vector<int> (t.size(), -1));
	return distinctSubsequenceRecursiveHelper(s.size() - 1, t.size() - 1, s, t, memo);
}

int main() {
	/*********************************
	 * this will give you TLE, a dp solution is also there.
	 * //THIS is recursive memo solution dp is also there
	LEETCODE: https://leetcode.com/problems/distinct-subsequences/
	VIDEO LINK(STRIVER TAKE PRIORITY): https://www.youtube.com/watch?v=nVG7eTiD2bY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=34
	VIDEO LINK: https://www.youtube.com/watch?v=nVG7eTiD2bY
	*********************************/
	string s = "rabbbit";
	string t = "rabbit";

	cout << distinctSubsequenceRecursive(s, t);
}