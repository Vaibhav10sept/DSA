#include <bits/stdc++.h>
using namespace std;

bool searchInARotatedSortedArrayII(vector<int>&arr, int k) {
	int n = arr.size(); // size of the array.
	int low = 0, high = n - 1;

	while (low <= high) {
		int mid = (low + high) / 2;

		//if mid points the target
		if (arr[mid] == k) return true;

		//Edge case: WV, crucial part of the question remember
		if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
			low = low + 1;
			high = high - 1;
			continue;
		}

		//if left part is sorted:
		if (arr[low] <= arr[mid]) {
			if (arr[low] <= k && k <= arr[mid]) {
				//element exists:
				high = mid - 1;
			}
			else {
				//element does not exist:
				low = mid + 1;
			}
		}
		else { //if right part is sorted:
			if (arr[mid] <= k && k <= arr[high]) {
				//element exists:
				low = mid + 1;
			}
			else {
				//element does not exist:
				high = mid - 1;
			}
		}
	}
	return false;
}

int main()
{
	//*****************************
	// NOTE: using binary search approach
	// video link: https://www.youtube.com/watch?v=w2G2W8l__pc&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=6Wohttps://www.youtube.com/watch?v=YqV0ftquk
	// time complexity:
	// worst case: On
	// best case: logn
	//*****************************************
	vector<int> arr = {4, 5, 6, 7, 0, 0, 0, 1, 2, 3};
	int target = 45;
	cout << "IS TARGET FOUND: " << searchInARotatedSortedArrayII(arr, target);
}