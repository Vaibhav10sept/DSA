#include <bits/stdc++.h>
using namespace std;

int buyAndSellStockKTransactionAllowed(vector<int> arr, int k) {
	// nice question, WV
	//* NOTE: the code is derived from the rec striver code please see the rec code and then derive the dp code from it.
	//3D vector(WV)
	int n = arr.size();
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

	for (int ind = n - 1; ind >= 0; ind--) {
		for (int buy = 0; buy <= 1; buy++) {
			for (int transaction = 1; transaction <= k; transaction++) {
				// copy the recursive code
				if (buy) { //you can buy not sell
					//there can be two case: buy and not buy
					int ProfitBuy = -1 * arr[ind] + dp[ind + 1][0][transaction];
					int ProfitNotBuy = 0 + dp[ind + 1][1][transaction];
					dp[ind][buy][transaction]  = max(ProfitNotBuy, ProfitBuy);
				}
				else { //you cannot buy only sell
					//there can be two case: sell and not sell
					//crucial and tricky part, sell krne pr hi ek transaction complete hoti h tbhi sell hone pr hi transaction -1 kia h
					int profitSell = arr[ind] + dp[ind + 1][1][transaction - 1];
					int profitNotSell = 0 + dp[ind + 1][0][transaction];
					dp[ind][buy][transaction]  = max(profitNotSell, profitSell);
				}
			}
		}
	}

	return dp[0][1][k];
}

int main()
{
	/***************************
	 * SAME CODE AS IN: dp-striver-buy-and-sell-stock-two-transaction-allowed
	 * STRONG PREQ: dp-striver-buy-and-sell-stock-two-transaction-allowed
	 * NOTE: the code is derived from the rec striver code please see the rec code and then derive the dp code from it.
	 * LEETCODE: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/submissions/
	// video link: youtube.com/watch?v=IV1dHbk5CDc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=39https://www.youtube.com/watch?v=-uQGzhYj8BQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=38
	NOTE: this is striver dp solution, dp pepcoding solution is also there
	//**************************************************/
	int k = 2;
	vector<int> prices = {2, 4, 1};
	cout << buyAndSellStockKTransactionAllowed(prices, k);

}