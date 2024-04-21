#include <bits/stdc++.h>
using namespace std;

vector<int> rangeSumQuery(vector<vector<int>> arr, vector<vector<int>> queries) {
	int n = arr.size();
	int m = arr[0].size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	//precomputations
	for (int i = 1; i < dp.size(); i++) {
		for (int j = 1; j < dp[0].size(); j++) {
			//think, cs, wv --> mene khud se soch ke likha hai ye no need to memorize anything here
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i - 1][j - 1];
		}
	}

	//queries run kro(time complexy constant for every query)
	vector<int> ans;
	for (auto query : queries) {
		int r1 = query[0];
		int c1 = query[1];
		int r2 = query[2];
		int c2 = query[3];

		int sum = dp[r2 + 1][c2 + 1] - dp[r1][c2 + 1] - dp[r2 + 1][c1] + dp[r1][c1];
		ans.push_back(sum);
	}
	return ans;
}
int main()
{
	/***************************
	 * STRONG PREQ:
	VIDEO LINK: https://www.youtube.com/watch?v=tk0Twx2VQy8
	LEETCODE LINK: https://leetcode.com/problems/range-sum-query-2d-immutable/
	//**************************************************/
	vector<vector<int>> arr = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
	vector<vector<int>> queries = {{2, 1, 4, 3}, {1, 1, 2, 2}, {1, 2, 2, 4}};
	vector<int> ans = rangeSumQuery(arr, queries);
	for (auto ele : ans) cout << ele << " ";
	cout << endl;
}