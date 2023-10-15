#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
	//Min-Heap Initialization
	priority_queue<int, vector<int>, greater<int>> pq;

	for (auto ele : nums) {
		pq.push(ele);
		if (pq.size() > k) {
			pq.pop();
		}
	}

	//Return the top (smallest) of min-heap
	return pq.top();
}

int main() {
	/*
	NOTE: i wrote this, no video required, think, cs
	QUESTION LINK: https://leetcode.com/problems/kth-largest-element-in-an-array/
	*/
	vector<int> arr = {3, 2, 1, 5, 6, 4};
	int k = 2;

	cout << findKthLargest(arr, k);
}