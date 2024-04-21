#include <bits/stdc++.h>
using namespace std;

bool isPallindrome(string str, int start, int end) {
	while (start < end) {
		if (str[start] != str[end]) {
			return false;
		}
		start++;
		end--;
	}
	return true;
}

void pallindromePartitioningBacktracking(string str, int idx, vector<string> ans, vector<vector<string>> &res) {
	//BC
	if (idx == str.size()) {
		res.push_back(ans);
		return;
	}
	//BC ends.


	for (int i = idx; i < str.size(); i++) {
		//check if substring from idx to i is a pallindrome
		if (isPallindrome(str, idx, i)) {
			//idx to i substring is a pallindrome so we can do the partition.
			ans.push_back(str.substr(idx, i - idx + 1)); //substr(starting idx, length)
			pallindromePartitioningBacktracking(str, i + 1, ans, res);
			//backtrack
			ans.pop_back();
		}
	}
}

vector<vector<string>> pallindromePartitioning(string str) {
	vector<vector<string>> res;
	vector<string> ans;

	pallindromePartitioningBacktracking(str, 0, ans, res);

	return res;
}

int main() {
	/*********************************
	 * APPLICATION QUESTION: minimum insertion to make string pallindromic
	 * PREREQUISITE: backtracking combination sum 2 optimized
	VIDEO LINK: https://www.youtube.com/watch?v=WBgsABoClE0
	LEETCODE LINK: https://leetcode.com/problems/palindrome-partitioning/
	*********************************/
	string s = "aabb";

	vector<vector<string>> ans = pallindromePartitioning(s);
	for (auto vec : ans) {
		for (auto ele : vec) {
			cout << ele << " ";
		}
		cout << endl;
	}
}