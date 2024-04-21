#include <bits/stdc++.h>
using namespace std;

int rec(int ind, bool buy, vector<int> arr, vector<vector<long>> &memo) {
	if (ind == arr.size()) return 0; //profit 0 hoga think

	if (memo[ind][buy] != -1)return memo[ind][buy];

	//WV recommended
	if (buy) { //you can buy not sell
		//there can be two case: buy and not buy
		int ProfitBuy = -1 * arr[ind] + rec(ind + 1, false, arr, memo);
		int ProfitNotBuy = 0 + rec(ind + 1, true, arr, memo);
		return memo[ind][buy] = max(ProfitNotBuy, ProfitBuy);
	}
	else { //you cannot buy only sell
		//there can be two case: sell and not sell
		int profitSell = arr[ind] + rec(ind + 1, true, arr, memo);
		int profitNotSell = 0 + rec(ind + 1, false, arr, memo);
		return memo[ind][buy] = max(profitNotSell, profitSell);
	}
}

int buyAndSellStockInfiniteTransactionAllowed(vector<int> arr) {
	// nice question, WV
	vector<vector<long>> memo(arr.size(), vector<long>(2, -1));
	return rec(0, true, arr, memo);
}

int main()
{
	/***************************
	 * NOTE: not submit on leetcode, submit DP solution
	// video link: https://www.youtube.com/watch?v=nGJmxkUJQGs&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=37
	NOTE: this is striver rec solution, one dp pepcoding solution is also there
	// NOTE: this question is part of 6 questions series "buy and sell stock"
	// this is 2rd question in the series
	//**************************************************/
	// vector<int> stock = {11, 6, 7, 19, 4, 1, 6, 18, 4};
	vector<int> stock = {7, 1, 5, 3, 6, 4};
	cout << buyAndSellStockInfiniteTransactionAllowed(stock);

}