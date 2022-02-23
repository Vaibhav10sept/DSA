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

int paintHouseManyColorsOptimized(vector<vector<int>> arr) {
	//Please watch attached video(link) for more understanding.
	vector<vector<int>> dp(arr.size(), vector<int>(arr[0].size(), 0));
	int firstMin = INT_MAX;
	int secondMin = INT_MAX;
	//initialization
	for (int j = 0; j < dp[0].size(); j++) {
		dp[0][j] = arr[0][j];

		// finding first min and second min using known logic
		if (dp[0][j] <= firstMin) {
			secondMin = firstMin;
			firstMin  = dp[0][j];
		}
		else if (dp[0][j] <= secondMin) {
			secondMin = dp[0][j];
		}

	}

	for (int i = 1; i < dp.size(); i++) {
		int nfirstMin = INT_MAX;
		int nsecondMin = INT_MAX;

		for (int j = 0; j < dp[i].size(); j++) {
			if (dp[i - 1][j] == firstMin) {
				dp[i][j] += secondMin;
			}
			else {
				dp[i][j] += firstMin;
			}
			dp[i][j] += arr[i][j];

			// finding the new first min and second min
			if (dp[i][j] < nfirstMin) {
				nsecondMin = nfirstMin;
				nfirstMin  = dp[i][j];
			}
			else if (dp[i][j] < secondMin) {
				nsecondMin = dp[i][j];
			}
		}
		// updating firstMin and secondMin with the new one
		firstMin = nfirstMin;
		secondMin = nsecondMin;
	}

	return firstMin;
}

int main()
{
	//***************************
	// video link: https://www.youtube.com/watch?v=jGywRalvoRw&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=496
	// NOTE: similar to "paint-house"
	//**************************************************
	//input:
	// 	4 3
	// 1 5 7
	// 5 8 4
	// 3 2 9
	// 1 2 4
	int n, m;
	cin >> n;
	cin >> m;
	vector<vector<int>> input(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> input[i][j];
		}
	}

	cout << "minimum cost of paint with many colors: " << paintHouseManyColorsOptimized(input);
}
