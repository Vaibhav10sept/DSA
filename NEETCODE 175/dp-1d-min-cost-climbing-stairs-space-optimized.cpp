#include <bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int> arr) {
	//this is the space optimized code, here we are not creating a seperate array(dp) for storage
	// SPACE --> constant
	// WV recommended
	arr.push_back(0);

	//right to left
	for (int i = arr.size() - 3; i >= 0; i--) {
		arr[i] = min(arr[i] + arr[i + 1], arr[i] + arr[i + 2]);
	}

	return min(arr[0], arr[1]);
}

int main()
{
	//***************************
	// VIDEO: https://www.youtube.com/watch?v=ktmzAZWkEZ0
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