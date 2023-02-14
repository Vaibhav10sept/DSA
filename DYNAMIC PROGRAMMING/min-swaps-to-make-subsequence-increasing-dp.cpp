#include <bits/stdc++.h>
using namespace std;

int minSwapToMakeSubsequenceIncreasing(vector<int> arr1, vector<int> arr2) {
	int n = arr1.size();
	vector<vector<int>> dp(n + 1, vector<int>(2, 0));

	for (int idx = n - 1; idx >= 1; idx--) {
		for (int swapped = 1; swapped >= 0; swapped--) {
			int ans = INT_MAX;
			int prev1 = arr1[idx - 1];
			int prev2 = arr2[idx - 1];

			if (swapped) { //think, WV
				swap(prev1, prev2);
			}

			if (arr1[idx] > prev1 and arr2[idx] > prev2) {
				//no swap
				ans = dp[idx + 1][0];
			}
			if (arr1[idx] > prev2 and arr2[idx] > prev1) { //see the if clearly, think, WV
				//swap happened
				ans = min(ans, 1 + dp[idx + 1][1]); // + 1 bcoz , swapping hue to count of swapping is incresed by 1
			}

			dp[idx][swapped] = ans;
		}
	}
	return dp[1][0];
}

int main()
{
	/***************************
	 * NOTE: leetcode me wrong ans aa rha, pta nhi kyo, memo vala submit ho rha
	 * PREREQUISITE: recursive and memoized solution
	 * NOTE: this is  a dp solution, othere solutions are also there
	VIDEO LINK: https://www.youtube.com/watch?v=IeT9Qz_vqHo
	LEETCODE LINK: https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/
	//**************************************************/
	vector<int> nums1 = {0, 3, 5, 8, 9};
	vector<int> nums2 = {2, 1, 4, 6, 9};
	cout << minSwapToMakeSubsequenceIncreasing(nums1, nums2);
}