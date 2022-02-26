#include <bits/stdc++.h>
using namespace std;

int buyAndSellStockWithTransactionFeeAndInfiniteTransactionAllowed(vector<int> arr, int fee) {
	int bsp = -1 * arr[0]; // bought state profit
	int ssp = 0; // sold state profit

	for (int i = 1; i < arr.size(); i++) {
		int temp = bsp;
		bsp = std::max(bsp, ssp - arr[i]);
		ssp = std::max(ssp, temp + arr[i] - fee);
	}

	return ssp;
}

int main()
{
	//***************************
	// VIDEO LINK: https://www.youtube.com/watch?v=pTQB9wbIpfU&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=517
	// NOTE: this question is part of 6 questions series "buy and sell stock"
	// this is 3rd question in the series
	// NOTE: similar to "include exclude" format of ques in DP
	//**************************************************
	vector<int> stock = {10, 15, 17, 20, 16, 18, 22, 20, 22, 20, 23, 25};
	int fee = 3;
	cout << buyAndSellStockWithTransactionFeeAndInfiniteTransactionAllowed(stock, fee);

}