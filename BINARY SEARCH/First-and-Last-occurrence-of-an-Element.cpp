#include<bits/stdc++.h>
using namespace std;

int lastOccurenceOfAnElement(vector<int> arr, int k) {
	int start = 0;
	int end = arr.size() - 1;
	int ans = -1;
	while (start <= end) {
		int mid = start + (end - start) / 2; //we are not using (start + end) / 2, to prevent int overflow
		if (k == arr[mid]) {
			//move right coz we are searching for the last occurence
			//this is only change as compared to normal binary search code.
			start = mid + 1;
			ans = mid;
		}
		else if (k < arr[mid]) { //move left
			end = mid - 1;
		}
		else { //move right
			start = mid + 1;
		}
	}
	return ans; //return -1 if not found
}

int firstOccurenceOfAnElement(vector<int> arr, int k) {
	int start = 0;
	int end = arr.size() - 1;
	int ans = -1;
	while (start <= end) {
		int mid = start + (end - start) / 2; //we are not using (start + end) / 2, to prevent int overflow
		if (k == arr[mid]) {
			//move left coz we are searching for the first occurence
			//this is only change as compared to normal binary search code.
			end = mid - 1;
			ans = mid;
		}
		else if (k < arr[mid]) { //move left
			end = mid - 1;
		}
		else { //move right
			start = mid + 1;
		}
	}
	return ans; //return -1 if not found
}

int main() {
	/*
	VIDEO LINK:
	*/
	vector<int> arr = {1, 2, 3, 3, 3, 4, 5, 5, 6, 7, 8, 9, 10};
	int k = 3;
	cout << "first occurence: " << firstOccurenceOfAnElement(arr, k) << endl;
	cout << "last occurence: " << lastOccurenceOfAnElement(arr, k);
}