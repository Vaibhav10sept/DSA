#include <bits/stdc++.h>
using namespace std;

int partitionArrayIntoDisjointIntervalsSpaceOptimized(vector<int> arr) {
	int ans = 0;
	int leftMax = arr[0];
	int greater = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] > greater) {
			greater = arr[i];
		}
		if (arr[i] < leftMax) {
			ans = i;
			leftMax = greater;
		}
	}
	return ans + 1;
}

int main() {
	//*********************************
	// NOTE: prerequisite is "max-chunk-to-make-an-array-sorted" and "max-chunk-to-make-an-array-sorted-2"
	// VIDEO LINK: https://www.youtube.com/watch?v=nTzB6L8gJts&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=12
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
	int ans = partitionArrayIntoDisjointIntervalsSpaceOptimized(arr);
	cout << ans << endl;

}