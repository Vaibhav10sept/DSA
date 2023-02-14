#include <bits/stdc++.h>
using namespace std;

bool targetSumSubsetDP(vector<int> arr, int target) {
	vector<vector<bool>> dp(arr.size() + 1, vector<bool> (target + 1, false));
	// row --> array ke element hote h, means subsets hote h
	// col --> target hota h
	// dp[i][j] --> store bool value --> if it is possible to create a subset using values till arr[i-1](bcoz array index is one less than the row(i) in dp) and target as j.
	for (int i = 0; i < dp.size() ; i++) { // row --> array ke elements
		for (int j = 0; j < dp[0].size(); j++) {
			//first row and first column means 0 sum and empty subset
			if (i == 0 and j == 0) {
				dp[i][j] = true;
			}
			//first row means no data in the subset(empty subset)
			else if (i == 0) {
				dp[i][j] = false;
			}
			//first column means 0 sum
			else if (j == 0) {
				dp[i][j] = true;
			}
			//for every other cells
			else {
				if (dp[i - 1][j] == true) {
					dp[i][j] = true;
				}
				else { //dp[i-1][j] == false
					int val = arr[i - 1]; // bcoz array index is 1 less than the row no(i). think
					if (val <= j) {
						if (dp[i - 1][j - val]) {
							dp[i][j] = true;
						}
					}
				}
			}
		}
	}
	//returning the last row and column
	return dp[arr.size()][target];
}

int main()
{
	//***************************
	// video link: https://www.youtube.com/watch?v=tRpkluGqINc&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=478
	// subset/subsequence: 2^n; har element ke pass 2 option hai ya toh subset me aae
	// ya na aae
	// subarray: N*(N+1)/2; subarray continuous hote hai
	//**************************************************
	vector<int> arr = {2, 3, 5};

	bool ans = targetSumSubsetDP(arr, 7);
	if (ans) cout << "true";
	else cout << "false";
}