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


int maximalSqaure(vector<vector<char>> &arr) {
	//good question, wv, think, cs
	int n = arr.size();
	int m = arr[0].size();
	vector<vector<int>> dp(n, vector<int>(m, 0));
	int maxSquare = INT_MIN;

	for (int i = 0; i < dp.size(); i++) {
		for (int j = 0; j < dp[0].size(); j++) {

			if (i == 0 or j == 0) {
				dp[i][j] = arr[i][j] - '0'; //char to int conversion
			}
			else {
				if (arr[i][j] == '1')  {
					dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
				}
				else {
					dp[i][j] = 0;
				}
			}
			maxSquare = max(maxSquare, dp[i][j]);
		}
	}
	return maxSquare * maxSquare;
}

int main()
{
	/***************************
	 * STRONG PREQ: count square submatrix with all ones(same code pattern)
	VIDEO LINK: https://www.youtube.com/watch?v=MMr19RE7KYY
	LEETCODE LINK: https://leetcode.com/problems/maximal-square/
	//**************************************************/
	vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
	cout << maximalSqaure(matrix) << endl;
}