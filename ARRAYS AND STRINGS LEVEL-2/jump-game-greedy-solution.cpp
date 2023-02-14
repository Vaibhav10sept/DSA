#include <bits/stdc++.h>
using namespace std;

bool jumpGame(vector<int> arr) {
	//O(N) --> time
	//THIS IS THE GREEDY SOLUTION MORE SOLUTION ARE ALSO THERE
	// WV RECOMMENDED
	int maxReachableIdx = 0;
	//simple logic, wv, nice question, greedy approach is used
	for (int i = 0; i < arr.size(); i++) {
		if (maxReachableIdx < i) return false;
		maxReachableIdx = max(maxReachableIdx, i + arr[i]);
	}
	return true;
}

int main() {
	/**************************
	NOTE: THIS IS THE GREEDY SOLUTION MORE SOLUTION ARE ALSO THERE
	 * LEETCODE LINK: https://leetcode.com/problems/jump-game/
	 VIDEO LINK: https://www.youtube.com/watch?v=muDPTDrpS28
	 * ******************************/
	vector<int> nums = {2, 3, 1, 1, 4};
	bool ans = jumpGame(nums);
	if (ans) cout << "true";
	else cout << "false";
}