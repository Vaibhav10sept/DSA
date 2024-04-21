#include <bits/stdc++.h>
using namespace std;

bool jumpGame(vector<int> arr) {
	//THIS IS MY DP SOLUTION.
	//O(N) --> time
	//THIS IS THE DP SOLUTION MORE SOLUTION ARE ALSO THERE
	// WV RECOMMENDED
	vector<bool> dp(arr.size(), false);
	//storage: dp at ith index store true/false that us index se last index tk pahuchna possible h ya nhi
	//initialization
	dp[dp.size() - 1] = true; //think, last me rah ke last pahunchna is always possible

	//traversing from the last index to first, ans is in first index
	for (int i = dp.size() - 2; i >= 0; i--) {
		for (int j = 1; j <= arr[i]; j++) {
			if (i + j < arr.size() and dp[i + j] == true) {
				dp[i] = true;
				break;
			}
		}
	}
	return dp[0];
}

int main() {
	/**************************
	NOTE: THIS IS THE DP SOLUTION MORE SOLUTION ARE ALSO THERE
	 * LEETCODE LINK: https://leetcode.com/problems/jump-game/
	 VIDEO LINK: https://www.youtube.com/watch?v=Yan0cv2cLy8
	 * ******************************/
	vector<int> nums = {2, 3, 1, 1, 4};
	bool ans = jumpGame(nums);
	if (ans) cout << "true";
	else cout << "false";
}