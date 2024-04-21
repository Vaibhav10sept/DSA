#include<bits/stdc++.h>
using namespace std;

double MedianOfTwoSortedArrays(vector<int> arr1, vector<int> arr2, int k) {
	/*
	watch video highly recommended
	*/
	//we assume that arr1 is smaller, if its not then below if will handle that
	if (arr2.size() < arr1.size()) return MedianOfTwoSortedArrays(arr2, arr1, k);
	int n1 = arr1.size();
	int n2 = arr2.size();

	//this low and high is kinda complex WV, this is the change from "median of two sorted arrays"
	int low = max(0, k - n2);
	int high = min(k, n1);

	while (low <= high) {
		int cut1 = (low + high) / 2;
		int cut2 = k - cut1; //this is the change from "median of two sorted arrays"

		cout << "cut1 " << cut1 << " cut2 " << cut2 << endl;
		int left1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
		int left2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];

		int right1 = cut1 == n1 ? INT_MAX : arr1[cut1];
		int right2 = cut2 == n2 ? INT_MAX : arr2[cut2];

		if (left1 <= right2 and left2 <= right1) {
			//means its a valid partition
			//this is the change from "median of two sorted array"
			return max(left1, left2);
		}

		else if (left1 > right2) { //left1 ko chota krna hai, toh move left
			high = cut1 - 1;
		}
		else { //left2 > right1
			//right1 ko bada krna hoga, move to right(think, watch video)
			low = cut1 + 1;
		}
	}
	return 0.0;
}

int main() {
	/*
	MUST PREREQUISITE: median of two sorted array
	VIDEO LINK: https://www.youtube.com/watch?v=nv7F4PiLUzo&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=67
	QUESTION: https://takeuforward.org/data-structure/k-th-element-of-two-sorted-arrays/
	*/
	// vector<int> arr1 = {1, 2};
	// vector<int> arr2 = {3, 4};

	vector<int> arr1 = {2, 3, 4, 6, 7, 9};
	vector<int> arr2 = {1, 4, 8, 10};
	int k = 5;
	cout << "result " << MedianOfTwoSortedArrays(arr1, arr2, k);
}