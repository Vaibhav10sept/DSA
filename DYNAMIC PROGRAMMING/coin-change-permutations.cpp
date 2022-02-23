#include <bits/stdc++.h>
using namespace std;

int coinChangePermutations(vector<int> coins, int amount) {
	vector<int> dp(amount + 1, 0);
	dp[0] = 1; //initialization --> ek combination hai 0 amount ke lie ki kuch na do

	for (int amt = 1; amt <= amount ; amt++) {
		for (int coin : coins) {
			if ((amt - coin) >= 0) {
				dp[amt] += dp[amt - coin];
			}
		}
	}

	return dp[amount];
}

int main()
{
	//***************************
	// video link: https://www.youtube.com/watch?v=yc0LunmJA1A&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=480
	//**************************************************
	vector<int> coins = {2, 3, 5, 6};
	int amount = 10;

	cout << coinChangePermutations(coins, amount);
}