#include <bits/stdc++.h>
using namespace std;

vector<string> concatenatedWords(vector<string> arr) {
	//NOTE: go through word break DP solution first, this code has been derived from that question only
	vector<string> ans;

	for (int i = 0; i < arr.size(); i++) {
		string str = arr[i];

		vector<bool> dp(str.size() + 1, false);
		dp[str.size()] = true; //initialization

		for (int j = str.size() - 1; j >= 0; j--) {

			for (int k = 0; k < arr.size(); k++) {
				if (k == i) continue;

				string dictWord = arr[k];
				int stringSize = dictWord.size();
				string subString = str.substr(j, stringSize);

				if (dictWord == subString) {
					if (j + subString.size() < dp.size()) {
						if (dp[j + subString.size()]) {
							dp[j] = true;
						}
					}
					else {
						dp[j] = true;
					}
				}
			}

		}

		if (dp[0] == true) ans.push_back(str);
	}
	return ans;
}

int main() {
	/*********************************
	 * NOTE: I wrote this code, this code has been derived from the preq, no video required.
	 * NOTE: will give TLE
	 STRONG PREQ: dp 1d word break
	LEETCODE: https://leetcode.com/problems/concatenated-words/
	VIDEO LINK:
	*********************************/

	vector<string> arr = {"cat", "dog", "catdog"};
	vector<string> ans = concatenatedWords(arr);
	for (auto ele : ans) cout << ele << endl;
}