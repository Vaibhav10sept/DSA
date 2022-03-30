#include <bits/stdc++.h>
using namespace std;

bool searchInRotateSortedArrayWithDistinctElements(vector<int> arr, int target) {
	//please watch the video(link below) for better understanding.
	int low = 0;
	int high = arr.size() - 1;
	while (low <= high) {
		// int mid = (low + high) / 2;
		int mid = low + (high - low) / 2;

		if (arr[mid] == target) return true;

		//if the left part of array is sorted
		if (arr[low] < arr[mid]) {
			// check if target is in range of left sorted array
			if (target >= arr[low] and target < arr[mid]) {
				//move to left
				high = mid - 1;
			}
			else { //move to right
				low = mid + 1;
			}
		}
		//left half is not sorted, that means right half is sorted
		else if (arr[mid] < arr[low]) {
			//check if target is in range of right sorted array
			if (target > arr[mid] and target <= arr[high]) {
				//move to right
				low = mid + 1;
			}
			else {  //move to left
				high = mid - 1;
			}
		}
		else { //special case for duplicacy, watch video
			//when we are not sure on which half the target is present, becoz of duplicacy
			//arr[low] == arr[mid] == arr[high]
			low++;
		}
	}
	return false;
}

int main()
{
	//*****************************
	// NOTE: using binary search approach
	// video link: https://www.youtube.com/watch?v=YqV0ftqukWo
	// time complexity:
	// worst case: On
	// best case: logn
	//*****************************************
	vector<int> arr = {4, 5, 6, 7, 0, 0, 0, 1, 2, 3};
	int target = 45;
	cout << "IS TARGET FOUND: " << searchInRotateSortedArrayWithDistinctElements(arr, target);
}