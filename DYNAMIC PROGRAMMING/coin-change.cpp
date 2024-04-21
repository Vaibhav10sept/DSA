#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int> coins, int amount) {
	vector<int> dp(amount + 1, amount + 1); // dp[i] --> represents the min no of coins required to pay using coins in vector "coins" for the amount "dp[i]"
	dp[0] = 0; //initialization --> 0(dp[0]) amount ko pay krne ke lie, min 0 coin required hote h(think, CS)

	//PERMUTAION WAY
	//NOTE: COMBINATION WAY --> this is giving wrong answer mene check kr liya h--> neeche commented code h dekhlo
	for (int i = 1; i < dp.size(); i++) {
		for (int j = 0; j < coins.size(); j++) {
			if (i - coins[j] >= 0) {
				dp[i] = min(dp[i], 1 + dp[i - coins[j]]); //THINK: +1 kyo kia, kyoki least no of coins toh 1+ means ek or coin use hua
			}
		}
	}
	for (auto ele : dp) {
		cout << ele << " ";
	}
	cout << endl;

	return dp[amount] > amount ? -1 : dp[amount];

	//COMBINATION WAY --> this is giving wrong answer mene check kr liya h
	// for (int i = 0; i < coins.size(); i++) {
	// 	for (int j = coins[i]; j < dp.size(); j++) {
	// 		dp[j] = min(dp[j], dp[j - coins[i]]);
	// 	}
	// }
	// for (auto ele : dp) {
	// 	cout << ele << " ";
	// }
	// cout << endl;

}

int main() {
	/*********************************
	 * PREREQUISITE: coin change permutations
	 * NOTE: a recursive solution is also there, which will give you TLE.
	VIDEO LINK: https://www.youtube.com/watch?v=H9bfqozjoqs
	LEETCODE LINK: https://leetcode.com/problems/coin-change/
	*********************************/
	vector<int> coins = {2};
	int amount = 6;
	cout << "res " << coinChange(coins, amount);

}