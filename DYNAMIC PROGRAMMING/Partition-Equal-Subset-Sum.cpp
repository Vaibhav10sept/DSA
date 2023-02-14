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

bool partitionEqualSubsetSum(vector<int> arr) {
	// WV recommended
	//LOGIC: we are using target sum subset code.
	//equal sum vale do subsets ke kie, unn dono subset ka sum = total sum / 2 hona chahiye(think,CS)
	//age aesa subset h jiska sum = total sum / 2, h to obviously dosra ek subset jrurut hoga jiska sum = total sum / 2 h
	//hence hme do subset mil jaege jiska sum equal hoga means total sum / 2 hoga
	int totalSum = 0;
	for (auto ele : arr) {
		totalSum += ele;
	}
	if (totalSum % 2 == 1) { //total sum is odd
		//odd sum ko 2 se divide krke hme do equal sum nhi milega, hence do equal sum vale subsets bhi nhi bnege
		return false;
	}

	int target = totalSum / 2; //as total sum is even, it can be divided into two equal parts
	return targetSumSubsetDP(arr, target);
}

int main() {
	/*********************************
	 * STRONG PREREQUISITE: DP --> target sum subset
	LEETCODE: https://leetcode.com/problems/partition-equal-subset-sum/
	VIDEO LINK: https://www.youtube.com/watch?v=7win3dcgo3k
	*********************************/
	vector<int> arr = {1, 2, 3, 5};
	bool ans = partitionEqualSubsetSum(arr);
	if (ans) cout << "true";
	else cout << "false";
}