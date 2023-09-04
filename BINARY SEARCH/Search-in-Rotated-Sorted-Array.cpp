#include<bits/stdc++.h>
using namespace std;

int NumberOfTimesASortedArrayIsRotated(vector<int> &num) {
	//iska code with explaination ye alg question me kia hua h, search and go through the code to understand the approach used.
	int start = 0, end = num.size() - 1;

	while (start < end) {
		if (num[start] < num[end])
			return start;

		int mid = (start + end) / 2;

		if (num[mid] >= num[start]) {
			start = mid + 1;
		} else {
			end = mid;
		}
	}

	return start;
}

int binarySearch(vector<int> arr, int k, int start, int end) {
	while (start <= end) {
		int mid = start + (end - start) / 2; //we are not using (start + end) / 2, to prevent int overflow
		if (k == arr[mid]) return mid;
		else if (k < arr[mid]) end = mid - 1; //move left
		else start = mid + 1;//move right
	}
	return -1; //return -1 if not found
}


int FindanElementInRotatedSortedArray(vector<int> &arr, int k) {
	/*
	LOGIC:
	1. ham min element(pivot)(no of rotation)(before) nikal lete hai
	2. pivot ke left me sab sorted hoga or pivot se right tak sorted hoga
	3. so we have two sorted arrays(undono me binary search lga do)
	*/
	int pivotIndex = NumberOfTimesASortedArrayIsRotated(arr);
	int leftSortedHalf = binarySearch(arr, k, 0, pivotIndex - 1);
	int rightSortedHalf = binarySearch(arr, k, pivotIndex, arr.size() - 1);

	//jisse -1 na mile use return krdo, agr dono me -1 hoga toh -1 hi return hoga(think)
	return leftSortedHalf != -1 ? leftSortedHalf : rightSortedHalf;
}

int main() {
	/*
	NOTE: more better solution is also there check, search: search in rotated sorted array
	PREREQUISITE:
	VIDEO LINK:
	*/
	vector<int> arr = {3, 5, 1};
	int k = 1;
	cout << FindanElementInRotatedSortedArray(arr, k) << endl;
}