#include <bits/stdc++.h>
using namespace std;

int buyAndSellStockTwoTransactionAllowed(vector<int> arr) {
	// nice question, WV
	//* NOTE: the code is derived from the rec striver code please see the rec code and then derive the dp code from it.
	//3D vector(WV)
	int n = arr.size();
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

	for (int ind = n - 1; ind >= 0; ind--) {
		for (int buy = 0; buy <= 1; buy++) {
			for (int transaction = 1; transaction <= 2; transaction++) {
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

	return dp[0][1][2];
}

int main()
{
	/***************************
	 * NOTE: the code is derived from the rec striver code please see the rec code and then derive the dp code from it.
	 * LEETCODE: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
	// video link: https://www.youtube.com/watch?v=-uQGzhYj8BQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=38
	NOTE: this is striver dp solution, dp pepcoding solution is also there
	// NOTE: this question is part of 6 questions series "buy and sell stock"
	// this is 2rd question in the series
	//**************************************************/
	vector<int> stock = {3, 3, 5, 0, 0, 3, 1, 4};
	cout << buyAndSellStockTwoTransactionAllowed(stock);

}