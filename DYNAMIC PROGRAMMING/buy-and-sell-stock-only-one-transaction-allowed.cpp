#include <bits/stdc++.h>
using namespace std;

int buyAndSellStockOneTransactionAllowed(vector<int> arr) {
	int leastSoFar = arr[0];
	int maxProfit = INT_MIN;
	for (int i = 1; i < arr.size(); i++) {

		leastSoFar = std::min(leastSoFar, arr[i]);
		maxProfit = std::max(maxProfit, arr[i] - leastSoFar);
	}
	return maxProfit;
}

int main()
{
	//***************************
	// video link: https://www.youtube.com/watch?v=4YjEHmw1MX0&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=515
	// NOTE: this question is part of 6 questions series "buy and sell stock"
	// this is 1rd question in the series
	//**************************************************
	vector<int> stock = {11, 6, 7, 19, 4, 1, 6, 18, 4};
	cout << buyAndSellStockOneTransactionAllowed(stock);

}