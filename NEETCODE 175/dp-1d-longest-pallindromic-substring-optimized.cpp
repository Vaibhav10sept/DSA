#include <bits/stdc++.h>
using namespace std;

string longestPallindromicSubstrings(string str) {
	// WV
	string ans = "";
	int longestLength = INT_MIN;

	//for odd length pallindrome
	for (int i = 0; i < str.size(); i++) {
		int left = i;
		int right = i;
		while (left >= 0 and right < str.size() and str[left] == str[right]) {
			if (right - left + 1 > longestLength) {
				longestLength = right - left + 1;
				ans = str.substr(left, longestLength);
			}
			left--;
			right++;
		}


		//for even length pallindrome
		left = i;
		right = i + 1; //rem., crucial part(WV)
		while (left >= 0 and right < str.size() and str[left] == str[right]) {
			if (right - left + 1 > longestLength) {
				longestLength = right - left + 1;
				ans = str.substr(left, longestLength);
			}
			left--;
			right++;
		}
	}
	return ans;
}

int main()
{
	/*
	NOTE: a 2d DP solution is also there. this one is space optimized.
	STRONG PREREQUISITE: count-pallindromic-substrings(a slight change in this prob code will give you the ans)
	LEETCODE: https://leetcode.com/problems/longest-palindromic-substring/
	VIDEO LINK: https://www.youtube.com/watch?v=XYQecbcd6_c
	*/
	string str = "cbbd";
	cout << longestPallindromicSubstrings(str);
}