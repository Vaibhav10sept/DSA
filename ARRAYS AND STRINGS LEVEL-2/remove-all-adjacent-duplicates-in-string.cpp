#include <bits/stdc++.h>
using namespace std;

string removeAdjacent(string str) {
	//NOTE: i wrote it myself, no vidoe, no reading
	string ans = "";
	for (int i = 0; i < str.size(); i++) {
		if (ans.size() == 0) {
			ans += str[i];
		}
		else {
			if (ans[ans.size() - 1] == str[i]) {
				ans.pop_back();
			}
			else {
				ans += str[i];
			}
		}
	}
	return ans;
}

int main() {
	/*********************************
	 * //NOTE: i wrote it myself, no vidoe, no reading
	// VIDEO LINK:
	// QUESTION: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

	//*********************************/
	string s = "abbaca";
	cout << removeAdjacent(s);
}