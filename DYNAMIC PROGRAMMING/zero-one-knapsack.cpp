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

int zeroOneKnapsack(vector<int> value, vector<int> weight, int capacity) {
	vector<vector<int>> dp(value.size() + 1, vector<int>(capacity + 1));
	for (int i = 0; i < dp.size(); i++) {
		for (int j = 0; j < dp[0].size(); j++) {
			//first row or first column
			//initialization
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			}
			//for every other cells
			else {
				if (j - weight[i - 1] >= 0) {
					dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + value[i - 1]);
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
	}

	displayMatrix(dp);
	return dp[value.size()][capacity];
}

int main()
{
	//***************************
	// video link: https://www.youtube.com/watch?v=bUSaenttI24&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=482
	// similar to target sum subsets
	//**************************************************
	vector<int> value = {15, 14, 10, 45, 30};
	vector<int> weight = {2, 5, 1, 3, 4};
	int capacity = 7;
	cout << "maximum profit is: " << zeroOneKnapsack(value, weight, capacity);
}