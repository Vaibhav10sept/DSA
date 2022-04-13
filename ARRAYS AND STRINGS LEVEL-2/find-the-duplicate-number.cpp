#include <bits/stdc++.h>
using namespace std;

int findTheDuplicateNumber(vector<int> &arr) {
	for (int i = 0; i < arr.size(); i++) {
		int idx = abs(arr[i]) - 1;
		if (arr[idx] < 0) {
			return abs(arr[i]);
		}
		else {
			arr[idx] = arr[idx] * -1;
		}
	}
	return -1;
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=32Ll35mhWg0
	// LEETCODE LINK: https://leetcode.com/problems/find-the-duplicate-number/
	//*********************************
	vector<int> arr = {1, 3, 4, 2, 2, 2, 2};
	cout << findTheDuplicateNumber(arr) << endl;
}