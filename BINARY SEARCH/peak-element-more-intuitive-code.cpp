#include<bits/stdc++.h>
using namespace std;

int peakElement(vector<int> &arr) {
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
	NOTE: this code is easier to understand
	PREREQUITE: same code as in question: no of times arrays is rotated
	NOTE: given arr is unsorted, So here we are using a concept "binary search on answer"
	VIDEO LINK: https://www.youtube.com/watch?v=OINnBJTRrMU&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=17
	*/
	vector<int> arr = {1, 2};
	cout << peakElement(arr) << endl; //peak element ka index return krre h
}