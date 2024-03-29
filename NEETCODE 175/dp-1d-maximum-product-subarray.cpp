#include <bits/stdc++.h>
using namespace std;

int maxProductSubarray(vector<int> arr) {
	//claim max product vala subarray ya to starting vala hoga
	//ya ending vala subarray hoga..beech ka subarray nhi ho skta
	//watch video for proof.
	int ans = INT_MIN;
	int currProduct = 1;
	//loop for starting vala subarray.
	for (int i = 0; i < arr.size(); i++) {
		currProduct *= arr[i];
		ans = max(currProduct, ans);
		if (currProduct == 0) {
			currProduct = 1;
		}
	}

	//loop for ending vala subarray
	currProduct = 1;
	for (int i = arr.size() - 1; i >= 0; i--) {
		currProduct *= arr[i];
		ans = max(currProduct, ans);
		if (currProduct == 0) {
			currProduct = 1;
		}
	}
	return ans;
}

int main() {
	//*********************************
	// TOTAL SUBARRAYS: n(n+1)/2
	// LEETCODE: https://leetcode.com/problems/maximum-product-subarray/
	// VIDEO LINK: https://www.youtube.com/watch?v=jzQ-f2uU0UU&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=49
	//*********************************
	vector<int> arr = {6, -3, -10, 0, 2};
	cout << maxProductSubarray(arr);
}