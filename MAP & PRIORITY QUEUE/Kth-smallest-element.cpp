#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k) {
	int n = r + 1;
	priority_queue<int> pq; //max heap
	for (int i = 0; i < n; i++) {
		if (pq.size() < k) {
			pq.push(arr[i]);
		}
		else if (pq.size() == k) {
			if (pq.top() > arr[i]) {
				pq.pop();
				pq.push(arr[i]);
			}
		}
	}

	return pq.top();
}

int main() {
	/*
	NOTE: i wrote it.
	VIDEO LINK:
	QUESTION: https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
	*/
	int k = 3;
	int l = 0;
	int r = 5;
	int arr[] = {7, 10, 4, 3, 20, 15};
	cout << kthSmallest(arr, l, r, k);
	// for (int ele : ans) cout << ele << " ";
}