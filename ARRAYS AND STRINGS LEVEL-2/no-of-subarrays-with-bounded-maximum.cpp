#include <bits/stdc++.h>
using namespace std;

int noOfSubarrayWithBoundedMaximum(vector<int> arr, int left, int right) {
	//good question watch video.
	int startIdx = 0;
	int endIdx = 0;

	int totalCount = 0;
	int prevCount = 0; //no. of subarray ending at endIdx
	while (endIdx < arr.size()) {
		//there can be 3 cases.
		if (left <= arr[endIdx] and arr[endIdx] <= right) {
			prevCount = startIdx - endIdx + 1; //no. of element in between two indexes(logic)
			totalCount += prevCount;
		}
		else if (arr[endIdx] < left) {
			//in this case, prevcount no. of subarrays can be formed(think)
			totalCount += prevCount;
		}
		else if (arr[endIdx] > right) {
			//in this case no subarray can be formed(think)
			//reset
			startIdx = endIdx + 1;
			prevCount = 0;
		}
		endIdx++;
	}
	return totalCount;
}

int main() {
	//*********************************
	// NOTE: no of subarrays => n(n+1)/2
	// NOTE: this is a DP question.
	// COM: O(n)
	// VIDEO LINK: https://www.youtube.com/watch?v=My3pobBPtbA&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=34
	// QUESTION:
	// 1. We have an array 'arr' of positive integers, and two positive integers left and right (left is smaller than right).
	// 2. Return the number of (contiguous, non-empty) subarrays such that the value of the maximum array element in that subarray is at least left and at most right.
	//*********************************

	vector<int> arr = {2, 1, 4, 3};
	int left = 2;
	int right = 3;
	cout << "no of subarrays are: " << noOfSubarrayWithBoundedMaximum(arr, left, right);
}