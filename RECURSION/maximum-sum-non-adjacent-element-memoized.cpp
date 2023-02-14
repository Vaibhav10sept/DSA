#include <bits/stdc++.h>
using namespace std;

int maxSumNonAdjacentElementRecursionMemoized(vector<int> arr, int idx, vector<int> &dp) {
	if (idx >= arr.size()) {
		return 0;
	}
	if (dp[idx] != -1) {
		return dp[idx];
	}
	int pick = arr[idx] + maxSumNonAdjacentElementRecursionMemoized(arr, idx + 2, dp);
	int notPick = 0 + maxSumNonAdjacentElementRecursionMemoized(arr, idx + 1, dp);

	dp[idx] = max(pick, notPick);
	return dp[idx];
}

int maxSumNonAdjacentElement(vector<int> arr) {
	vector<int> dp(arr.size(), -1);
	return maxSumNonAdjacentElementRecursionMemoized(arr, 0, dp);
}

int main()
{
	/*
	VIDEO LINK: https://www.youtube.com/watch?v=GrMBfJNk_NY
	SIMILAR PROB: house robber
	NOTE: house robber is the use case of this question.
	*/
	vector<int> arr = {3, 2, 5, 10, 7};
	cout << maxSumNonAdjacentElement(arr);
}