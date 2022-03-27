#include <bits/stdc++.h>
using namespace std;


int findUnsortedSubarray(vector<int> arr) {
	int end = arr.size() - 1;
	// for getting end, travel from left to right
	int max = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] < max) {
			end  = i;
		}
		else {
			max = std::max(max, arr[i]);
		}
	}

	// for getting start, travel from right to left
	int min = arr[arr.size() - 1];
	int start = 0;
	for (int i = arr.size() - 2; i >= 0; i--) {
		if (arr[i] > min) {
			start = i;
		}
		else {
			min = std::min(min, arr[i]);
		}
	}
	return end - start + 1;
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=GvAtQOMr8CQ&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=23
	// QUESTION:
	// Given an integer array nums, you need to find one continuous
	// subarray that if you only sort this subarray in ascending order,
	// then the whole array will be sorted in ascending order.
	// Return the shortest such subarray and output its length.
	//*********************************
	vector<int> arr = {2, 6, 4, 8, 10, 9, 15};
	cout << findUnsortedSubarray(arr);
}