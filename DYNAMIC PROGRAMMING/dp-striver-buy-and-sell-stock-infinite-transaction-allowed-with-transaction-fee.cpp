#include <bits/stdc++.h>
using namespace std;

int buyAndSellStockInfiniteTransactionAllowedWithTransactionFee(vector<int> arr, int fee) {
	// nice question, WV
	int n = arr.size();
	vector<vector<int>> dp(n + 1, vector<int>(2, 0));
	//changing parameters are ind and buy(true or false) hence the dp size.
	//* NOTE: this is derived from the rec striver solution, you must go through the rec code to understand this one.


	//initialization
	dp[n][0] = dp[n][1] = 0; //base case 'n' me profit zero hoga, see the recursive function

	for (int ind = n - 1; ind >= 0; ind--) {
		for (int buy = 0; buy <= 1; buy++) { //can run from 1 to 0 doesn't matter
			//copy the recursive code
			//WV recommended
			if (buy) { //you can buy not sell
				//there can be two case: buy and not buy
				int ProfitBuy = -1 * arr[ind] + dp[ind + 1][0];
				int ProfitNotBuy = 0 + dp[ind + 1][1];
				dp[ind][buy] = max(ProfitNotBuy, ProfitBuy);
			}
			else { //you cannot buy only sell
				//there can be two case: sell and not sell
				//NOTE: only difference, sell krne pr transaction fee minus hogi(think,WV)
				int profitSell = arr[ind] - fee + dp[ind + 1][1];
				int profitNotSell = 0 + dp[ind + 1][0];
				dp[ind][buy] = max(profitNotSell, profitSell);
			}
		}
	}
	return dp[0][1]; //1 coz buy vala case, think first stock ko buy kr skte hai, rec ko call krte time bhi first call me buy ko true paas kia tha tbhi '1' me answer hoga.
}

int main()
{
	/***************************
	 * NOTE: this is derived from the rec striver solution, you must go through the rec code to understand this one.
	* STRONG PREQ: dp-striver-buy-and-sell-stock-infinite-transaction-allowed
	 * SAME CODE WITH SLIGHT CHANGE: dp-striver-buy-and-sell-stock-infinite-transaction-allowed
	// video Link: https://www.youtube.com/watch?v=k4eK-vEmnKg&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=41
	QUESTION: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
	NOTE: this is striver dp solution, dp pepcoding solution is also there
	//**************************************************/
	vector<int> stock = {1, 3, 2, 8, 4, 9};
	int fee = 2;
	cout << buyAndSellStockInfiniteTransactionAllowedWithTransactionFee(stock, fee);

}