#include<bits/stdc++.h>
using namespace std;

int NumberOfTimesASortedArrayIsRotated(vector<int> &arr) {
	//jo index min element ka hoga utne times hi array rotate hue hoga(think)
	//so qustion find the min index in sorted rotated array and no of times an array is rotated is same
	int start = 0, end = arr.size() - 1;

	while (start < end) {//rem: = nhi hai while condition me
		if (arr[start] < arr[end])
			return start;

		int mid = (start + end) / 2;

		if (arr[mid] >= arr[start]) {
			start = mid + 1;
		} else {
			end = mid;
		}
	}

	return start;
}

int main() {
	/*
	SIMILAR QUESTION: Find Minimum in Rotated Sorted Array
	VIDEO LINK: https://www.youtube.com/watch?v=4WmTRFZilj8&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=7
	*/
	vector<int> arr = {11, 12, 15, 18, 2, 5, 6, 8};
	cout << NumberOfTimesASortedArrayIsRotated(arr);
}