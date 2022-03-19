#include <bits/stdc++.h>
using namespace std;

int maxNoOfChunksToMakeArraySorted(vector<int> arr) {
	int chunkCount = 0;
	int maxImpact = INT_MIN;

	for (int i = 0; i < arr.size(); i++) {
		maxImpact = max(maxImpact, arr[i]);

		if (maxImpact == i) {
			chunkCount++;
		}
	}
	return chunkCount;
}

int main() {
	//*********************************
	// NOTE: we use chaining technique here(important hai or question me bhi use hogi)
	// VIDEO LINK: https://www.youtube.com/watch?v=XZueXHOhO5E
	// QUESTION:
	// 1. Given an array arr that is a permutation of [0, 1, ..., arr.length - 1].
	// 2. We split the array into some number of "chunks" (partitions), and individually sort each chunk.
	// 3. Shuffling of chunk is not allowed.
	// 4. After concatenating them, the result equals the sorted array.
	// 5. What is the most number of chunks we could have made?
	//*********************************

	vector<int> arr = {4, 3, 2, 1, 0};
	cout << "max no of chunks: " << maxNoOfChunksToMakeArraySorted(arr);
}