#include <bits/stdc++.h>
using namespace std;

int printLongestIncreasingSubsequence(vector<int> arr) {
	//Please watch attached video(link) for more understanding.
	int n = arr.size();
	int maxLenghtLongestIncresingSubsequence = 0;
	vector<int> hash(n);
	for (int i = 0; i < hash.size(); i++) hash[i] = i;
	vector<int> dp(n);
	dp[0] = 1; //initialization --> means one size ka subarray to apne app me longest inc subsequence hota h(think), islie 1 store krege coz dp me hm lenght store kr rhe h
	//NOTE: an index in dp defines, the lenght of longest inc. subsequence ending at that arr[index].
	int lastIndex = 0; //for print the longest incrasing subsequence

	for (int i = 1; i < dp.size(); i++) {
		int max = 0;

		//we are finding the max len longest inc subseqence.
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) { //mtlb, inc subseqence bn skta h
				if (dp[j] > max) {
					max = dp[j];
					hash[i] = j;
				}
			}
		}
		dp[i] = max + 1; //+1 coz, dp me len store h, to +1 kregena uss element ke lie(WV)

		if (dp[i] > maxLenghtLongestIncresingSubsequence) {
			//logic: is question me dp ke end ya start me answer nhi hoga, coz dp me len store h lon inc subsequence ki to dp me jo sbse jyada value hogi vohi hmara answer hoga.
			maxLenghtLongestIncresingSubsequence = dp[i];
			lastIndex = i; //for print the longest incrasing subsequence
		}
	}

	//for printing the longest increasing subsequence
	vector<int> printing;
	printing.push_back(arr[lastIndex]);
	while (lastIndex != hash[lastIndex]) {
		lastIndex = hash[lastIndex];
		printing.push_back(arr[lastIndex]);
	}
	reverse(printing.begin(), printing.end());
	cout << "printing the longest increasing subsequence:" << endl;
	for (auto ele : printing) cout << ele << ", ";
	cout << endl;

	return maxLenghtLongestIncresingSubsequence;
}

int main()
{
	/***************************
	 * STRONG PREQ: longest increasing subsequence.
	 * WV highly recommended
	NOTE: this question is not there in leetcode similar is there in below link
	// LEETCODE: https://leetcode.com/problems/longest-increasing-subsequence/
	// video link: https://www.youtube.com/watch?v=IFfYfonAFGc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=43
	//**************************************************/
	vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
	int ans = printLongestIncreasingSubsequence(arr);
	cout << "printing the length longest increasing subsequence: " << ans << endl;
}