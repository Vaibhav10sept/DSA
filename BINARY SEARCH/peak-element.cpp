#include<bits/stdc++.h>
using namespace std;

int peakElement(vector<int> &arr) {
	int start = 0, end = arr.size() - 1, mid;

	while (start < end) {
		mid = start + (end - start) / 2;

		if (arr[mid] < arr[mid + 1]) //move to right, think ki kaese mid+1 kbhi out of bound nhi jaega
			start = mid + 1;

		else end = mid; //move to left or end = mid kia
		//end = mid -1 nhi kia coz arr[mid] bhi answer ho skta hai, coz condition hi yahi hai iss else ki arr[mid]>=arr[mid+1]
	}

	return start;
}


int main() {

	/*
	PREREQUITE: same code as in question: no of times arrays is rotated
	NOTE: given arr is unsorted, So here we are using a concept "binary search on answer"
	VIDEO LINK: https://www.youtube.com/watch?v=B4t3NB0478k
	NOTE: watch the above video at 1hr 19min
	*/
	vector<int> arr = {1, 2, 3, 1};
	cout << peakElement(arr) << endl;
}