#include <bits/stdc++.h>
using namespace std;

int countSubsetsWithSumK(vector<int> arr, int target) {
	vector<vector<int>> dp(arr.size() + 1, vector<int> (target + 1, false));
	// row --> array ke element hote h, means subsets hote h
	// col --> target hota h
	// dp[i][j] --> store count of subsets using values till arr[i-1](bcoz array index is one less than the row(i) in dp) and target as j.
	for (int i = 0; i < dp.size() ; i++) { // row --> array ke elements
		for (int j = 0; j < dp[0].size(); j++) {
			//first row and first column means 0 sum and empty subset
			if (i == 0 and j == 0) {
				dp[i][j] = 1;
			}
			//first row means no data in the subset(empty subset)
			else if (i == 0) {
				dp[i][j] = 0;
			}
			//initialization ends

			//for every other cells
			else {
				dp[i][j] += dp[i - 1][j]; //not pick
				int val = arr[i - 1]; // bcoz array index is 1 less than the row no(i). think
				if (val <= j) {
					dp[i][j] += dp[i - 1][j - val]; //pick
				}
			}
		}
	}

	return dp[arr.size()][target];
}

int main()
{
	/***************************

	 * NOTE: there is a recursive solution also.
	VIDEO LINK: https://www.youtube.com/watch?v=ZHyb-A2Mte4&t=46s
	QUESTION LINK: https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/
	subset/subsequence: 2^n; har element ke pass 2 option hai ya toh subset me aae
	ya na aae
	subarray: N*(N+1)/2; subarray continuous hote hai
	//**************************************************/
	vector<int> arr =  {0, 0, 1};
	int target = 1;

	cout << "result " << countSubsetsWithSumK(arr, target);
}