#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int k) {
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

int main() {
	/*
	VIDEO LINK:
	*/
	vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int k = 2;
	cout << binarySearch(arr, k);
}