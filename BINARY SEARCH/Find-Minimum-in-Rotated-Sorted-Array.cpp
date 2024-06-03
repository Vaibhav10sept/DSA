#include<bits/stdc++.h>
using namespace std;

int findMinInRotatedSortedArray(vector<int> &arr) {
	/*
	watch video recommended
	*/
	int n = arr.size();
	int start = 0;
	int end = n - 1;
	int ans = arr[0];

	//MAIN IDEA: the unsorted contains the min element
	///LOGIC: the unsorted half may or may not have the min element(think, dry run, cs, wv)
	//So, pick the min from the sorted half and move to unsorted half in search of min element.

	while (start <= end) {

		int mid = (start + end) / 2;
		
		//kidhar jana hai?
		//check if we are in left sorted portion
		if (arr[start] <= arr[mid]) {
			//we are in left sorted portion
			//take the min value of left sorted portion in ans
			ans = min(ans, arr[start]);
			//we will move to right unsorted portion in search of min value, think, watch video, draw a rotated array and see by yourself
			start = mid + 1;
		}

		//else, we are in right sorted portion
		else {
			//take the min value of right sorted portion in ans
			ans = min(ans, arr[mid]);
			//we will move to left unsorted portion in search of min value, think, watch video, draw a rotated array and see by yourself
			end = mid - 1;
		}
	}
	return ans;
}

int main() {
	/*
	//MAIN IDEA: the unsorted contains the min element
	SIMILAR CODE: no of times a sorted array is rotated, search in rotated sorted array
	VIDEO LINK: https://www.youtube.com/watch?v=nhEMDKMB44g&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=7
	LEETCODE: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
	*/
	vector<int> arr = {11, 12, 15, 18, 2, 5, 6, 8};
	// vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
	cout << findMinInRotatedSortedArray(arr);
}