#include <bits/stdc++.h>
using namespace std;

int coinChangeCombination(vector<int> coins, int amount) {
	vector<int> dp(amount + 1, 0); // dp[i] --> represents the no of possible combinations to pay using coins in vector coins for a amount dp[i]
	dp[0] = 1; //initialization --> ek combination hai 0 amount ke lie ki kuch na do

	for (int i = 0; i < coins.size(); i++) {
		for (int j = coins[i]; j < dp.size(); j++) {
			dp[j] += dp[j - coins[i]];
		}
	}

	return dp[amount];
}

int main()
{
	//***************************
	// NOTE: there is a backtracking problem "combiantion sum" which prints the combination
	//       you can search it using ctrl + p.
	//       this DP problem will give you the no of ways
	//       the backtracking prob will print all those ways.
	// video link: https://www.youtube.com/watch?v=l_nR5X9VmaI&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=479
	//**************************************************
	vector<int> coins = {1, 2, 5};
	int amount = 5;

	cout << coinChangeCombination(coins, amount);
}