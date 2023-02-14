#include<bits/stdc++.h>
using namespace std;

int chocolateDistributionProblem(vector<int> arr, int m) {
	//easy prob, just need to think that way, WV
	sort(arr.begin(), arr.end());
	int ans = INT_MAX;
	for (int i = 0; i + m - 1 < arr.size(); i++) {
		int diff = arr[i + m - 1] - arr[i];
		ans = min(diff, ans);
	}
	return ans;
}

int main() {
	//**************************************
	//VIDEO LINK: https://www.youtube.com/watch?v=T_2CATt_XyQ
	// QUESTION LINK: https://www.geeksforgeeks.org/chocolate-distribution-problem/
	//*******************************************
	vector<int> arr = {7, 3, 2, 4, 9, 12, 56};
	int m = 3;
	cout << chocolateDistributionProblem(arr, m);
}

