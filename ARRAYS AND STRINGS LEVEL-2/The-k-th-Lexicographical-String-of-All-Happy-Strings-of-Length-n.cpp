#include <bits/stdc++.h>
using namespace std;

void printAllHappyStringOfN(int n, string ans, vector<string> &vecAns) {
	//this is base condition
	if (n == 0) {
		vecAns.push_back(ans);
		// cout << ans << endl;
		return;
	}
	vector<char> arr = {'a', 'b', 'c'};
	for (char ele : arr) {
		if (ans != "" ) {
			if (ele == ans[ans.size() - 1]) continue;
			printAllHappyStringOfN(n - 1, ans + ele, vecAns);
		}
		else { //ans == ""
			printAllHappyStringOfN(n - 1, ans + ele, vecAns);
		}
	}
}

int main() {
	//*********************************
	//NOTE: this is my solution using recursion the actual solution is more efficient.
	// VIDEO LINK: https://www.youtube.com/watch?v=4DQu4Z6f2XI&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=51
	// QUESTION:
// A happy string is a string that:

// consists only of letters of the set ['a', 'b', 'c'].
// s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
// For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

// Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.

// Return the kth string of this list or return an empty string if there are less than k happy strings of length n.
	//*********************************
	int n = 3;
	int k = 9;
	vector<string> ans;

	printAllHappyStringOfN(n, "", ans);
	if (k > ans.size()) {
		cout << "" << endl;
	}
	else {
		cout << ans[--k] << endl;
	}
}