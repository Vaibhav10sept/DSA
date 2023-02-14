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

int countPartitionsWithGivenDifference(vector<int> arr, int diff) {
	int totalSum = 0;
	for (auto ele : arr) totalSum += ele;

	if ((totalSum - diff) % 2 == 1 or totalSum - diff < 0) {
		//totalSum - diff should be even and positive (coz of the fomula for target = (totalSum - diff) / 2)
		return 0;
	}

	int target = (totalSum - diff) / 2;
	return countSubsetsWithSumK(arr, target);
}

int main()
{
	/***************************
	NOTE: we just need to calculate the target(using formula, WV)
	PREREQUISITE: count subsets with sum k(just target has to be calculated every thing else will remain the same)
	VIDEO LINK: https://www.youtube.com/watch?v=zoilQD1kYSg
	QUESTION LINK: https://www.geeksforgeeks.org/count-of-subsets-with-given-difference/#:~:text=Given%20an%20array%20arr%5B%5D,equal%20to%20the%20given%20difference.
	subset/subsequence: 2^n; har element ke pass 2 option hai ya toh subset me aae
	ya na aae
	subarray: N*(N+1)/2; subarray continuous hote hai
	//**************************************************/
	vector<int> arr =  {5, 2, 6, 4};
	int diff = 3;

	cout << "result " << countPartitionsWithGivenDifference(arr, diff);
}