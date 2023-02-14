#include <bits/stdc++.h>
using namespace std;

int searchInRotateSortedArrayWithDistinctElements(vector<int>& arr, int k) {
	int n = arr.size();
	int start = 0;
	int end = n - 1;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (k == arr[mid]) return mid;

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