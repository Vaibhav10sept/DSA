#include <bits/stdc++.h>
using namespace std;


int longestIncreasingSubsequence(vector<int> arr) {
	//Please watch attached video(link) for more understanding.
	int n = arr.size();
	int maxLenghtLongestIncresingSubsequence = 0;
	vector<int> dp(n);
	dp[0] = 1; //initialization --> means one size ka subarray to apne app me longest inc subsequence hota h(think), islie 1 store krege coz dp me hm lenght store kr rhe h
	//NOTE/STORAGE: an index in dp defines, the lenght of longest inc. subsequence ending at that arr[index].

	for (int i = 1; i < dp.size(); i++) {
		int max = 0;

		//we are finding the max len longest inc subseqence.
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) { //mtlb, inc subseqence bn skta h
				if (dp[j] > max) {
					max = dp[j];
				}
			}
		}
		dp[i] = max + 1; //+1 coz, dp me len store h, to +1 kregena uss element ke lie(WV)
		if (dp[i] > maxLenghtLongestIncresingSubsequence) {
			maxLenghtLongestIncresingSubsequence = dp[i];
		}
	}
	return maxLenghtLongestIncresingSubsequence;
}

int main()
{
	//***************************
	// LEETCODE: https://leetcode.com/problems/longest-increasing-subsequence/
	// video link: https://www.youtube.com/watch?v=odrfUCS9sQk
	//**************************************************
	vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
	// cout << "fsd";
	cout << longestIncreasingSubsequence(arr);
}