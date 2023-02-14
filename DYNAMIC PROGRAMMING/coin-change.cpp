#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int> coins, int amount) {
	vector<int> dp(amount + 1, amount + 1); // dp[i] --> represents the min no of coins required to pay using coins in vector "coins" for the amount "dp[i]"
	dp[0] = 0; //initialization --> 0(dp[0]) amount ko pay krne ke lie, min 0 coin required hote h(think)

	//PERMUTAION WAY
	for (int i = 0; i < dp.size(); i++) {
		for (int j = 0; j < coins.size(); j++) {
			if (coins[j] <= i) {
				dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
			}
		}
	}
	return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
	/*********************************
	 * PREREQUISITE: coin change permutations
	 * NOTE: a recursive solution is also there, which will give you TLE.
	VIDEO LINK: https://www.youtube.com/watch?v=H9bfqozjoqs
	LEETCODE LINK: https://leetcode.com/problems/coin-change/
	*********************************/
	vector<int> coins = {1, 2, 5};
	int amount = 11;
	cout << coinChange(coins, amount);

}