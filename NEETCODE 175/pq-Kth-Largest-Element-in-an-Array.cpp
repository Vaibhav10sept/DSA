#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
	//Min-Heap Initialization
	priority_queue<int, vector<int>, greater<int>> pq;

	//We push first k elements into min-heap
	for (int i = 0; i < k; i++) pq.push(nums[i]);

	//Now, if the element at top of min-heap is smaller, we remove it and add new element
	for (int i = k; i < nums.size(); i++) {
		if (pq.top() < nums[i]) {
			pq.pop();
			pq.push(nums[i]);
		}
	}

	//Return the top (smallest) of min-heap
	return pq.top();
}

int main() {
	/*
	VIDEO LINK:
	QUESTION LINK: https://leetcode.com/problems/kth-largest-element-in-an-array/
	*/
	vector<int> arr = {3, 2, 1, 5, 6, 4};
	int k = 2;

	cout << findKthLargest(arr, k);
}