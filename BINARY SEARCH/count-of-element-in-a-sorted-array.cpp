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

int countOfElementInSortedArray(vector<int> arr, int k) {
	int first = firstOccurenceOfAnElement(arr, k);
	int last = lastOccurenceOfAnElement(arr, k);
	return last - first + 1;
}

int main() {
	/*
	PREREQUISITE: first and last index of an element
	NOTE: lastIndex - firstIndex + 1 --> count of an element
	VIDEO LINK:
	*/
	vector<int> arr = {1, 2, 3, 3, 3, 4, 5, 5, 6, 7, 8, 9, 10};
	int k = 3;
	cout << countOfElementInSortedArray(arr, k);
}