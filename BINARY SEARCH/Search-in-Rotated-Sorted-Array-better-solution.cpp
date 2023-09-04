#include<bits/stdc++.h>
using namespace std;


int FindanElementInRotatedSortedArray(vector<int> &arr, int k) {
	int start = 0;
	int end = arr.size() - 1;

	while (start <= end) {
		int mid = start + (end - start) / 2;

		if (k == arr[mid]) return mid;

		//check which half of the array is sorted
		if (arr[start] <= arr[mid]) { //left half of the array is sorted
			if (k >= arr[start] and k < arr[mid]) { //k < arr[mid] coz -> k == arr[mid] hm upr line 12 me check kr chuke h
				//move to left half coz k lie in the left half;
				end = mid - 1;
			}
			else { //move to right half
				start = mid + 1;
			}
		}
		else { //right half of the array is sorted
			if (k > arr[mid] and k <= arr[end]) { //k < arr[mid] coz -> k == arr[mid] hm upr line 12 me check kr chuke h
				//move to right half coz k lie in the right half;
				start = mid + 1;
			}
			else { //move to left half
				end = mid - 1;
			}

		}
	}

	//not found, return -1
	return -1;
}

int main() {
	/*
	NOTE: one more solution is also there, but i think this one is better, search: search in rotated sorted array
	QUESTION: https://leetcode.com/problems/search-in-rotated-sorted-array/description/:
	VIDEO LINK: https://www.youtube.com/watch?v=Le8bc8aHgBA
	*/
	vector<int> arr = {3, 1};
	int k = 1;
	cout << FindanElementInRotatedSortedArray(arr, k) << endl;
}