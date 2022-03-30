#include <bits/stdc++.h>
using namespace std;

int searchInRotateSortedArrayWithDistinctElements(vector<int> arr, int target) {
	//please watch the video(link below) for better understanding.
	int low = 0;
	int high = arr.size() - 1;
	while (low <= high) {
		// int mid = low + (high - low) / 2;
		int mid = (low + high) / 2;
		if (arr[mid] == target) return mid;

		//if the left part of array is sorted
		if (arr[low] <= arr[mid]) {
			// check if target is in range of left sorted array
			if (target >= arr[low] and target <= arr[mid]) {
				//move to left
				high = mid - 1;
			}
			else { //move to right
				low = mid + 1;
			}
		}
		//left half is not sorted, that means right half is sorted
		else {
			//check if target is in range of right sorted array
			if (target >= arr[mid] and target <= arr[high]) {
				//move to right
				low = mid + 1;
			}
			else {  //move to left
				high = mid - 1;
			}
		}
	}
	return -1;
}

int main()
{
	//*****************************
	// NOTE: using binary search approach
	// video link: https://www.youtube.com/watch?v=r3pMQ8-Ad5s
	// time complexity: logn
	//*****************************************
	vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
	int target = 0;
	cout << "TARGET IS FOUND AT INDEX: " << searchInRotateSortedArrayWithDistinctElements(arr, target);
}