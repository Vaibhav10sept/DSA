#include<bits/stdc++.h>
using namespace std;

void recursiveHelper(int n, int open, int close, string ansSoFar, vector<string> &ans) {
	if (open == n and close == n) {
		ans.push_back(ansSoFar);
	}
	if (open < n) {
		recursiveHelper(n, open + 1, close, ansSoFar + "(", ans);
	}
	if (close < open) {
		recursiveHelper(n, open, close + 1, ansSoFar + ")", ans);
	}
}

vector<string> generateParentheses(int n) {
	/*
	NOTE:
	open --> no of open braces so far
	close --> no of close braces so far
	RULES:
	1. add open bracket if open < n
	2. base case: if open == n and close == n
	3. add close if and only if close < open
	*/
	vector<string> ans;
	recursiveHelper(n, 0, 0, "", ans);
	return ans;
}

int main() {
	/*
	NOTE: this is recursion
	VIDEO LINK: https://www.youtube.com/watch?v=s9fokUqJ76A
	LEETCODE LINK: https://leetcode.com/problems/generate-parentheses/
	*/
	int n = 2;
	vector<string> arr =  generateParentheses(n);
	for (auto ele : arr) cout << ele << endl;
}