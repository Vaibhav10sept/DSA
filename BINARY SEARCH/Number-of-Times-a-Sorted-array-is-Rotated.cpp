#include<bits/stdc++.h>
using namespace std;

int noOfTimesSortedArrayIsRotated(vector<int> &arr) {
	/*
	watch video recommended
	LOGIC: index of the minimum element = no of rotations of the array
	NOTE: min element hmesa unsorted half of the array me hoga.
	*/
	int n = arr.size();
	int start = 0;
	int end = n - 1;
	int ans = arr[0];
	int minIndex = -1;

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
			if(arr[start] < ans) {
				ans = arr[start];
				minIndex = start;
			}
			
			//we will move to right unsorted portion in search of min value, think, watch video, draw a rotated array and see by yourself
			start = mid + 1;
		}

		//else, we are in right sorted portion
		else {
			//take the min value of right sorted portion in ans
			if(arr[mid] < ans) {
				ans = arr[mid];
				minIndex = mid;
			}
			//we will move to left unsorted portion in search of min value, think, watch video, draw a rotated array and see by yourself
			end = mid - 1;
		}
	}
	return minIndex;
}

int main() {
	/*
	PREREQUISITE: Find minimum in rotated sorted array(almost same code)
	VIDEO LINK: https://www.youtube.com/watch?v=jtSiWTPLwd0&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=8
	*/
	vector<int> arr = {11, 12, 15, 18, 2, 5, 6, 8};
	cout << noOfTimesSortedArrayIsRotated(arr);
}