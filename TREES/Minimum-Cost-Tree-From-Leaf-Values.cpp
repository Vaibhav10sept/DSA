#include <bits/stdc++.h>
using namespace std;

int solveRecursive(int left, int right, vector<int> &arr, map<pair<int, int>, int> &maxValue, vector<vector<int>> &memo) {
	if (left == right) { //leaf node, directly returns
		return 0;
	}
	//BC ends

	if (memo[left][right] != -1) return memo[left][right];

	//divide the arr using left and right and make recursive calls
	int ans = INT_MAX;
	for (int i = left; i < right; i++) {
		ans = min(ans, maxValue[ {left, i}] * maxValue[ {i + 1, right}]
		          + solveRecursive(left, i, arr, maxValue, memo) + solveRecursive(i + 1, right, arr, maxValue, memo));
	}
	return memo[left][right] = ans;
}

int minCostTree(vector<int> arr) {
	//wv recommended
	//precomputation
	int n = arr.size();
	map<pair<int, int>, int> maxValue; //pair --> range(i,j) vs max value
	//maxValue will store, for range i to j iss range me max value kya h
	for (int i = 0; i < n; i++) {
		maxValue[ {i, i}] = arr[i];
		for (int j = i + 1; j < n; j++) {
			maxValue[ {i, j}] = max(arr[j], maxValue[ {i, j - 1}]);
		}
	}


	//main solve vala recursive function with memoization(wv, think, logic)
	vector<vector<int>> memo(n, vector<int>(n, -1));
	return solveRecursive(0, n - 1, arr, maxValue, memo);
}

int main()
{
	/*
	NOTE: this is recursion with memoization
	VIDEO: https://www.youtube.com/watch?v=LDiD9fr28tc
	LEETCODE: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
	*/
	vector<int> arr = {6, 2, 4};

	cout << minCostTree(arr);
}
