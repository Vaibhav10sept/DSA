#include <bits/stdc++.h>
using namespace std;

vector<int> productOfArrayExceptItself(vector<int> arr) {
	vector<int> rightProduct(arr.size());
	vector<int> ans(arr.size());

	// filling up the right product array
	rightProduct[arr.size() - 1] = arr[arr.size() - 1];
	for (int i = arr.size() - 2; i >= 0; i--) {
		rightProduct[i] = rightProduct[i + 1] * arr[i];
	}

	int leftProd = 1;
	for (int i = 0; i < ans.size(); i++) {
		if (i == 0) { //first index
			ans[i] = rightProduct[i + 1];
		}
		else if (i == ans.size() - 1) { //last index
			ans[i] = leftProd;
		}
		else { //other than first and last index
			ans[i] = leftProd * rightProduct[i + 1];
		}
		leftProd *= arr[i];
	}

	return ans;
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=UBkpyXgx0g0&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=9
	// QUESTION:
	// 1. Given an integer array of size 'n'.
	// 2. Return an array answer such that answer[i] is equal to the product of all the elements of arr except arr[i].
	// 3. The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
	//*********************************
	vector<int> arr = {1, 2, 2, 3, 0, 1, 2};

	vector<int> ans = productOfArrayExceptItself(arr);
	for (auto ele : ans) cout << ele << " ";
}