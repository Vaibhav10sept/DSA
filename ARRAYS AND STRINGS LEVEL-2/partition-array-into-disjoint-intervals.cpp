#include <bits/stdc++.h>
using namespace std;

int partitionArrayIntoDisjointIntervals(vector<int> arr) {
	vector<int> rightMin(arr.size() + 1);
	rightMin[arr.size()] = INT_MAX;

	for (int i = arr.size() - 1; i >= 0; i--) {
		rightMin[i] = min(arr[i], rightMin[i + 1]);
	}
	// for (auto ele : rightMin) cout << ele << " ";
	int leftMax = INT_MIN;
	int ans = 0;
	for (int i = 0; i < arr.size(); i++) {
		leftMax = std::max(leftMax, arr[i]);
		if (leftMax < rightMin[i + 1]) {
			ans = i;
			break;
		}
	}
	return ans + 1;
}

int main() {
	//*********************************
	// NOTE: prerequisite is "max-chunk-to-make-an-array-sorted" and "max-chunk-to-make-an-array-sorted-2"
	// VIDEO LINK: https://www.youtube.com/watch?v=FRG2YlZdmPE&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=11
	// QUESTION:
	// 1. Given an integer array nums.
	// 2. Partition it into two (contiguous) subarrays left and right so that:
	//     a. Every element in left is less than or equal to every element in right.
	//     b. Left and right are non-empty.
	//     c. Left has the smallest possible size.
	// 3. Return the length of left after such a partitioning.
	// NOTE : Test cases are generated such that partitioning exists.
	//*********************************
	vector<int> arr = {5, 0, 3, 8, 6};
	int ans = partitionArrayIntoDisjointIntervals(arr);
	cout << ans << endl;

}