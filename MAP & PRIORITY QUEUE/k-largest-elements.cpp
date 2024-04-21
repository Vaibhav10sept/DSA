#include <bits/stdc++.h>
using namespace std;

vector<int> kLargest(int arr[], int n, int k) {
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		pq.push(arr[i]);
	}

	vector<int> ans;

	while (k--) {
		ans.push_back(pq.top());
		pq.pop();
	}

	return ans;
}

int main() {
	/*
	NOTE: i wrote it.
	VIDEO LINK:
	QUESTION: https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1
	*/
	int n = 5;
	int k = 2;
	int arr[] = {12, 5, 787, 1, 23};
	vector<int> ans = kLargest(arr, n, k);
	for (int ele : ans) cout << ele << " ";
}