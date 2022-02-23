#include <bits/stdc++.h>
using namespace std;

int countClimbStairPathsWithVariableJumpsDp(int n, vector<int> jumpArray) {
	vector<int> dp(n + 1, 0);
	dp[n] = 1;
	for (int i = n - 1; i >= 0; i--) {
		int ans = 0;
		for (int j = 1; j <= jumpArray[i]; j++) {
			if (i + j < dp.size()) {
				ans += dp[i + j];
			}
		}
		dp[i] = ans;
	}
	return dp[0];
}

int main()
{
	int n = 10;
	vector<int> jumpArray = {3, 3, 0, 2, 1, 2, 4, 2, 0, 0};
	cout << countClimbStairPathsWithVariableJumpsDp(n, jumpArray);
}