#include <bits/stdc++.h>
using namespace std;

int maximumsumoftwononoverlappingsubarrays(vector<int> arr, int x, int y) {
	//watch video
	//case 1: when x is in left and y is in right
	int n = arr.size();
	vector<int> dp1(n);
	vector<int> dp2(n);
	int currsum = 0;
	//left to right to fill dp1
	//dp1[i]: holds the max sum of x size subarray till ith index.
	for (int i = 0; i < n; i++) {
		if (i < x) {
			currsum += arr[i];
			dp1[i] = currsum;
		}
		else {
			currsum += arr[i] - arr[i - x]; //maintain the sum of x size subarray
			dp1[i] = max(dp1[i - 1], currsum);
		}
	}

	//right to left to fill dp2
	//dp2[i]: holds the max sum of y size subarray till ith index.
	currsum = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (i + y >= n) {
			currsum += arr[i];
			dp2[i] = currsum;
		}
		else {
			currsum += arr[i] - arr[i + y]; //maintain the sum of y size subarray
			dp2[i] = max(dp2[i + 1], currsum);
		}
	}

	int ans = 0;
	for (int i = x - 1; i < n - y; i++) {
		ans = max(ans, dp1[i] + dp2[i + 1]);
	}


	// CASE2: y length ka subarray pehle aa jae or x lenght ka subarray baad me.just coppy paste the above code and replace x and y
	dp1.clear();
	dp2.clear();
	currsum = 0;
	//left to right to fill dp1
	//dp1[i]: holds the max sum of x size subarray till ith index.
	for (int i = 0; i < n; i++) {
		if (i < y) {
			currsum += arr[i];
			dp1[i] = currsum;
		}
		else {
			currsum += arr[i] - arr[i - y]; //maintain the sum of x size subarray
			dp1[i] = max(dp1[i - 1], currsum);
		}
	}

	//right to left to fill dp2
	//dp2[i]: holds the max sum of x size subarray till ith index.
	currsum = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (i + x >= n) {
			currsum += arr[i];
			dp2[i] = currsum;
		}
		else {
			currsum += arr[i] - arr[i + x]; //maintain the sum of y size subarray
			dp2[i] = max(dp2[i + 1], currsum);
		}
	}

	for (int i = y - 1; i < n - x; i++) {
		ans = max(ans, dp1[i] + dp2[i + 1]);
	}

	return ans;
}

int main() {
	//*********************************
	// DP is used here.
	// VIDEO LINK: https://www.youtube.com/watch?v=8e6U4O5VUx0
	// LEETCODE LINK: https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/
	//*********************************
	vector<int> arr = {0, 6, 5, 2, 2, 5, 1, 9, 4};
	int firstLen = 1;
	int secondLen = 2;
	cout << maximumsumoftwononoverlappingsubarrays(arr, firstLen, secondLen);
}