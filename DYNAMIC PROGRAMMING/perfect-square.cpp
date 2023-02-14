#include <bits/stdc++.h>
using namespace std;


int perfectSquare(int n) {
	//Please watch attached video(link) for more understanding.
	//strong prerequisite: longest increasing subsequence.
	vector<int> dp(n + 1);
	//storage: dp[i] stores the no of steps(perfect squares) that is need to sum to "i"
	dp[0] = 0; //initialization: coz
	for (int i = 1; i < dp.size(); i++) {
		int minSteps = INT_MAX;
		for (int j = 1; j * j <= i; j++) {
			int square = j * j;
			if (i - square >= 0) {
				minSteps = min(dp[i - square], minSteps);
			}
		}
		dp[i] = minSteps + 1;
	}

	// for (auto ele : dp) cout << ele << " ";
	return dp[n];
}

int main()
{
	/***************************
	STRONG PREREQUISITE: longest increasing subsequence
	LEETCODE: https://leetcode.com/problems/perfect-squares/description/
	video link: https://www.youtube.com/watch?v=aZuQXkO0-XA
	//**************************************************/
	int n = 12;
	cout << perfectSquare(n);
}