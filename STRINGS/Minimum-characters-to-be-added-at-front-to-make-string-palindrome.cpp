#include <bits/stdc++.h>
using namespace std;

bool isPallindrome(string str) {
	int i = 0;
	int j = str.size() - 1;
	while (i < j) {
		if (str[i] != str[j]) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}


int getLenghtOfLongestPallindromicPrefix(string str) {
	string temp = "";
	int ans = 0;
	for (int i = 0; i < str.size(); i++) {
		temp += str[i];
		if (isPallindrome(temp)) {
			ans = i + 1;
		}
	}
	return ans;
}

long long longestPallindromicSubstrings(string str) {
	// WV recommended
	// nice question, think, wv, logic
	//STORAGE:
	// row --> represent the start of substring
	// col --> represent the end of substring
	// CELL --> every cell stores the boolean(true/false).
	//          ie., substring start from ith index and ends at jth index is pallindromic or not.

	vector<vector<bool>> dp(str.size(), vector<bool>(str.size(), false));
	long long lenghtOfLongestPallindromicSubstring = INT_MIN;
	string ans = "";
	//NOTE: here we are doing upper diagonal wise traversal(WV

	for (long long gap = 0; gap < dp.size(); gap++) {
		for (long long i = 0, j = gap; i < dp.size() and j < dp.size(); i++, j++) {
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
				long long length = j - i + 1; //end idx - start idx + 1 --> length of substring
				if (lenghtOfLongestPallindromicSubstring < length) {
					ans = str.substr(i, length);
					lenghtOfLongestPallindromicSubstring = length;
				}
			}
		}
	}
	return lenghtOfLongestPallindromicSubstring;
}

int minCharacterAdded(string str) {
	//LOGIC: find the longest pallindromic prifix and return the str.size() - lenghtOfLongestPallindromicPrefix
	long long lenghtOfLongestPallindromicSubstring = longestPallindromicSubstrings(str);
	return str.size() - lenghtOfLongestPallindromicSubstring;
}


int main() {
	/************************************
	 * QUESTION: https://practice.geeksforgeeks.org/problems/minimum-characters-to-be-added-at-front-to-make-string-palindrome/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
	// VIDEO LINK:
	//************************************/
	string S = "aacecaaa";
	cout << minCharacterAdded(S);

}


