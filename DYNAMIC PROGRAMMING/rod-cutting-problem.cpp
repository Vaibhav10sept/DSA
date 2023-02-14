#include <bits/stdc++.h>
using namespace std;

int rodCutting(vector<int> arr) {
	// WV recommended
	// NOTE: this code is written by me.
	vector<int> dp(arr.size() + 1); // STORAGE: dp ka har index hold krta h the max profit we can make by cutting the rod of lenght i(index)
	dp[0] = 0; //cost of 0 lenght piece is 0 (think, WV)

	for (int i = 1; i < dp.size(); i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + arr[j - 1]);
		}
	}

	return dp[arr.size()];
}

int main()
{
	//***************************
	// this is 1D DP solution
	// video link: https://www.youtube.com/watch?v=eQuJb5gBkkc
	// PEPCODING LINK: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/dynamic-programming/rod-cutting-official/ojquestion
	//**************************************************
	vector<int> costOfCutting = {1, 5, 8, 9, 10, 17, 17, 20};
	cout << "result" << endl;
	cout << rodCutting(costOfCutting);
}