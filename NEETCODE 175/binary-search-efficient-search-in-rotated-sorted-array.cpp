#include<bits/stdc++.h>
using namespace std;

int FindanElementInRotatedSortedArray(vector<int> &arr, int k) {
	/*
	watch video recommended
	*/
	int n = arr.size();
	int start = 0;
	int end = n - 1;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (k == arr[mid]) return mid;

		//kidhar jana hai?
		//check if we are in left sorted portion
		if (arr[mid] >= arr[start]) {
			if (k > arr[mid] or k < arr[start]) {
				//move right
				start = mid + 1;
			}
			else { //else, k is less than mid and greater than start element(arr[start])
				//move left
				end = mid - 1;
			}
		}

		//else, we are in right sorted portion
		else {
			if (k < arr[mid] or k > arr[end]) {
				//move left
				end = mid - 1;
			}
			else {//else, k is greater than mid value and k is less than end value
				//move right
				start = mid + 1;
			}
		}
	}
	return -1;
}

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=U8XENwh8Oy8
	*/
	vector<int> arr = {3, 5, 1};
	int k = 1;
	cout << FindanElementInRotatedSortedArray(arr, k) << endl;
}