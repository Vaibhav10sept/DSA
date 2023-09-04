#include <bits/stdc++.h>
using namespace std;

string longestPallindromicSubstrings(string str) {
	// WV recommended
	// nice question, think, wv, logic
	//STORAGE:
	// row --> represent the start of substring
	// col --> represent the end of substring
	// CELL --> every cell stores the boolean(true/false).
	//          ie., substring start from ith index and ends at jth index is pallindromic or not.

	vector<vector<bool>> dp(str.size(), vector<bool>(str.size(), false));
	int lenghtOfLongestPallindromicSubstring = INT_MIN;
	string ans = "";
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
			if (dp[i][j] == true) {
				int length = j - i + 1; //end idx - start idx + 1 --> length of substring
				if (lenghtOfLongestPallindromicSubstring < length) {
					ans = str.substr(i, length);
					lenghtOfLongestPallindromicSubstring = length;
				}
			}
		}
	}
	return ans;
}

int main()
{
	/*
	STRONG PREREQUISITE: count-pallindromic-substrings(a slight change in this prob code will give you the ans)
	LEETCODE: https://leetcode.com/problems/longest-palindromic-substring/
	VIDEO LINK: https://www.youtube.com/watch?v=WpYHNHofwjc
	*/
	string str = "abb";
	cout << longestPallindromicSubstrings(str);
}