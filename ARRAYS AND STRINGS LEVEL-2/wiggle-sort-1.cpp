#include <bits/stdc++.h>
using namespace std;

void wiggleSort1(vector<int> &arr) {
	// LOGIC:
	// even indexes are less than or equal to odd indexes
	// odd indexes are greater than or equal to even indexes
	for (int i = 0; i < arr.size() - 1; i++) {
		if (i % 2 == 0) { //even index
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
			}
		}
		else { // odd index
			if (arr[i] < arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
			}
		}
	}
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=mwsjU6CHOb4&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=27
	// QUESTION:
	// 1. Given an unsorted array 'arr'.
	// 2. Reorder it in-place such that :  arr[0] <= arr[1] >= arr[2] <= arr[3] . . . .
	// 3. Please sort the array in place and do not define additional arrays.
	// 4. Allowed Time Complexity : O(n)
	//*********************************
	vector<int> arr = {3, 5, 2, 1, 6, 4};
	wiggleSort1(arr);
	for (auto ele : arr) cout << ele << " ";
}