#include <bits/stdc++.h>
using namespace std;

int buyAndSellStockWithCoolDownInfiniteTransactionAllowed(vector<int> arr) {
	int bsp = -1 * arr[0]; // bought state profit
	int ssp = 0; // sold state profit
	int csp = 0; //cool down state profit

	for (int i = 1; i < arr.size(); i++) {
		int obsp = bsp; // old bought state profit
		bsp = std::max(bsp, csp - arr[i]);
		int ossp = ssp;
		ssp = std::max(ssp, obsp + arr[i]);
		csp = std::max(csp, ossp);
	}

	return ssp;
}

int main()
{
	//***************************
	// VIDEO LINK: https://www.youtube.com/watch?v=GY0O57llkKQ&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=518
	// NOTE: this question is part of 6 questions series "buy and sell stock"
	// this is 4rd question in the series
	// NOTE: similar/extention of "buyAndSellStockWithTransactionFeeAndInfiniteTransactionAllowed"
	//**************************************************
	vector<int> stock = {10, 15, 17, 20, 16, 18, 22, 20, 22, 20, 23, 25};
	cout << buyAndSellStockWithCoolDownInfiniteTransactionAllowed(stock);

}