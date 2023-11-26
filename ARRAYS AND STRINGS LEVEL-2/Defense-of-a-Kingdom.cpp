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


int defenseKingdom(vector<pair<int, int>> &arr, int n, int m, int t) {
	set<int> row;
	set<int> col;
	for (auto p : arr) {
		row.insert(p.first - 1); //-1 coz to make 0 based indexing
		col.insert(p.second - 1);
	}

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	bool order = true;
	int largestPenalty = 0;
	for (int i = 1; i <= n; i++) {
		if (order) {
			for (int j = 1; j <= m; j++) {
				if (row.find(i - 1) != row.end() or col.find(j - 1) != col.end()) {
					//this i or j index has tower

				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 1;
				}
			}
		}
		else {
			for (int j = dp[0].size() - 1; j >= 1; j--) {
				if (row.find(i - 1) != row.end() or col.find(j - 1) != col.end()) {
					//this i or j index has tower

				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j + 1 < dp[0].size() ? j + 1 : j]) + 1;
				}
			}
		}
		order = !order;
	}

	// displayMatrix(dp);

	//answer is the largest number
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			largestPenalty = max(largestPenalty, dp[i][j]);
		}
	}
	return largestPenalty;
}


int main() {
	/*********************************
	 * //NOTE: i wrote this
	// VIDEO LINK:
	// LEETCODE LINK: https://practice.geeksforgeeks.org/problems/smallest-subset-with-greater-sum/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
	//*********************************/
	int n = 15;
	int m = 8;
	int t = 3;
	vector<pair<int, int>> arr = {{3, 8}, {11, 2}, {8, 6}}; //all in 1 based indexing
	cout << "ans " << defenseKingdom(arr, n, m, t);
}
