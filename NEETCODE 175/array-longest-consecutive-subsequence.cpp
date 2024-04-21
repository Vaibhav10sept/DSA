#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveSubsequence(vector<int> arr) {
	set<int> st(arr.begin(), arr.end());
	int longest = 0;

	for (int ele : arr) {
		//check if ele is the start of a subsequence(logic)
		if (st.find(ele - 1) != st.end()) { //found, that means no this ele cannot be the start of a subsequence

		}
		else { //ele can be the start of a subsequence
			//find the length of that subsequence;
			int len = 1;
			int nextNumber = ele + 1;
			while (st.find(nextNumber) != st.end()) {
				len++;
				nextNumber++;
			}
			longest = max(longest, len);
		}
	}
	return longest;
}

int main() {
	/*
	*********************************
	we are using set here
	TIME: O(n) --> this is required in leetcode
	VIDEO LINK: https://www.youtube.com/watch?v=P6RZZMu_maU
	LEETCODE LINK: https://leetcode.com/problems/longest-consecutive-sequence/
	*********************************
	*/
	vector<int> arr = {100, 4, 200, 1, 3, 2};
	cout << longestConsecutiveSubsequence(arr);
}