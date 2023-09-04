#include <bits/stdc++.h>
using namespace std;

int rec(int i, int j, vector<int> &arr, vector<vector<int>> &memo) {
	if (i == j) { //one size arr 0 multiplication required, hence return 0
		return 0;
	}
	//base case ends

	if (memo[i][j] != -1) return memo[i][j];

	int minCost = 1e9;
	//trying all the partitions
	for (int k = i; k < j; k++) {
		int leftCost = rec(i, k, arr, memo);
		int rightCost = rec(k + 1, j, arr, memo);
		int myMultiplicationCost = arr[i - 1] * arr[k] * arr[j]; //WV recommended
		int totalCost = leftCost + rightCost + myMultiplicationCost;
		minCost = min(minCost, totalCost);
	}

	return memo[i][j] = minCost;
}

int matrixChainMultiplication(vector<int> arr) {
	// WV highly recommended
	int n = arr.size();
	vector<vector<int>> memo(n, vector<int>(n, -1));
	return rec(1, arr.size() - 1, arr, memo);
}

int main()
{
	/***************************
	NOTE: a pepcoding dp solution also there.
	STRONG PREREQUISITE: minimum pallindrome partition or pallindrome partition 2 optimized solution.
	VIDEO: https://www.youtube.com/watch?v=vRVfmbCFW7Y&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=51
	QUESTION: https://www.codingninjas.com/studio/problems/matrix-chain-multiplication_975344?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
	//**************************************************/
	vector<int> arr =  {10, 15, 20, 25};
	cout << matrixChainMultiplication(arr);
}