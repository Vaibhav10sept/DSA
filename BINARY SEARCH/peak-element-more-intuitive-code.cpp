#include<bits/stdc++.h>
using namespace std;

int peakElement(vector<int> &arr) {
	//edge case
	if (arr.size() == 1) return 0; //we are returning index of the peak element, one size array me ek hi element hoga or vohi peak element hoga.
	int n = arr.size();

	//check for the first and last index so that we don't have to check for corner cases in the while loop
	//same thing hmne single element in a sorted array me bhi ki thi
	if (arr[0] > arr[i + 1]) return 0;
	if (arr[n - 1] > arr[n - 2]) return n - 1;


	//hence we can use start = 1 and end = n-2;
	int start = 1, end = arr.size() - 2, mid;

	while (start <= end) {
		mid = start + (end - start) / 2;

		if (arr[mid] > arr[mid - 1] and arr[mid] > arr[mid + 1]) return mid; //index of peak element

		//kidhar move krna hai
		else if (arr[mid] > arr[mid - 1]) { //increase curse me hai hm, to right side hi peak hoga, think, draw, dry run, wv
			//move right
			start = mid + 1;
		}
		else { //hm decreasing curve me hai, to left side hi peak hoga, think, wv, draw
			//move left
			end = mid - 1;
		}
	}

	return -1;
}


int main() {

	/*
	NOTE: this code is easier to understand
	PREREQUITE:
	VIDEO LINK: https://www.youtube.com/watch?v=cXxmbemS6XM&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=10
	*/
	vector<int> arr = {1, 2};
	cout << peakElement(arr) << endl; //peak element ka index return krre h
}