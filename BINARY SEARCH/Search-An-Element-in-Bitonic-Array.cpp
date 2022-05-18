#include<bits/stdc++.h>
using namespace std;

int binarySearchDecreasingSortedArray(vector<int> arr, int k, int start, int end) {
	while (start <= end) {
		int mid = start + (end - start) / 2; //we are not using (start + end) / 2, to prevent int overflow
		if (k == arr[mid]) return mid;
		else if (k < arr[mid]) { //move right, coz decreasing sorted array
			start = mid + 1; //move left
		}
		else { //move left, coz decreasing sorted array
			end = mid - 1;
		}
	}
	return -1; //return -1 if not found
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

int peakElement(vector<int> &arr) {
	int start = 0, end = arr.size() - 1, mid;

	while (start < end) {
		mid = start + (end - start) / 2;

		if (arr[mid] < arr[mid + 1]) //move to right, think ki kaese mid+1 kbhi out of bound nhi jaega
			start = mid + 1;

		else end = mid; //move to left or end = mid kia
		//end = mid -1 nhi kia coz arr[mid] bhi answer ho skta hai, coz condition hi yahi hai iss else ki arr[mid]>=arr[mid+1]
	}

	return start;
}

int SearchAnElementinBitonicArray(vector<int> &arr, int k) {
	//1. find peak element ka index, coz peak element ke left vala increseing sorted hoga
	//or right vala decreasing sorted hoga
	int peakIndex = peakElement(arr);

	//left pe binary search(increasing vala) lga do
	int leftAns = binarySearch(arr, k, 0, peakIndex);
	if (leftAns != -1) return leftAns;

	//right pe decreasing binary search lga do
	int rightAns = binarySearchDecreasingSortedArray(arr, k, peakIndex + 1, arr.size() - 1);
	return rightAns;
}

int main() {
	/*
	PREREQUISITE: find peak element and binary search on sorted array
	NOTE: bitonic array me ek hi peak element hoga(think, watch video)
	VIDEO LINK: https://www.youtube.com/watch?v=BrrZL1RDMwc&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=18
	BITONIC ARRAY: an array which is first monotonically(duplicate value nhi hogi ya toh increase kregi ya decrease) increasing and then monotonically decreasing.
	*/
	vector<int> arr = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
	int k = 10;
	cout << SearchAnElementinBitonicArray(arr, k) << endl;
}