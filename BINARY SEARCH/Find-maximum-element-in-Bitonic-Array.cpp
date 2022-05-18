#include<bits/stdc++.h>
using namespace std;

int findMaxInBitonicArray(vector<int> &arr) {
	//this is minified code copied from leetcode, watch video recommended
	int start = 0, end = arr.size() - 1, mid;

	while (start < end) {
		mid = start + (end - start) / 2;

		if (arr[mid] < arr[mid + 1]) //move to right, think ki kaese mid+1 kbhi out of bound nhi jaega(see while ki condition = nhi hai, baki most of the binary search ke code me = hota h), dry run krke dekho
			start = mid + 1;

		else end = mid; //move to left or end = mid kia
		//end = mid -1 nhi kia, coz arr[mid] bhi answer ho skta hai, coz condition hi yahi hai iss else ki arr[mid]>=arr[mid+1]
	}

	return arr[start];
}

int main() {
	/*
	PREREQUISITE: find peak element(same code no difference)
	NOTE: bitonic array me ek hi peak element hoga(think, watch video)
	VIDEO LINK: https://www.youtube.com/watch?v=BrrZL1RDMwc&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=18
	BITONIC ARRAY: an array which is first monotonically(duplicate value nhi hogi ya toh increase kregi ya decrease) increasing and then monotonically decreasing.
	*/
	vector<int> arr = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
	cout << findMaxInBitonicArray(arr) << endl;
}