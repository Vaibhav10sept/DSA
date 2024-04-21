#include <bits/stdc++.h>
using namespace std;

int rec(int i, int j, string str1, string str2, vector<vector<int>> &memo) {
	//base case
	if (i < 0) { //str1 is exhausted. we need to insert the chars that are there in str2
		return j + 1;
	}
	if (j < 0) { //str2 is exhausted. we need to remove/delete chars that are there in str1
		return i + 1;
	}
	if (memo[i][j] != -1) return memo[i][j];

	if (str1[i] == str2[j]) {
		return rec(i - 1, j - 1, str1, str2, memo);
	}

	int deleteOperation = rec(i - 1, j, str1, str2, memo);
	int replaceOperation = rec(i - 1, j - 1, str1, str2, memo);
	int insertOperation = rec(i, j - 1, str1, str2, memo);
	return memo[i][j] = 1 + min(min(deleteOperation, replaceOperation), insertOperation);
}

int editDistance(string str1, string str2) {
	int n = str1.size();
	int m = str2.size();
	vector<vector<int>> memo(n, vector<int>(m, -1));
	return rec(n - 1, m - 1, str1, str2, memo);
}

int main() {
	/*********************************
	 * NOTE: this is rec solution, dp is also there
	 * PREREQUISITE: distinct subsequence
	 * NOTE: this question is the application of distinct subsequence.
	LEETCODE: https://leetcode.com/problems/edit-distance/
	VIDEO LINK: https://www.youtube.com/watch?v=fJaKO8FbDdo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=34
	*********************************/
	string word1 = "horse";
	string word2 = "ros";

	cout << editDistance(word1, word2);
}