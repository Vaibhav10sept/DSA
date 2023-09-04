#include <bits/stdc++.h>
using namespace std;

int pallindromePartitioning2(string str) {
	// WV highly recommended --> gap strategy is used here.
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

	vector<vector<int>> dpInt(str.size(), vector<int>(str.size(), 0));
	//STORAGE: har cell storage the min cuts to make the substring starting at ith index and ending at jth index pallidrome, so we will get the ans at the top right corner of the dp(think,wv)
	//NOTE: here we are doing upper diagonal wise traversal(WV), following gap strategy

	for (int gap = 0; gap < dpInt.size(); gap++) {
		for (int i = 0, j = gap; i < dpInt.size() and j < dpInt.size(); i++, j++) {
			if (gap == 0) { //means str.size() = 1, one size ki substring pallindrome hoti h
				dpInt[i][j] = 0;
			}
			else if (gap == 1) { //means str.size() = 2, two size ki substring ko easy check kr skte h ki vo pallindrome hai ya nhi
				if (str[i] == str[j]) { //pallidrome h so no cuts required
					dpInt[i][j] = 0;
				}
				else { //do size ki substring h or pallindrome nhi h to 1 cut se pallindrome bn jaegi(think,WV)
					dpInt[i][j] = 1;
				}
			}
			else { //for every other upper matrix cell(note: sirf upper matrix ko diagonally traversal kr rhe h hum(WV, think))
				if (dp[i][j]) {
					//means already a pallindromic substring so 0 cut required
					dpInt[i][j] = 0;
				}
				else { //not a pallidromic substring
					//crucial part, WV, high level of understanding required
					int minCuts = INT_MAX;
					for (int k = i; k < j; k++) {
						int left = dpInt[i][k];
						int right = dpInt[k + 1][j];
						minCuts = min(minCuts, left + right + 1);// +1 coz ek cut apna bhi to lgega coz ye substring pallidromic nhi h.
					}
					dpInt[i][j] = minCuts;
				}
			}
		}
	}
	//the ans is in the top right cell of dpInt (WV, think)
	return dpInt[0][str.size() - 1];
}

int main()
{
	/***************************
	NOTE: this is n^3 solution will give you TLE.
	STRONG PREREQUISITE: longest pallidromic substring
	video link: https://www.youtube.com/watch?v=qmTtAbOTqcg
	LEETCODE LINK: https://leetcode.com/problems/palindrome-partitioning-ii/
	//**************************************************/
	string str = "aab";
	cout << pallindromePartitioning2(str);
}