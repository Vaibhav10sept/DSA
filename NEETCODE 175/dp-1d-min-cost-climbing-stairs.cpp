#include <bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int> arr) {
	int n = arr.size();
	vector<int> dp(n + 1, 0);

	//travelling from right to left(smaller prob to bigger prob)
	for (int i = n - 1; i >= 0; i--) {

		if (i + 1 < dp.size()) {
			dp[i] = arr[i] + dp[i + 1];
		}
		if (i + 2 < dp.size()) {
			dp[i] = min(arr[i] + dp[i + 2], dp[i]);
		}
	}
	return min(dp[0], dp[1]); //think, WV
}

int main()
{
	//***************************
	//TABULAR MEANS PURE DYNAMIC PROGRAMMING, WHERE THERE IS NO
	//RECURSIVE CALLS THE CODE IS ITERATIVE
	//WHILE IN MEMOIZATION WE HAVE RECURSIVE CALLS
	//********************************
	//********************************
	//STEPS TO SOLVE DP PROBLEMS(TABULATION):
	//1. THINK ABOUT STORAGE AND MEANING
	//2. THINK ABOUT DIRECTION OF THE PROBLEM(FROM SMALLER PROBLEM TO LARGER PROBLEM)
	//3. FINALLY TRAVEL AND SOLVE
	//**************************************************
	vector<int> cost = {10, 15, 20};
	cout << minCostClimbingStairs(cost);
}