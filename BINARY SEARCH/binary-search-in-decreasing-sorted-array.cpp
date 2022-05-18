#include<bits/stdc++.h>
using namespace std;

int binarySearchDecreasingSortedArray(vector<int> arr, int k) {
	int start = 0;
	int end = arr.size() - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2; //we are not using (start + end) / 2, to prevent int overflow
		if (k == arr[mid]) return mid;
		else if (k < arr[mid]) { //move right, coz decreasing sorted array
			start = mid + 1; //move right
		}
		else { //move left, coz decreasing sorted array
			end = mid - 1;
		}
	}
	return -1; //return -1 if not found
}

int main() {
	/*
	VIDEO LINK:
	*/
	vector<int> arr = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	int k = 3;
	cout << binarySearchDecreasingSortedArray(arr, k);
}