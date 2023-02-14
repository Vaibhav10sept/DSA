#include <bits/stdc++.h>
using namespace std;

bool targetSumSubsetDP(vector<int> arr, int target) {
	vector<vector<bool>> dp(arr.size() + 1, vector<bool> (target + 1, false));
	// row --> array ke element hote h, means subsets hote h
	// col --> target hota h
	// dp[i][j] --> store bool value --> if it is possible to create a subset using values till arr[i-1](bcoz array index is one less than the row(i) in dp) and target as j.
	for (int i = 0; i < dp.size() ; i++) { // row --> array ke elements
		for (int j = 0; j < dp[0].size(); j++) {
			//first row and first column means 0 sum and empty subset
			if (i == 0 and j == 0) {
				dp[i][j] = true;
			}
			//first row means no data in the subset(empty subset)
			else if (i == 0) {
				dp[i][j] = false;
			}
			//first column means 0 sum
			else if (j == 0) {
				dp[i][j] = true;
			}
			//for every other cells
			else {
				if (dp[i - 1][j] == true) {
					dp[i][j] = true;
				}
				else { //dp[i-1][j] == false
					int val = arr[i - 1]; // bcoz array index is 1 less than the row no(i). think
					if (val <= j) {
						if (dp[i - 1][j - val]) {
							dp[i][j] = true;
						}
					}
				}
			}
		}
	}
	//returning the last row and column
	return dp[arr.size()][target];
}

int subsetsWithMinAbsoluteDifference(vector<int> arr) {
	//LOGIC: target sum subset ki last row kya define krti h
	//rows --> arr ke elements hote h
	//cols --> target hota h
	//to last row me store hota h ki target from 1 to target using the whole array(last index) possible h ya nhi(boolean)
	// WV highly recommended
	//NOTE: this quesiton is the use case of target sum subsets(dp solution)
	//NOTE: target sum subset me hm target sum of whole arr use krege(think, WV)

	int target = 0;
	for (auto ele : arr) target += ele;

	//***************
	// TARGET SUM SUBSET CODE STARTS
	//******************
	vector<vector<bool>> dp(arr.size() + 1, vector<bool> (target + 1, false));
	// row --> array ke element hote h, means subsets hote h
	// col --> target hota h
	// dp[i][j] --> store bool value --> if it is possible to create a subset using values till arr[i-1](bcoz array index is one less than the row(i) in dp) and target as j.
	for (int i = 0; i < dp.size() ; i++) { // row --> array ke elements
		for (int j = 0; j < dp[0].size(); j++) {
			//first row and first column means 0 sum and empty subset
			if (i == 0 and j == 0) {
				dp[i][j] = true;
			}
			//first row means no data in the subset(empty subset)
			else if (i == 0) {
				dp[i][j] = false;
			}
			//first column means 0 sum
			else if (j == 0) {
				dp[i][j] = true;
			}
			//for every other cells
			else {
				if (dp[i - 1][j] == true) {
					dp[i][j] = true;
				}
				else { //dp[i-1][j] == false
					int val = arr[i - 1]; // bcoz array index is 1 less than the row no(i). think
					if (val <= j) {
						if (dp[i - 1][j - val]) {
							dp[i][j] = true;
						}
					}
				}
			}
		}
	}
	//*********************
	// TARGET SUM SUBSET CODE ENDS
	//************************

	//now, we have the dp
	int minDiff = INT_MAX;
	for (int j = 1, i = arr.size(); j <= target; j++) {
		//last row me tarverse krna h
		if (dp[i][j] == true) { //means, j target ka subset possible h
			int sum1 = j;
			int sum2 = target - j;//think,  logic, wv

			minDiff = min(abs(sum1 - sum2), minDiff);
		}
	}
	return minDiff;
}

int main()
{
	/***************************
	 * STRONG PREREQUISITE: target sum subset --> DP Solution
	video link: https://www.youtube.com/watch?v=GS_OqZb2CWc&t=14s
	subset/subsequence: 2^n; har element ke pass 2 option hai ya toh subset me aae
	QUESTION LINK: https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
	subarray: N*(N+1)/2; subarray continuous hote hai
	//**************************************************/
	vector<int> arr = { 3, 2, 7 };
	//we will get the min diff of sum of two subsets
	cout << subsetsWithMinAbsoluteDifference(arr);
}