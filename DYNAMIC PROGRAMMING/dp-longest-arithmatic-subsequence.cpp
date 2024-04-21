#include <bits/stdc++.h>
using namespace std;

int longestArithmaticSubsequence(vector<int> arr) {
	// * NOTE: this code is derived from the rec solution, so go through the rec then derive dp solution
	int n = arr.size();
	if (n <= 2) return n; //edge case(think, cs)

	vector< unordered_map<int, int>> dp(n + 1);
	//storage: means memo ke har index me ek map hoga jo diff->length ko store krega

	int longestLength = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			int diff = arr[i] - arr[j];
			int currLength = 1;

			if (dp[j].find(diff) != dp[j].end()) { //found
				currLength = dp[j][diff];
			}

			dp[i][diff] = 1 + currLength;
			longestLength = max(longestLength, dp[i][diff]);
		}
	}

	return longestLength;
}


int main()
{
	/***************************
	 * NOTE: this code is derived from the rec solution, so go through the rec then derive dp solution
	 * NOTE: this is dp solution, rec and iterative are also there.
	 * NOTE: wv recommended
	VIDEO LINK: https://www.youtube.com/watch?v=YaMcX7sem70&t=2s
	LEETCODE LINK: https://leetcode.com/problems/longest-arithmetic-subsequence/
	//**************************************************/
	vector<int> arr = {3, 6, 9, 12};
	cout << longestArithmaticSubsequence(arr);
}