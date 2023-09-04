#include <bits/stdc++.h>
using namespace std;

int partitionArrayForMaxSum(vector<int> arr, int k) { //written by me going through the rec solution
	//PREREQUISITE: this code is derived from striver-rec-partition-array-for-maximum-sum.cpp
	int n = arr.size();
	vector<int> dp(n + 1, 0);

	dp[n] = 0; //initilization

	for (int ind = n - 1; ind >= 0; ind--) {
		int maxNumber = INT_MIN;
		int maxSum = INT_MIN;
		for (int i = 0; i < k; i++) {
			if (ind + i < n) {
				maxNumber = max(maxNumber, arr[ind + i]);
				int currMaxSum = maxNumber * (i + 1);
				maxSum = max(maxSum, currMaxSum + dp[ind + i + 1]);
			}
		}
		dp[ind] = maxSum;
	}

	return dp[0];
}

int main()
{
	/***************************
	 * PREREQUISITE: this code is derived from striver-rec-partition-array-for-maximum-sum.cpp
	 * NOTE: written by me going through the rec solution
	 * SIMILAR CODE PATTERN: striver-rec-minimum-pallindromic-cuts-or-pallindrome-partitioning-2
	video link: https://www.youtube.com/watch?v=PhWWJmaKfMc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=55
	LEETCODE LINK: https://leetcode.com/problems/partition-array-for-maximum-sum/
	//**************************************************/
	vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
	int k = 3;
	cout << partitionArrayForMaxSum(arr, k);
}