#include <bits/stdc++.h>
using namespace std;

bool wordBreak(string str, vector<string> arr) {
	// WV recommended
	//this is my own solution
	//you can watch video, for logic but this solution is written by me only
	vector<bool> dp(str.size() + 1, false);
	//LOGIC: dp[i] --> contains boolean which represent that a substring from ith index to end vali substring se kya word dictionary ke words ko use krte hue bnae ja skti h
	set<string> st(arr.begin(), arr.end());

	//initialization
	dp[str.size()] = true; //means str.size() pe to true hi hoga kyoki hm str ke end pe pahunch gae h.(think, WV)

	for (int i = str.size() - 1; i >= 0; i--) {

		for (string ele : arr) {
			int stringSize = ele.size();
			// string subString = stringSize <= str.size() ? str.substr(i, stringSize) : "";
			string subString = str.substr(i, stringSize);
			// cout << "sub " << subString << endl;
			// cout << "siz " << stringSize << endl;
			// cout << "ele " << ele << endl;
			if (ele == subString) {
				// cout << "i " << dp[i + subString.size()] << endl;
				if (i + subString.size() < dp.size()) {
					if (dp[i + subString.size()]) {
						dp[i] = true;
						break; //think, agr ek word from wordict se true mil jata h to baki ke word ke sath check krne ki jrurt nhi
					}
				}
				else {
					dp[i] = true;
				}
			}

		}
	}
	for (auto ele : dp) cout << ele << " ";
	cout << endl;
	//think
	return dp[0];
}

int main() {
	/*********************************
	LEETCODE: https://leetcode.com/problems/word-break/
	VIDEO LINK: https://www.youtube.com/watch?v=Sx9NNgInc3A
	*********************************/
	// string str = "leetcode";
	// vector<string> wordDict = {"leet", "code"};

	string str = "abcd";
	vector<string> wordDict = {"a", "abc", "b", "cd"};
	bool ans = wordBreak(str, wordDict);
	if (ans) cout << "true";
	else cout << "false";
}