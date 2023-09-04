#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	string ans;

	for (int i = 0; i < strs[0].size(); i++) {
		for (int j = 1; j < strs.size(); j++) {
			if (strs[0][i] != strs[j][i]) {
				return ans;
			}
		}
		ans += strs[0][i];
	}

	return ans;
}

int main() {
	/*********************************
	VIDEO: no video required
	QUESTION: https://leetcode.com/problems/longest-common-prefix/description/
	//*********************************/
	vector<string> strs = {"flower", "flow", "flight"};
	cout << longestCommonPrefix(strs);
}