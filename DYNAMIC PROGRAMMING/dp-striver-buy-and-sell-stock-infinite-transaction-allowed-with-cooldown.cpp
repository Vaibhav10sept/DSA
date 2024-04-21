#include <bits/stdc++.h>
using namespace std;

int buyAndSellStockInfiniteTransactionAllowedWithCooldown(vector<int> arr) {
	// nice question, WV
	int n = arr.size();
	vector<vector<int>> dp(n + 2, vector<int>(2, 0)); //n+2 coz neeche dekho hm ind + 2 kr rhe so for that to be valid n+2 size ka bnaya h, think, WV
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
				int profitSell = arr[ind] + dp[ind + 2][1]; //NOTE: ind + 2, coz of cooldown(WV)
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
	 * STRONG PREQ: dp-striver-buy-and-sell-stock-infinite-transaction-allowed
	 * SAME CODE SLIGHT CHANGE: dp-striver-buy-and-sell-stock-infinite-transaction-allowed
	 * NOTE: this is derived from the rec striver solution, you must go through the rec code to understand this one.
	// video link: https://www.youtube.com/watch?v=IGIe46xw3YY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=40
	QUESTION: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
	NOTE: this is striver dp solution, dp pepcoding solution is also there
	//**************************************************/
	// vector<int> stock = {11, 6, 7, 19, 4, 1, 6, 18, 4};
	vector<int> stock = {1, 2, 3, 0, 2};
	cout << buyAndSellStockInfiniteTransactionAllowedWithCooldown(stock);

}