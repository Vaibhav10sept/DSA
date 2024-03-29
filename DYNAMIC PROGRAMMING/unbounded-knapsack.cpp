#include <bits/stdc++.h>
using namespace std;

void displayMatrix(vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int unboundedZeroOneKnapsack(vector<int> value, vector<int> weight, int capacity) {
	vector<int> dp(capacity + 1);
	// STORAGE: dp[i] stores the max profit if the capacity of the bag is i.

	dp[0] = 0; // initialization --> 0 size ke bag me profit 0 hi hoga
	for (int i = 0; i < weight.size(); i++) {
		for (int j = weight[i]; j <= capacity; j++) {
			dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);
		}
	}
	return dp[capacity];
}

int main()
{
	//***************************
	// PREREQUISITE: coin change combination
	// video link: https://www.youtube.com/watch?v=jgps7MXtKRQ&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=483
	// similar to "COIN CHANGE COMBINATION" because we need duplicacy here(unbounded knapsack)
	// NOTE: its doesn't matter ki ham "COIN CHANGE COMBINATION" use kr rhe
	// ya "COIN CHANGE PERMUTATIONS" both will give the same answer(think)
	// here, we have used "COIN CHANGE COMBINATION"
	//**************************************************
	// vector<int> value = {15, 14, 10, 45, 30};
	// vector<int> weight = {2, 5, 1, 3, 4};
	// int capacity = 7;

	vector<int> value = {60, 100, 120};
	vector<int> weight = {10, 20, 30};
	int capacity = 50;
	cout << "maximum profit is: " << unboundedZeroOneKnapsack(value, weight, capacity);
}