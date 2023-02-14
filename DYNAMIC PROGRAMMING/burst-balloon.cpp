#include <bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(vector<int> arr) {
	// WV highly recommended

	//NOTE: arr ke size ke ek choti size ka dp 2d-array bnega(think, WV)
	vector<vector<int>> dp(arr.size() - 1, vector<int>(arr.size() - 1));
	int n = dp.size();
	int m = dp[0].size();
	//STORAGE: dp[i][j] stores the min no of multiplication required to multiply the matrixes from ith index to jth index.(NOTE: array me matrix ke size kaese store h ye dekhna(array ka size n h to usme n-1 matrix ke dimension store h(WV)))

	//gap strategy --> this will traverse the upper triangle matrix, diagonally(wv)
	for (int gap = 0; gap < n; gap++) {
		for (int i = 0, j = gap; i < n and j < m; i++, j++) {
			if (gap == 0) { //single matrix h, to multiplication to hoga nhi, islie 0 likho
				dp[i][j] = 0;
			}
			else if (gap == 1) { //do matrix ka multiplication hoga, simple h(WV)
				dp[i][j] = arr[i] * arr[j] * arr[j + 1]; // WV
				//NOTE: j+1 kbhi out of bound nhi jaegi, kyoki dp ka size arr se ek kam h(WV)
			}
			else {
				// crucial part --> this for loop is similar to minimum pallindrome partition or pallindrome partition 2 optimized solution
				int minCostOfMultiplication = INT_MAX;
				for (int k = i; k < j; k++) {
					// i to k is left half and k+1 to j is right half(wv)
					int leftCost = dp[i][k];
					int rightCost = dp[k + 1][j];
					int multipliationCost = arr[i] * arr[k + 1] * arr[j + 1];
					int totalCost = leftCost + rightCost + multipliationCost;
					minCostOfMultiplication = min(minCostOfMultiplication, totalCost);
				}
				dp[i][j] = minCostOfMultiplication;
			}
		}
	}

	return dp[0][arr.size() - 2]; //dp ke top right me ans hoga(wv)
}

int main()
{
	/***************************
	NOTE: gap strategy is used here.
	STRONG PREREQUISITE: minimum pallindrome partition or pallindrome partition 2 optimized solution.
	video link: https://www.youtube.com/watch?v=pEYwLmGJcvs
	LEETCODE LINK: https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
	//**************************************************/
	vector<int> arr =  {40, 20, 30, 10, 30};
	cout << matrixChainMultiplication(arr);
}