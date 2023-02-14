#include <bits/stdc++.h>
using namespace std;

int pallindromePartitioning2(string str) {
	// WV highly recommended
	// STORAGE:
	// row --> represent the start of substring
	// col --> represent the end of substring
	// CELL --> every cell stores the boolean(true/false).
	//          ie., substring start from ith index and ends at jth index is pallindromic or not.

	vector<vector<bool>> dp(str.size(), vector<bool>(str.size(), false));
	//NOTE: here we are doing upper diagonal wise traversal(WV

	for (int gap = 0; gap < dp.size(); gap++) {
		for (int i = 0, j = gap; i < dp.size() and j < dp.size(); i++, j++) {
			if (gap == 0) { //means str.size() = 1, one size ki substring pallindrome hoti h
				dp[i][j] = true;
			}
			else if (gap == 1) { //means str.size() = 2, two size ki substring ko easy check kr skte h ki vo pallindrome hai ya nhi
				if (str[i] == str[j]) {
					dp[i][j] = true;
				}
			}
			else { //for every other upper matrix cell(note: sirf upper matrix ko diagonally traversal kr rhe h hum(WV, think))
				if (str[i] == str[j] and dp[i + 1][j - 1] == true) {
					//crucial part, WV
					dp[i][j] = true;
				}
			}
		}
	}
	//********************************
	//NOTE: the above code is copied from longest pallindromic substring
	//********************************

	vector<int> dpInt(str.size());
	// STORAGE: every index hold the min no of cut required to make the substring from 0th indx to ith index pallindrom
	dpInt[0] = 0; // 0th index ki string means ek size ki substring, ek size ki substring to pallindrome hoti, to 0 cuts required

	// j --> defines the end of substring
	// i --> defines the start of substring
	for (int j = 1; j < str.size(); j++) {
		if (dp[0][j]) { //means ye puri string hi pallindrome h, to kuch calculate krne ki jrurt nhi, direct 0 likhdo(0 cut required hoge)
			dpInt[j] = 0;
		}
		else { //ye substring(0 to jth index) pallidrome nhi to hame kuch calculation krni pdegi
			int minCuts = INT_MAX;
			for (int i = j; i >= 1; i--) {
				//WV recommended
				if (dp[i][j]) { //mtlb ith to jth substring pallidrome
					if (dpInt[i - 1] < minCuts) {
						minCuts = dpInt[i - 1]; // why, i-1 think,WV
					}
				}
			}
			dpInt[j] = minCuts + 1;// +1 coz ek cut to apna bhi hoga
		}
	}
	return dpInt[str.size() - 1];
}

int main()
{
	/***************************
	NOTE: there is n^3 solution also that will give you TLE.
	NOTE: this is n^2 solution will not give you TLE.
	STRONG PREREQUISITE: longest pallidromic substring
	video link: https://www.youtube.com/watch?v=qmTtAbOTqcg
	LEETCODE LINK: https://leetcode.com/problems/palindrome-partitioning-ii/
	//**************************************************/
	string str = "a";
	cout << pallindromePartitioning2(str);
}