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
int rob(vector<int>& arr) {
	vector<int> dp(arr.size(), -1);
	return maxSumNonAdjacentElementRecursionMemoized(arr, 0, dp);
}

int main()
{
	/***************************
	PREREQUISITE: maximum sum non adjacent element.
	NOTE: a dp solution is also there
	NOTE: we can use the same code as in max sum non adjacent element.
	video link: https://www.youtube.com/watch?v=VT4bZV24QNo&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=494
	//********************************
	//********************************
	//STEPS TO SOLVE DP PROBLEMS(TABULATION):
	//1. THINK ABOUT STORAGE AND MEANING
	//2. THINK ABOUT DIRECTION OF THE PROBLEM(FROM SMALLER PROBLEM TO LARGER PROBLEM)
	//3. FINALLY TRAVEL AND SOLVE
	//**********************************************/
	vector<int> cost = {2, 1, 1, 2};
	cout << houseRobber(cost);
}