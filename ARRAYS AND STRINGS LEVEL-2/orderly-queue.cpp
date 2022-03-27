#include <bits/stdc++.h>
using namespace std;

void put0thOnBack(string &str) {
	if (str == "") return;
	char ch = str[0];
	str.erase(0, 1);
	str += ch;
}

string orderlyQueue(string str, int k) {
	// nice question(hard) watch video.
	//CLAIM:
	//1. if k==1, use brute force
	//2. if k>1, return the sorted str(this is proofed in the video)
	if (k > 1) {
		sort(str.begin(), str.end());
		return str;
	}
	else {
		string ans = str;
		for (int i = 0; i < str.size(); i++) {
			put0thOnBack(str);
			// int diff = (int)ans - (int)str;
			if (ans > str) { // diff is -ve means str is smaller than ans, so update ans.
				ans = str;
			}

		}
		return ans;
	}
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=s0JtNntehsM&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=55https://www.youtube.com/watch?v=6cODUSGmYD4&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=56
	// QUESTION:
// You are given a string s and an integer k. You can choose one of the first k letters of s and append it at the end of the string..

// Return the lexicographically smallest string you could have after applying the mentioned step any number of moves.
	//*********************************
	string str = "baaca";
	int k = 3;

	cout << orderlyQueue(str, k);
}