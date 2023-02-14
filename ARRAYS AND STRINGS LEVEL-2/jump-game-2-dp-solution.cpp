#include <bits/stdc++.h>
using namespace std;

int jumpGame2(vector<int> arr) {
	//THIS IS MY DP SOLUTION.
	//THIS IS THE DP SOLUTION MORE SOLUTION ARE ALSO THERE
	// WV RECOMMENDED
	vector<int> dp(arr.size());
	//storage: dp at ith index store true/false that us index se last index tk pahuchne me kitni min no of jumps required hai
	//initialization
	dp[dp.size() - 1] = 0; //think, last me rah ke last index tk pahuchne ke lie 0 jump lgegi

	//traversing from the last index to first, ans is in first index
	for (int i = dp.size() - 2; i >= 0; i--) {
		int minValue = INT_MAX;
		for (int j = 1; j <= arr[i]; j++) {
			if (i + j < arr.size()) {
				if (dp[i + j] != INT_MAX and dp[i + j] < minValue) {
					minValue = dp[i + j];
				}
			}
		}
		if (minValue != INT_MAX) {
			dp[i] = minValue + 1; //+1 coz ek jump ho tumhare index se bhi hoga (WV)
		}
		else dp[i] = INT_MAX;
	}
	return dp[0];
}

int main() {
	/**************************
	 * STRONG PREREQUSITE: jump game dp solution
	NOTE: THIS IS THE DP SOLUTION MORE SOLUTION ARE ALSO THERE
	 * LEETCODE LINK: https://leetcode.com/problems/jump-game-ii/
	 VIDEO LINK: https://www.youtube.com/watch?v=phgjL7SbsWs
	 * ******************************/
	// vector<int> nums = {3, 3, 0, 2, 1, 2, 4, 2, 0, 0};
	vector<int> nums = {2, 3, 0, 1, 4};
	cout << jumpGame2(nums);
}