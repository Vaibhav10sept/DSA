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
	// dp works as a storage for DP --> every cell at dp stores the max profit that can be made with elements(value,weight) till i-1 and j capacity
	// NOTE: row(i) --> represents the element ie. the weight and the value
	//       col(j) --> represents the capacity.
	for (int i = 0; i < dp.size(); i++) {
		for (int j = 0; j < dp[0].size(); j++) {
			//first row or first column
			//initialization
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			}

			else { //for every other cells
				if (j - weight[i - 1] >= 0) { // this will ensure that j-weight[i-1] is a valid index
					dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + value[i - 1]);
				}
				else { // j-weight[i-1] < 0 --> means j-weight[i-1] is not a valid index
					dp[i][j] = dp[i - 1][j]; // means mujhe include kr hi nhi skte
				}
			}
		}
	}
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