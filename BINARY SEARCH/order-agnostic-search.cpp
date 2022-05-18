#include<bits/stdc++.h>
using namespace std;

int AscendingBinarySearch(vector<int> arr, int k) {
	//return index of k
	int start = 0;
	int end = arr.size() - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2; //we are not using (start + end) / 2, to prevent int overflow
		if (k == arr[mid]) return mid;
		else if (k < arr[mid]) end = mid - 1; //move left
		else start = mid + 1;//move right
	}
	return -1; //return -1 if not found
}

int DecendingBinarySearch(vector<int> arr, int k) {
	//return the index of k
	int start = 0;
	int end = arr.size() - 1;
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

int agnosticBinarySearch(vector<int> arr, int k) {
	//return the index of k

	//EDGE CASE: if array size is 1
	if (arr.size() == 1) {
		if (k == arr[0]) return 0;
		else return -1;
	}

	if (arr[0] < arr[1]) {
		//means ascending order
		return AscendingBinarySearch(arr, k);

	}
	else {
		//means decending order
		return DecendingBinarySearch(arr, k);
	}
	return -1;
}

int main() {
	/*
	NOTE: here, we don't know that the array is sorted in which order
	VIDEO LINK:
	*/
	vector<int> arr = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	int k = 3;
	cout << agnosticBinarySearch(arr, k);
}