#include <bits/stdc++.h>
using namespace std;

int recursiveHelper(vector<int> arr, int idx, vector<int> &memo) {
	//******************
	//THIS recursive-memoized solution WILL GIVE YOU TLE, A DP SOLUTION IS ALSO THERE
	//*************************

	if (idx == arr.size() - 1) return 0;
	//memoization
	if (memo[idx] != -1) return memo[idx];

	int jump = arr[idx];
	int minJumps = 1e9;
	for (int i = 1; i <= jump and idx + i < arr.size(); i++) {
		minJumps = min(recursiveHelper(arr, i + idx, memo), minJumps);
	}
	minJumps++;
	return memo[idx] = minJumps;
}

int jumpGame2(vector<int> arr) {
	vector<int> memo(arr.size(), -1);
	return recursiveHelper(arr, 0, memo);
}

int main() {
	/**************************
	 * STRONG PREREQUSITE: jump game dp solution
	NOTE: THIS IS THE DP SOLUTION MORE SOLUTION ARE ALSO THERE
	 * LEETCODE LINK: https://leetcode.com/problems/jump-game-ii/
	 VIDEO LINK: https://www.youtube.com/watch?v=phgjL7SbsWs
	 * ******************************/
	// vector<int> nums = {3, 3, 0, 2, 1, 2, 4, 2, 0, 0};
	vector<int> nums = {2, 3, 1, 1, 4};
	cout << jumpGame2(nums);
}