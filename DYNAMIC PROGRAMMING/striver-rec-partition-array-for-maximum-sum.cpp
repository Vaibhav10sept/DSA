#include <bits/stdc++.h>
using namespace std;

int rec(int ind, vector<int> arr, int k, vector<int> &memo) {
	if (ind == arr.size()) return 0;

	if (memo[ind] != -1) return memo[ind];

	int maxNumber = INT_MIN;
	int maxSum = INT_MIN;
	for (int i = 0; i < k; i++) {
		if (ind + i < arr.size()) {
			maxNumber = max(maxNumber, arr[ind + i]);
			int currMaxSum = maxNumber * (i + 1);
			maxSum = max(maxSum, currMaxSum + rec(ind + i + 1, arr, k, memo));
		}
	}
	return memo[ind] = maxSum;
}

int partitionArrayForMaxSum(vector<int> arr, int k) { //written by me after wv
	vector<int> memo(arr.size(), -1);
	return rec(0, arr, k, memo);
}

int main()
{
	/***************************
	 * NOTE: written by me after wv, gives TLE on leetcode, dp solution(derived from this) also there.
	 * SIMILAR CODE PATTERN: striver-rec-minimum-pallindromic-cuts-or-pallindrome-partitioning-2
	STRONG PREREQUISITE: striver-rec-minimum-pallindromic-cuts-or-pallindrome-partitioning-2
	video link: https://www.youtube.com/watch?v=PhWWJmaKfMc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=55
	LEETCODE LINK: https://leetcode.com/problems/partition-array-for-maximum-sum/
	//**************************************************/
	vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
	int k = 3;
	cout << partitionArrayForMaxSum(arr, k);
}