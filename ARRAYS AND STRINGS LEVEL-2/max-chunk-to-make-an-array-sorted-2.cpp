#include <bits/stdc++.h>
using namespace std;

int maxNoOfChunksToMakeArraySorted2(vector<int> arr) {
	int chunkCount = 0;
	vector<int> rightMin(arr.size() + 1);
	rightMin[arr.size()] = INT_MAX;

	// filling up the right minimum array
	for (int i = arr.size() - 1; i >= 0; i--) {
		rightMin[i] = min(rightMin[i + 1], arr[i]);
	}

	int leftMax = INT_MIN;
	for (int i = 0; i < arr.size(); i++) {
		leftMax = std::max(arr[i], leftMax);
		if (leftMax <= rightMin[i + 1]) {
			chunkCount++;
		}
	}

	return chunkCount;
}

int main() {
	//*********************************
	// NOTE: prerequisite is "max-chunk-to-make-an-array-sorted"
	// NOTE: we use chaining technique here(important hai or question me bhi use hogi)
	// VIDEO LINK: https://www.youtube.com/watch?v=GxTo3agdnjs&t=175s
	// QUESTION:
	// 1. Given an array arr of integers (not necessarily distinct).
	// 2. We split the array into some number of "chunks" (partitions), and individually sort each chunk.
	// 3. After concatenating them, the result equals the sorted array.
	// 4. What is the most number of chunks we could have made?
	//*********************************

	vector<int> arr = {2, 1, 3, 4, 4};
	// vector<int> arr = {30, 10, 20, 40, 60, 50, 75, 70};
	cout << "max no of chunks: " << maxNoOfChunksToMakeArraySorted2(arr);
}