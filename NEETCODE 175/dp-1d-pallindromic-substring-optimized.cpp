#include <bits/stdc++.h>
using namespace std;

int pallindromicSubstrings(string str) {
	// WV
	// TIME: O(n^2)
	int count = 0;

	for (int i = 0; i < str.size(); i++) {
		//for odd length pallindrome
		int left = i;
		int right = i;
		while (left >= 0 and right < str.size() and str[left] == str[right]) {
			count++;
			left--;
			right++;
		}


		//for even length pallindrome
		left = i;
		right = i + 1; //rem., crucial part(WV)
		while (left >= 0 and right < str.size() and str[left] == str[right]) {
			count++;
			left--;
			right++;
		}
	}
	return count;
}

int main()
{
	/*
	NOTE: a 2d DP solution is also there. this one is space optimized.
	STRONG PREREQUISITE: dp-1d-longest-pallindromic-substrings(a slight change in this prob code will give you the ans)
	LEETCODE: https://leetcode.com/problems/palindromic-substrings/
	VIDEO LINK: https://www.youtube.com/watch?v=4RACzI5-du8
	*/
	string str = "cbbd";
	cout << pallindromicSubstrings(str);
}