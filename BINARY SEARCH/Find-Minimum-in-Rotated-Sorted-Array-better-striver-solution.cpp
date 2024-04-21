#include<bits/stdc++.h>
using namespace std;

int findMinInRotatedSortedArray(vector<int> &arr) {
	/*
	watch video recommended
	*/
	int n = arr.size();
	int start = 0;
	int end = n - 1;
	int ans = INT_MAX;


	while (start <= end) {
		int mid = (start + end) / 2;

		//edge case: for optimization: if the arr is already sorted
		if (arr[start] <= arr[end]) { //means the search space is sorted
			ans = min(ans, arr[start]); //whole arr is sroted means the smallest elemetn is in the start of the array
			break; //no need to search further, wv, cs, think
		}

		if (arr[start] <= arr[mid]) { //left half is sorted, so the min value in left half is the arr[start] (think,cs)
			ans = min(ans, arr[start]);
			//since left half is sorted and we already include the min value  of left half in ans, move to right
			start = mid + 1;
		}

		//else, we are in right sorted portion
		else { //right half is sorted, so the min value in right half is the arr[mid] (think,cs)
			ans = min(ans, arr[mid]);
			//since right half is sorted and we already include the min value  of right half in ans, move to left
			end = mid - 1;
		}
	}
	return ans;
}

int main() {
	/*
	PREREQUISITE: search in rotated sorted array
	VIDEO LINK: https://www.youtube.com/watch?v=nhEMDKMB44g&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=7
	QUESTION: https://www.codingninjas.com/studio/problems/rotated-array_1093219?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries
	*/
	vector<int> arr = {3, 4, 1, 2};
	// vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
	cout << findMinInRotatedSortedArray(arr);
}