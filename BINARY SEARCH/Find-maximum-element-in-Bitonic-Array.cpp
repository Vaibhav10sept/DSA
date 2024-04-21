#include<bits/stdc++.h>
using namespace std;

int findMaxInBitonicArray(vector<int> &arr) {
	//edge case
	if (arr.size() == 1) return 0; //we are returning index of the peak element, one size array me ek hi element hoga or vohi peak element hoga.
	int start = 0, end = arr.size() - 1, mid;

	while (start <= end) {
		mid = start + (end - start) / 2;
		if (mid > 0 and mid < arr.size() - 1) {
			if (arr[mid] > arr[mid - 1] and arr[mid] > arr[mid + 1]) {
				return mid;
			}
			//kidhar move krna h
			else if (arr[mid - 1] > arr[mid]) { //move left
				end = mid - 1;
			}
			else { //move right
				start = mid + 1;
			}
		}

		//check for 0th and last index
		else if (mid == 0) {
			if (arr[mid] > arr[mid + 1]) {
				return mid;
			}
			else
				return 1;
		}
		else if (mid ==  arr.size() - 1) {
			if (arr[mid] > arr[mid - 1]) {
				return mid;
			}
			else
				return arr.size() - 1;
		}
	}
}

int main() {
	/*
	PREREQUISITE: find peak element more intuitive code(same code no difference)
	NOTE: bitonic array me ek hi peak element hoga(think, watch video)
	VIDEO LINK: https://www.youtube.com/watch?v=BrrZL1RDMwc&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=18
	BITONIC ARRAY: an array which is first monotonically(duplicate value nhi hogi ya toh increase kregi ya decrease) increasing and then monotonically decreasing.
	*/
	vector<int> arr = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
	cout << findMaxInBitonicArray(arr) << endl;
}