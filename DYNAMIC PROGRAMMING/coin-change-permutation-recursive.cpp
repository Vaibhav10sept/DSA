#include <bits/stdc++.h>
using namespace std;

void coinChangeCombination(vector<int> coins, int amount, vector<int> ans) {
	if (amount == 0) {
		for (auto ele : ans) cout << ele << " ";
		cout << endl;
		return;
	}
	else if (amount < 0) return;

	for (auto coin : coins) {
		ans.push_back(coin);
		coinChangeCombination(coins, amount - coin, ans);
		//backtrack
		ans.pop_back();
	}
}

int main()
{
	//***************************
	// this recursive solution will print all the premutation
	// the corresponding DP solution will count the no of permutations.
	//**************************************************
	vector<int> coins = {1, 3, 4, 5};
	int amount = 7;
	vector<int> ans;
	coinChangeCombination(coins, amount, ans);
}