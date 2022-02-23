#include <bits/stdc++.h>
using namespace std;

int tilingWithDominoes(int n) {
	vector<int> dp(n + 1);
	dp[1] = 1;
	dp[2] = 2;//think

	for (int i = 3; i < dp.size(); i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}

int main()
{
	//***************************
	// video link: https://www.youtube.com/watch?v=dVT9JeUMMDE&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=511
	//**************************************************
	int n = 4;
	cout << "no of ways in which tiles can be laid down: " << tilingWithDominoes(n);
}