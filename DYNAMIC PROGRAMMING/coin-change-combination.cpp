#include <bits/stdc++.h>
using namespace std;

int coinChangeCombination(vector<int> coins, int amount) {
	vector<int> dp(amount + 1, 0);
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
	// video link: https://www.youtube.com/watch?v=l_nR5X9VmaI&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=479
	//**************************************************
	vector<int> coins = {2, 3, 5};
	int amount = 7;

	cout << coinChangeCombination(coins, amount);
}