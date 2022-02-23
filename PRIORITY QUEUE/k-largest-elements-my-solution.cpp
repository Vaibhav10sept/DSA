#include <bits/stdc++.h>
using namespace std;

void sortKSortedArray(vector<int> arr, int k) {
	priority_queue<int, vector<int>, greater<int>> pq; //min priority queue--min the value higher the priority

	int idx = 0;
	while (idx < arr.size()) {
		if (pq.size() > k + 1) {
			cout << pq.top() << " ";
			pq.pop();
			pq.push(arr[idx]);
		}
		else {
			pq.push(arr[idx]);
		}
		idx++;
	}
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
}

int main() {
	vector<int> arr = {2, 3, 1, 4, 6, 7, 5, 8, 9};
	sortKSortedArray(arr, 2);
}