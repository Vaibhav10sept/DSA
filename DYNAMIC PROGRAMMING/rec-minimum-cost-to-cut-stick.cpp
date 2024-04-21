#include <bits/stdc++.h>
using namespace std;

int rec(int left, int right, vector<int> cuts, vector<vector<int>> &memo) {
	//WV
	if (right - left == 1) {
		return 0; //one size ki stick h to cut nhi kr skte to return 0(cost to cut the stick)
	}
	//base case ends

	if (memo[left][right] != -1) return memo[left][right];

	int minCost = INT_MAX;
	for (int cut : cuts) {
		if (cut > left and cut < right) { //for a cut to be valid it should in range of left and right.
			int currentCost = right - left;
			int leftSideCost = rec(left, cut, cuts, memo);
			int rightSideCost = rec(cut, right, cuts, memo);
			minCost = min(minCost, currentCost + leftSideCost + rightSideCost);
		}
	}

	if (minCost == INT_MAX) {
		return memo[left][right] = 0; //edge case, agr koi bhi cut valid ni hua, "if (cut > left and cut < right)" ye if true ni hua to minCost INTMAX hi rhegi in that case return 0;
	}

	return memo[left][right] = minCost;
}

int minCostToCutStick(vector<int> cuts, int n) {
	vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
	return rec(0, n, cuts, memo);
}

int main()
{
	/***************************
	* NOTE: give TLE on leetcode
	VIDEO: https://www.youtube.com/watch?v=EVxTO5I0d7w
	QUESTION: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
	//**************************************************/
	int n = 3500;
	vector<int> cuts = {448, 3234, 82, 3448, 491, 2244, 1939, 1440, 2484, 2516, 3133, 2089, 3405, 882};
	cout << minCostToCutStick(cuts, n);
}