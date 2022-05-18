#include<bits/stdc++.h>
using namespace std;

int findMinInRotatedSortedArray(vector<int> &arr) {
	int start = 0, end = arr.size() - 1;

	while (start < end) {
		if (arr[start] < arr[end])
			return arr[start];

		int mid = (start + end) / 2;

		if (arr[mid] >= arr[start]) {
			start = mid + 1;
		} else {
			end = mid;
		}
	}

	return arr[start];
}

int main() {
	/*
	PREREQUISITE: no of times a sorted array is rotated
	VIDEO LINK:
	*/
	vector<int> arr = {11, 12, 15, 18, 2, 5, 6, 8};
	cout << findMinInRotatedSortedArray(arr);
}