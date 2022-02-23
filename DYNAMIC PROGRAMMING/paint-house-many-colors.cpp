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

int findPrivMin(vector<int> arr, int j) {
	int ans = INT_MAX;
	for (int i = 0; i < arr.size(); i++) {
		if (i == j) continue;
		ans = std::min(ans, arr[i]);
	}
	return ans;
}

int paintHouseManyColors(vector<vector<int>> arr) {
	//Please watch attached video(link) for more understanding.
	vector<vector<int>> dp(arr.size(), vector<int>(arr[0].size()));
	for (int i = 0; i < dp.size(); i++) {
		for (int j = 0; j < dp[0].size(); j++) {
			if (i == 0) { //initialization
				dp[i][j] = arr[i][j];
			}
			else {
				int prevMin = findPrivMin(dp[i - 1], j);
				dp[i][j] = arr[i][j] + prevMin;
			}
		}
	}
	return findPrivMin(dp[dp.size() - 1], -1);
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

	cout << "minimum cost of paint with many colors: " << paintHouseManyColors(input);
}
