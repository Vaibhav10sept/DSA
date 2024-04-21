#include <bits/stdc++.h>
using namespace std;

string longestHappyPrefix(string str) {
	//nice logic, wv if required

	string prefix = "";
	string suffix = "";
	int n = str.size();
	int lengthOfLongestPrefix = 0;
	string ans = "";

	for (int i = 0; i < n - 1; i++) {
		prefix += str[i];
		suffix = str[n - 1 - i] + suffix;

		if (prefix == suffix) {
			if (i + 1 > lengthOfLongestPrefix) {
				ans = str.substr(0, i + 1);
				lengthOfLongestPrefix = i + 1;
			}
		}
	}
	return ans;
}

int main() {
	/************************************
	 * NOTE: this will give memory limit exceeded on leetcode
	 * QUESTION: https://leetcode.com/problems/longest-happy-prefix/
	// VIDEO LINK: https://www.youtube.com/watch?v=wuL8a7bStFg
	//************************************/
	string s = "ababab";
	cout << longestHappyPrefix(s);
}


