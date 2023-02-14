#include <bits/stdc++.h>
using namespace std;

int minAverageDifference(vector<int> arr) {
	int n = arr.size();
	vector<int> preSum(n);
	preSum[0] = arr[0];

	for (int i = 1; i < n; i++) {
		preSum[i] = preSum[i - 1] + arr[i];
	}

	int ans = INT_MAX;
	int ansIndex = 0;
	for (int i = 0; i < n; i++) {
		int value = 0;

		if (n - i - 1 != 0) {
			value = abs((preSum[i] / (i + 1)) - ((preSum[n - 1] - preSum[i]) / (n - i - 1)));
		}
		else {
			value = preSum[i] / (i + 1);
		}

		if (value < ans) {
			ans = value;
			ansIndex = i;
		}
	}
	return ansIndex;
}

int main()
{
	/***************************************
	 * LEETCODE LINK: https://leetcode.com/problems/minimum-average-difference/description
	 * NOTE: presum technique is used here.
	 * **************************************/
	vector<int> nums = {2, 5, 3, 9, 5, 3};
	cout << minAverageDifference(nums);
}