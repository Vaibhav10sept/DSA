#include <bits/stdc++.h>
using namespace std;

int buyAndSellStockTwoTransactionsAllowed(vector<int> arr) {
	vector<int> dp(arr.size());

	//left to right traversal
	int maxProfit = 0;
	int leastSoFar = arr[0];
	for (int i = 1; i < dp.size(); i++) {
		leastSoFar = std::min(leastSoFar, arr[i]);
		maxProfit = std::max(maxProfit, arr[i] - leastSoFar);
		dp[i] = maxProfit;
	}

	//right to left traversal
	int largestSoFar = arr[arr.size() - 1];
	maxProfit = 0;
	for (int i = dp.size() - 2; i >= 0; i--) {
		largestSoFar = std::max(largestSoFar, arr[i]);
		maxProfit = std::max(maxProfit, largestSoFar - arr[i]);
		dp[i] += maxProfit;
	}

	return *max_element(dp.begin(), dp.end());
}

int main()
{
	//***************************
	// VIDEO LINK: https://www.youtube.com/watch?v=wuzTpONbd-0&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=519
	// NOTE: this is a hard level ques, watch video and think
	// NOTE: this question is part of 6 questions series "buy and sell stock"
	// this is 5th question in the series
	// similar/prerequisite to "buyAndSellStockOneTransactionAllowed"
	//**************************************************
	// vector<int> stock = {10, 15, 17, 20, 16, 18, 22, 20, 22, 20, 23, 25};
	vector<int> stock =	{11, 6 , 7 , 19 , 4 , 1, 6, 18, 4};
	cout << "answer " << buyAndSellStockTwoTransactionsAllowed(stock);

}