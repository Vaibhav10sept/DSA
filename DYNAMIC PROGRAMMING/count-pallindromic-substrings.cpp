#include <bits/stdc++.h>
using namespace std;

int countPallindromicSubstrings(string str) {
	// WV recommended
	// nice question, think, wv, logic
	//STORAGE:
	// row --> represent the start of substring
	// col --> represent the end of substring
	// CELL --> every cell stores the boolean(true/false).
	//          ie., substring start from ith index and ends at jth index is pallindromic or not.

	vector<vector<bool>> dp(str.size(), vector<bool>(str.size(), false));
	int countOfPallindromicSubString = 0;
	//NOTE: here we are doing upper diagonal wise traversal(WV, CS)

	for (int gap = 0; gap < dp.size(); gap++) {
		for (int i = 0, j = gap; i < dp.size() and j < dp.size(); i++, j++) {
			if (gap == 0) { //means str.size() = 1, one size ki substring pallindrome hoti h
				//initialization
				dp[i][j] = true;
			}
			else if (gap == 1) { //means str.size() = 2, two size ki substring ko easy check kr skte h ki vo pallindrome hai ya nhi
				//initialization
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
			if (dp[i][j] == true) countOfPallindromicSubString++;
		}
	}
	return countOfPallindromicSubString;
}

int main()
{
	/*
	LEETCODE: https://leetcode.com/problems/palindromic-substrings/
	VIDEO LINK: https://www.youtube.com/watch?v=XmSOWnL6T_I
	*/
	string str = "abc";
	cout << "count is: " << countPallindromicSubstrings(str);
}