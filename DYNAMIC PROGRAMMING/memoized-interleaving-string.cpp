#include <bits/stdc++.h>
using namespace std;

bool interleavingStringMemoHelper(int i, int j, string s1, string s2, string s3, map<pair<int, int>, bool> &memo) {
	//NOTE: we can calculate the pointer for s3 by i + j;
	//where i is the pointer for s1 and j is the pointer for s2
	if (i + j == s3.size()) {
		if (i == s1.size() and j == s2.size()) return true;
		return false;
	}
	//BC ends
	//memoization
	if (memo.find({i, j}) != memo.end()) { //found
		return memo[ {i, j}];
	}
	int firstAns = false;
	int SecondAns = false;

	if (i < s1.size() and s1[i] == s3[i + j]) {
		firstAns = interleavingStringMemoHelper(i + 1, j, s1, s2, s3, memo);
	}
	if (j < s2.size() and s2[j] == s3[i + j]) {
		SecondAns = interleavingStringMemoHelper(i, j + 1, s1, s2, s3, memo);
	}

	return memo[ {i, j}] = firstAns or SecondAns; //logic: agr ek bhi true h to true return hoga.
}

int interleavingStringMemo(string s1, string s2, string s3) {
	// WV recommended.
	// edge case
	if (s1.size() + s2.size() != s3.size()) return false;
	map<pair<int, int>, bool> memo; //pair-->ith,jth  VS  bool(true/false)

	return interleavingStringMemoHelper(0, 0, s1, s2, s3, memo);
}

int main()
{
	/***************************
	 * NOTE: this is the memoized solution, a dp solution is also there.
	VIDEO LINK: https://www.youtube.com/watch?v=3Rw3p9LrgvE
	QUESTION LINK: https://leetcode.com/problems/interleaving-string/
	//**************************************************/
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbbaccc";

	bool ans = interleavingStringMemo(s1, s2, s3);
	if (ans) cout << "true";
	else cout << "false";
}