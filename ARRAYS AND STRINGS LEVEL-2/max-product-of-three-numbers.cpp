#include <bits/stdc++.h>
using namespace std;

int maxProductOfThreeNumbers(vector<int> arr) {
	int max1 = INT_MIN;
	int max2 = INT_MIN;
	int max3 = INT_MIN;

	int min1 = INT_MAX;
	int min2 = INT_MAX;

	for (auto ele : arr) {
		if (ele > max1) {
			max3 = max2;
			max2 = max1;
			max1 = ele;
		}
		else if (ele > max2) {
			max3 = max2;
			max2 = ele;
		}
		else if (ele > max3) {
			max3 = ele;
		}
		//for min1 and min2
		if (ele < min1) {
			min2 = min1;
			min1 = ele;
		}
		else if (ele < min2) {
			min2 = ele;
		}
	}
	return max(min1 * min2 * max1, max1 * max2 * max3);
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=fQF7tAmMKHE&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=16
	// QUESTION:
	// 1. Given an integer array 'arr',
	// 2. Find three numbers whose product is maximum and return the maximum product.
	//*********************************
	vector<int> arr = {3, 2, -4, -6, 5, 1};
	cout << "max product of three numbers in an array: " << maxProductOfThreeNumbers(arr);
}