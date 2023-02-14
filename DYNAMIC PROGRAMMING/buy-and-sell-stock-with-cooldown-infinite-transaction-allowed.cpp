#include <bits/stdc++.h>
using namespace std;

int buyAndSellStockWithCoolDownInfiniteTransactionAllowed(vector<int> arr) {
	int bsp = -1 * arr[0]; // bought state profit --> isme ek extra share hona chahiye --> means no of bought is one more than no of sold
	int ssp = 0; // sold state profit --> isme extra share nhi hoga
	int csp = 0; //cool down state profit

	for (int i = 1; i < arr.size(); i++) {
		int obsp = bsp; // old bought state profit
		bsp = std::max(bsp, csp - arr[i]); //bought ham cool down pe krte hai
		int ossp = ssp; // old sold state profit
		ssp = std::max(ssp, obsp + arr[i]); // sell ham bought state pe krte hai
		csp = std::max(csp, ossp); // cool down sell ke baat hota h.
	}
	return ssp;
}

int main()
{
	//***************************
	// VIDEO LINK: https://www.youtube.com/watch?v=GY0O57llkKQ&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=518
	// PREREQUISITE: buy and sell stocks with transaction fee and infinite transactions
	// NOTE: this question is part of 6 questions series "buy and sell stock"
	// this is 4rd question in the series
	// NOTE: similar/extention of "buyAndSellStockWithTransactionFeeAndInfiniteTransactionAllowed"
	//**************************************************
	vector<int> stock = {10, 15, 17, 20, 16, 18, 22, 20, 22, 20, 23, 25};
	cout << buyAndSellStockWithCoolDownInfiniteTransactionAllowed(stock);

}