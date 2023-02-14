#include <bits/stdc++.h>
using namespace std;

void printFibonacci(int n) {
	vector<int> dp(n + 1);
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i < dp.size(); i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	for (auto ele : dp) cout << ele << " ";
}

int main()
{
	printFibonacci(10);
}