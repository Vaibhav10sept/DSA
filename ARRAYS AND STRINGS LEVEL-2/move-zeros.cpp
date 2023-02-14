#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &arr) {
	int j = 0;
	// move all the nonzero elements advance
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] != 0) {
			arr[j++] = arr[i];
		}
	}
	for (; j < arr.size(); j++) {
		arr[j] = 0;
	}
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=VGDHph1k0tQ&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=60
	// LEETCODE LINK: NOT FOUND
	//*********************************
	vector<int> arr = {0, 1, 0, 3, 12};
	// string str = "00000";
	moveZeroes(arr);
	for (auto ele : arr) cout << ele << " ";
}