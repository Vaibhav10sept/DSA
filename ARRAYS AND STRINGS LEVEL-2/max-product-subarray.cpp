#include <bits/stdc++.h>
using namespace std;

int maxProductSubarray(vector<int> arr) {
	//claim max product vala subarray ya to starting vala hoga
	//ya ending vala subarray hoga..beech ka subarray nhi ho skta

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
	//claim max product vala subarray ya to starting vala hoga
	//ya ending vala subarray hoga..beech ka subarray nhi ho skta
	//NOTE: watch video recommended for proof of the above claim
	// VIDEO LINK: https://www.youtube.com/watch?v=jzQ-f2uU0UU&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=49
	// QUESTION:
	//*********************************
	vector<int> arr = { -2, -3, 4, 5, 6, 0, 50};
	cout << maxProductSubarray(arr);
}