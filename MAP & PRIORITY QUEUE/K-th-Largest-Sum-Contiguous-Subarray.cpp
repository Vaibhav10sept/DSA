#include <bits/stdc++.h>
using namespace std;

int kthLargest(vector<int> &arr, int n, int k) {
	//we use prefix sum technique here.
	// NOTE: i wrote it, wv is required

	vector<int> prefix(n);
	prefix[0] = arr[0];
	for (int i = 1; i < n; i++) {
		prefix[i] = prefix[i - 1] + arr[i];
	}

	//we use prefix to calculate the sum of i to j index
	//and store the sum of all subarrays in a sum vector
	//sort this sum vector in decreasing order
	//then return the k-1 th index which will be the kth largest sum
	vector<int> subarraySum;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int sum = prefix[j] - (i - 1 >= 0 ? prefix[i - 1] : 0);
			subarraySum.push_back(sum);
		}
	}

	sort(subarraySum.begin(), subarraySum.end(), greater<int>());
	return subarraySum[k - 1];
}

int main() {
	/*
	NOTE: i wrote it, wv is required
	//we use prefix sum technique here.
	VIDEO: https://www.youtube.com/watch?v=Rb4jGawY0MA
	QUESTION: https://practice.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
	*/
	int n = 6;
	int k = 20;
	vector<int> arr = {20, 19, 8, 3, 3, 20};
	cout << kthLargest(arr, n, k);
}