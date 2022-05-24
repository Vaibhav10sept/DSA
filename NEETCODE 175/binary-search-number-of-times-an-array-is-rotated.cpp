#include<bits/stdc++.h>
using namespace std;

int noOfTimesSortedArrayIsRotated(vector<int> &arr) {
	/*
	watch video recommended
	*/
	int n = arr.size();
	int start = 0;
	int end = n - 1;
	int ans = -1;


	while (start <= end) {
		if (arr[start] < arr[end]) //means, array is sorted so the min value is the left most value which is arr[start]
			return start;

		int mid = (start + end) / 2;
		ans = min(ans, mid);

		//kidhar jana hai?
		//check if we are in left sorted portion
		if (arr[start] <= arr[mid]) {
			//we are in left sorted portion
			//we will move to right sorted portion in search of min value, think, watch video, draw a rotated array and see by yourself
			start = mid + 1;
		}

		//else, we are in right sorted portion
		else {
			//we will move to left sorted portion in search of min value, think, watch video, draw a rotated array and see by yourself
			end = mid;
		}
	}
	return ans;
}

int main() {
	/*
	PREREQUISITE: no of times a sorted array is rotated(same code), search in rotated sorted array
	VIDEO LINK: https://www.youtube.com/watch?v=nIVW4P8b1VA
	*/
	vector<int> arr = {11, 12, 15, 18, 2, 5, 6, 8};
	cout << noOfTimesSortedArrayIsRotated(arr);
}