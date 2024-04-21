#include <bits/stdc++.h>
using namespace std;

int rec(int ind, bool buy, vector<int> arr, int fee, vector<vector<long>> &memo) {
	if (ind == arr.size()) return 0; //profit 0 hoga think

	if (memo[ind][buy] != -1)return memo[ind][buy];

	//WV recommended
	if (buy) { //you can buy not sell
		//there can be two case: buy and not buy
		int ProfitBuy = -1 * arr[ind] + rec(ind + 1, false, arr, fee, memo);
		int ProfitNotBuy = 0 + rec(ind + 1, true, arr, fee, memo);
		return memo[ind][buy] = max(ProfitNotBuy, ProfitBuy);
	}
	else { //you cannot buy only sell
		//there can be two case: sell and not sell
		//NOTE: only difference, sell krne pr transaction fee minus hogi(think,WV)
		int profitSell = arr[ind] - fee + rec(ind + 1, true, arr, fee, memo);
		int profitNotSell = 0 + rec(ind + 1, false, arr, fee, memo);
		return memo[ind][buy] = max(profitNotSell, profitSell);
	}
}

int buyAndSellStockInfiniteTransactionAllowedWithTransactionFee(vector<int> arr, int fee) {
	// nice question, WV
	vector<vector<long>> memo(arr.size(), vector<long>(2, -1));
	return rec(0, true, arr, fee, memo);
}

int main()
{
	/***************************
	 * NOTE: not submit on leetcode, try dp solution
	 * STRONG PREQ: rec-striver-buy-and-sell-stock-infinite-transaction-allowed
	 * SAME CODE WITH SLIGHT CHANGE: rec-striver-buy-and-sell-stock-infinite-transaction-allowed
	// video Link: https://www.youtube.com/watch?v=k4eK-vEmnKg&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=41
	QUESTION: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
	NOTE: this is striver rec solution, dp pepcoding solution is also there
	//**************************************************/
	// vector<int> stock = {11, 6, 7, 19, 4, 1, 6, 18, 4};
	vector<int> stock = {1, 3, 2, 8, 4, 9};
	int fee = 2;
	cout << buyAndSellStockInfiniteTransactionAllowedWithTransactionFee(stock, fee);

}