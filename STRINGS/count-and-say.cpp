#include <bits/stdc++.h>
using namespace std;

string countAndSayHelper(string str) {
	// * NOTE: I wrote it myself, no video no reading no help

	int i = 0;
	int cnt = 0;
	string ans = "";
	while (i < str.size() - 1) {
		cnt = 1;
		while (str[i] == str[i + 1] and i < str.size() - 1) {
			i++;
			cnt++;
		}

		ans += to_string(cnt);
		ans += str[i];
		i++;
	}

	//add the last char
	if (i == str.size() - 1) {
		ans += "1";
		ans += str[i];
	}

	return ans;
}

string countAndSay(int n) {
	// * NOTE: I wrote it myself, no video no reading no help
	string ans = "1";
	for (int i = 1; i < n; i++) {
		ans = countAndSayHelper(ans);
	}
	return ans;
}


int main() {
	/************************************
	 * NOTE: I wrote it myself, no video no reading no help
	 * QUESTION: https://leetcode.com/problems/count-and-say/
	// VIDEO LINK:
	//************************************/
	int n = 4;
	cout << countAndSay(n);
}


