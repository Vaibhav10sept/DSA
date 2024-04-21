#include <bits/stdc++.h>
using namespace std;

int rec(int ind, bool buy, vector<int> arr, int transaction, vector<vector<vector<int>>> &memo) {
	if (transaction == 0) return 0; // 2 transaction allowed thi to agr transaction khtm ho gae to 0 profit return kr do
	if (ind == arr.size()) return 0; //profit 0 hoga think

	if (memo[ind][buy][transaction] != -1)return memo[ind][buy][transaction];

	//WV recommended
	if (buy) { //you can buy not sell
		//there can be two case: buy and not buy
		int ProfitBuy = -1 * arr[ind] + rec(ind + 1, false, arr, transaction, memo);
		int ProfitNotBuy = 0 + rec(ind + 1, true, arr, transaction, memo);
		return memo[ind][buy][transaction]  = max(ProfitNotBuy, ProfitBuy);
	}
	else { //you cannot buy only sell
		//there can be two case: sell and not sell
		//crucial and tricky part, sell krne pr hi ek transaction complete hoti h tbhi sell hone pr hi transaction -1 kia h
		int profitSell = arr[ind] + rec(ind + 1, true, arr, transaction - 1, memo);
		int profitNotSell = 0 + rec(ind + 1, false, arr, transaction, memo);
		return memo[ind][buy][transaction]  = max(profitNotSell, profitSell);
	}
}

int buyAndSellStockTwoTransactionAllowed(vector<int> arr) {
	// nice question, WV
	//3D vector(WV)
	vector<vector<vector<int>>> memo(arr.size(), vector<vector<int>>(2, vector<int>(3, -1)));
	return rec(0, true, arr, 2, memo);
}

int main()
{
	/***************************
	 * NOTE: not submit on leetcode, submit DP solution
	 * LEETCODE: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
	// video link: https://www.youtube.com/watch?v=-uQGzhYj8BQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=38
	NOTE: this is striver rec solution, dp pepcoding solution is also there
	// NOTE: this question is part of 6 questions series "buy and sell stock"
	// this is 2rd question in the series
	//**************************************************/
	vector<int> stock = {3, 3, 5, 0, 0, 3, 1, 4};
	cout << buyAndSellStockTwoTransactionAllowed(stock);

}