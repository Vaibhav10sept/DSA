#include <bits/stdc++.h>
using namespace std;

void print(vector<int> arr) {
	for (auto ele : arr) cout << ele << " ";
	cout << endl;
}

void reverseArray(vector<int> &arr) {
	int li = 0;
	int ri = arr.size() - 1;
	while (li < ri) {
		int temp = arr[li];
		arr[li] = arr[ri];
		arr[ri] = temp;
		li++;
		ri--;
	}
}

void firstIndex(vector<int> arr, int data) {
	int left = 0;
	int right = arr.size() - 1;
	int firstIndex = -1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (data == arr[mid]) {
			right = mid - 1;
			firstIndex = mid;
			// left = mid + 1;

		}
		else if (data < arr[mid]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << "first index: " << firstIndex << endl;
}

void lastIndex(vector<int> arr, int data) {
	int left = 0;
	int right = arr.size() - 1;
	int lastIndex = -1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (data == arr[mid]) {
			// right = mid - 1;
			left = mid + 1;
			lastIndex = mid;

		}
		else if (data < arr[mid]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << "last index: " << lastIndex << endl;
}

int main()
{
	vector<int> arr = {1, 2, 2, 2, 4, 4};
	print(arr);
	firstIndex(arr, 2);
	lastIndex(arr, 2);
}