#include<bits/stdc++.h>
using namespace std;

int noOfTimesSortedArrayIsRotated(vector<int> &arr) {
	/*
	watch video recommended
	LOGIC: index of the minimum element = no of rotations of the array
	NOTE: min element hmesa unsorted half of the array me hoga.
	NOTE: min element ki pehchan h ki vo apne dono neighbour se chota hoga.
	MOVE: min element check krege, agr nhi mila to move to the unsorted half of the array.
	*/
	int n = arr.size();
	int start = 0;
	int end = n - 1;
	int ans = -1;


	while (start <= end) {
		if (arr[start] < arr[end]) //means, array is sorted so the min value is the left most value which is arr[start]
			return start;

		int mid = (start + end) / 2;
		ans = min(ans, mid); //is way se bhi min element find kr skte h.

		//kidhar jana hai?
		//check if we are in left sorted portion
		if (arr[start] <= arr[mid]) { //means left half of the array is sorted.
			//and we have to move to the right half, because if left is sorted that means, righ is unsorted and we are moving to the unsorted half in search of minimum element.
			//we will move to right unsorted portion in search of min value, think, watch video, draw a rotated array and see by yourself
			start = mid + 1;
		}

		else { //means the right half is sorted, so we'll move to the left unsorted half of the array.
			//we will move to left unsorted portion in search of min value, think, watch video, draw a rotated array and see by yourself
			end = mid; //IDK why mid-1 ni kia, agr mid-1 krege to leetcode me submit ni hoga.
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