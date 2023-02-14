#include <bits/stdc++.h>
using namespace std;

int countClimbStairPathsDP(int n) {
	vector<int> dp(n + 1, -1);
	dp[0] = 1; // initialization
	for (int i = 1; i < dp.size(); i++) {
		int ans = 0;
		ans += dp[i - 1];
		if (i - 2 >= 0) {
			ans += dp[i - 2];
		}
		if (i - 3 >= 0) {
			ans += dp[i - 3];
		}
		dp[i] = ans;
	}
	return dp[n];
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
	int n = 5;

	cout << countClimbStairPathsDP(n);
}