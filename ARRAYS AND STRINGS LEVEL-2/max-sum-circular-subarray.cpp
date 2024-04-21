#include <bits/stdc++.h>
using namespace std;

int maxSubarray(vector<int> arr) {
	int maxsum = arr[0];
	int currsum = arr[0];

	for (int i = 1; i < arr.size(); i++) {
		int ele = arr[i];
		currsum = max(currsum + ele, ele);
		maxsum = max(currsum, maxsum);
	}
	return maxsum;
}



int minSubarray(vector<int> arr) {
	int minsum = arr[0];
	int currsum = arr[0];

	for (int i = 1; i < arr.size(); i++) {
		int ele = arr[i];
		currsum = min(currsum + ele, ele);
		minsum = min(currsum, minsum);
	}
	return minsum;
}


int maxSubarraySumCircular(vector<int> arr) {
	//wv if required
	int minSum = minSubarray(arr);
	int maxSum = maxSubarray(arr);

	int sum = 0;
	for (auto ele : arr) sum += ele;

	if (maxSum < 0) { //edge case: means all the element are negative(agr max sum negative h to obivo all negative hoge)
		return maxSum;
	}

	return max(maxSum, sum - minSum);
}

int main() {
	/*********************************
	 * STRONG PREQ: maximum subarray sum (not kadane algo)
	// VIDEO LINK: https://www.youtube.com/watch?v=fxT9KjakYPM
	// LEETCODE LINK: https://leetcode.com/problems/maximum-sum-circular-subarray/description/
	//*********************************/
	vector<int> nums = { 5, -3, 5};
	cout << maxSubarraySumCircular(nums);
}