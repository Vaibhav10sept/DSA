#include <bits/stdc++.h>
using namespace std;

int numberOfLongestIncreasingSubsequence(vector<int> arr) {
	//Please watch attached video(link) for more understanding.
	int n = arr.size();
	//edge case
	if (n == 1) return 1; //agr one size ka array h to vo apne app me hi 1 size ka longest increasing subsequence hoga, hence return 1.
	int maxLenghtLongestIncresingSubsequence = 0;
	vector<int> dp(n);
	vector<int> dpCount(n, 1); //why the whole array is initialized as 1(think, cs, dry run)
	dp[0] = 1; //initialization --> means one size ka subarray to apne app me longest inc subsequence hota h(think), islie 1 store krege coz dp me hm lenght store kr rhe h
	//NOTE: an index in dp defines, the lenght of longest inc. subsequence ending at that arr[index].

	for (int i = 1; i < dp.size(); i++) {
		int max = 0;

		//we are finding the max len longest inc subseqence.
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) { //mtlb, inc subseqence bn skta h
				//NOTE: code is slight different then in the code, coz I wrote it myself with few changes
				if (dp[j] == max) {
					dpCount[i] += dpCount[j];
				}
				if (dp[j] > max) {
					max = dp[j];
					dpCount[i] = dpCount[j];
				}
			}
		}
		dp[i] = max + 1; //+1 coz, dp me len store h, to +1 kregena uss element ke lie(WV)

		if (dp[i] > maxLenghtLongestIncresingSubsequence) {
			//logic: is question me dp ke end ya start me answer nhi hoga, coz dp me len store h lon inc subsequence ki to dp me jo sbse jyada value hogi vohi hmara answer hoga.
			maxLenghtLongestIncresingSubsequence = dp[i];
		}
	}
	// cout << "printing" << endl;
	// cout << "dp" << endl;
	// for (int ele : dp) cout << ele << " ";
	// cout << endl;
	// cout << "count dp" << endl;
	// for (int ele : dpCount) cout << ele << " ";
	// cout << endl;

	int countOfLongestIncreasingSubsequence = 0;
	for (int i = 0; i < dp.size(); i++) {
		if (dp[i] == maxLenghtLongestIncresingSubsequence) {
			countOfLongestIncreasingSubsequence += dpCount[i];
		}
	}
	return countOfLongestIncreasingSubsequence;
}

int main()
{
	/***************************
	// LEETCODE: https://leetcode.com/problems/number-of-longest-increasing-subsequence/
	// VIDEO: https://www.youtube.com/watch?v=cKVl1TFdNXg&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=49
	STRONG PREQ: longest increasing subsequence.
	SAME CODE PATTERN AS IN: longest increasing subsequence.
	//**************************************************/
	vector<int> arr = {1, 3, 5, 4, 7};
	// vector<int> arr = {1, 5, 4, 3, 2, 6, 7};
	cout << numberOfLongestIncreasingSubsequence(arr);
}