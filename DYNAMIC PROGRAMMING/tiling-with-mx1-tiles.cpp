#include <bits/stdc++.h>
using namespace std;

int tilingWithMx1Tiles(int m, int n) {
	vector<int> dp(n + 1);

	for (int i = 1; i < dp.size(); i++) {
		if (i < m) {
			dp[i] = i; //sirf vertically hi rakh skte hai -- think
		}
		else if (i == m) {
			dp[i] = 2; //sare vertically rakh do ya sare horizontally, so 2 ways hai -- think
		}
		else {
			dp[i] = dp[i - 1] + dp[i - m];
		}
	}
	return dp[n];
}


int main()
{
	//***************************
	// video link: https://www.youtube.com/watch?v=_c_R-uIi-zU&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=512
	//**************************************************
	int n = 8;
	int m = 3;
	cout << "no of ways in which mx1 tiles can be laid down: " << tilingWithMx1Tiles(m, n);
}