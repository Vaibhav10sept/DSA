#include <bits/stdc++.h>
using namespace std;

bool wordBreakRecursive(string str, set<string> st) {
	//BC
	if (str.size() == 0) return true;

	string curr = "";
	int i = 0;
	for (; i < str.size(); i++) {
		curr += str[i];
		if (st.find(curr) != st.end()) { //found
			// cout << "curr " << curr << endl;
			string restOfQuestion = i + 1 < str.size() ? str.substr(i + 1) : "";
			// cout << "rest " << restOfQuestion << endl;
			return wordBreakRecursive(restOfQuestion, st);
		}
	}

	if (i == str.size()) return false;
}

bool wordBreak(string str, vector<string> arr) {
	set<string> st(arr.begin(), arr.end());
	return wordBreakRecursive(str, st);
}

int main() {
	/*********************************
	LEETCODE: https://leetcode.com/problems/word-break/
	VIDEO LINK: https://www.youtube.com/watch?v=Sx9NNgInc3A
	*********************************/
	string str = "catsandog";
	vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
	bool ans = wordBreak(str, wordDict);
	if (ans) cout << "true";
	else cout << "false";
}