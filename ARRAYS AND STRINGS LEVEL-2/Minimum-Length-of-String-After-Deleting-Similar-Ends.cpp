#include <bits/stdc++.h>
using namespace std;

int MinimumLengthofStringAfterDeletingSimilarEnds(string str) {
	int i = 0;
	int j = str.size() - 1;
	while (i < j) {
		if (str[i] == str[j]) {
			char ch = str[i];
			while (i < j and str[i] == ch) i++;
			//PLEASE THINK ABOUT THE "<=" IN THE BELOW CODE.(WATCH VIDEO).THIS WILL HANDLE ONE EDGE CASE
			while (i <= j and str[j] == ch) j--;
		}
		else {
			break;
		}
	}
	// cout << "i " << i << " " << j << endl;
	return j - i + 1;
}

int main() {
	//*********************************
	// NOTE:
	// LEETCODE LINK: https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/
	// VIDEO LINK: https://www.youtube.com/watch?v=PIs1EArGpIQ&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=76
	//*********************************
	// string str = "cabaabac";
	string str = "bbbbbbbbbbbbbbbbbbbbbbbbbbbabbbbbbbbbbbbbbbccbcbcbccbbabbb";
	cout << MinimumLengthofStringAfterDeletingSimilarEnds(str);
}