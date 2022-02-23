#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>  constructMatrix() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int> (m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	return arr;
}

void displayMatrix(vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int minimumCostPath(vector<vector<int>> arr) {
	int n = arr.size();
	int m = arr[0].size();
	vector<vector<int>> dp(n, vector<int>(m));
	dp[n - 1][m - 1] = arr[n - 1][m - 1];
	//filling the last row
	for (int j = m - 2; j >= 0; j--) {
		dp[n - 1][j] = arr[n - 1][j] + dp[n - 1][j + 1];
	}

	//filling the last column
	for (int i = n - 2; i >= 0; i--) {
		dp[i][m - 1] = arr[i][m - 1] + dp[i + 1][m - 1];
	}

	//filling the remaining rows and columns
	for (int i = n - 2; i >= 0; i--) {
		for (int j = m - 2; j >= 0; j--) {
			dp[i][j] = std::min(dp[i + 1][j], dp[i][j + 1]);
			dp[i][j] += arr[i][j];
		}
	}

	return dp[0][0];
}

int main()
{
	//***************************
	// https://www.youtube.com/watch?v=BzTIOsC0xWM&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=439
	//********************************
	//STEPS TO SOLVE DP PROBLEMS(TABULATION):
	//1. THINK ABOUT STORAGE AND MEANING
	//2. THINK ABOUT DIRECTION OF THE PROBLEM(FROM SMALLER PROBLEM TO LARGER PROBLEM)
	//3. FINALLY TRAVEL AND SOLVE
	//**************************************************
	//input:
	// 6
	// 6
	// 0 1 4 2 8 2
	// 4 3 6 5 0 4
	// 1 2 4 1 4 6
	// 2 0 7 3 2 2
	// 3 1 5 9 2 4
	// 2 7 0 8 5 1
	vector<vector<int>> arr;
	arr = constructMatrix();
	displayMatrix(arr);
	cout << "********************" << endl;
	cout << "minimum cost: " << minimumCostPath(arr);
}