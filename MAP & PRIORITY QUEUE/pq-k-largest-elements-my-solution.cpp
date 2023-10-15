#include <bits/stdc++.h>
using namespace std;

void sortKSortedArray(vector<int> arr, int k) {
	priority_queue<int, vector<int>, greater<int>> pq; //min priority queue--min the value higher the priority

	for (auto ele : nums) {
		pq.push(ele);
		if (pq.size() > k) {
			pq.pop();
		}
	}

	return pq.top();
}

int main() {
	//NOTE: i wrote this, no video, think cs
	vector<int> arr = {2, 3, 1, 4, 6, 7, 5, 8, 9};
	sortKSortedArray(arr, 2);
}