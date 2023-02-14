#include <bits/stdc++.h>
using namespace std;

void displayMatrix(vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int buyAndSellStockKTransactionsAllowed(vector<int> arr, int k) {
	vector<vector<int>> dp(k + 1, vector<int>(arr.size()));
	// row -> no of transactions(k)
	// col -> no of days
	// cell -> max profit you can make with ith transaction and jth day

	for (int i = 0; i < dp.size(); i++) {
		for (int j = 0; j < dp[0].size(); j++) {
			if (i == 0 || j == 0) { //initialization(this is the step of solving DP questions)
				dp[i][j] = 0;
			}
			else {
				dp[i][j] = dp[i][j - 1]; //dp[i][j-1] --> one day before, same no of transaction
				int currPrice = arr[j];
				int maxResult = INT_MIN; //for i-1(means transaction - 1) candidates
				for (int k = j - 1; k >= 0; k--) {
					maxResult = std::max(maxResult, dp[i - 1][k] + currPrice - arr[k]);
				}
				dp[i][j] = std::max(dp[i][j], maxResult);
			}
		}
	}
	displayMatrix(dp);
	return dp[k][arr.size() - 1];
}

int main()
{
	//***************************
	// VIDEO LINK: https://www.youtube.com/watch?v=3YILP-PdEJA&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=520
	// NOTE: this has n^3 complexity other optimized solution has n^2 complexity
	// NOTE: this is a hard level ques, watch video and think
	// NOTE: this question is part of 6 questions series "buy and sell stock"
	// this is 6th question in the series
	// approach to solve this question is similar to "knapsack"
	//**************************************************
	// vector<int> stock = {10, 15, 17, 20, 16, 18, 22, 20, 22, 20, 23, 25};
	vector<int> stock =	{9, 6, 7, 6, 3, 8};
	int k = 3; //no of transactions
	cout << "answer " << buyAndSellStockKTransactionsAllowed(stock, k);
}