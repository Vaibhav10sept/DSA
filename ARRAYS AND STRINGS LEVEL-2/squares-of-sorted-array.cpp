#include <bits/stdc++.h>
using namespace std;

vector<int> squaresOfSortedArray(vector<int> arr) {
	vector<int> ans(arr.size());
	int i = 0;
	int j = arr.size() - 1;
	int k = ans.size() - 1; //iterate the ans array from end.

	while (i < j) {
		if (arr[i] * arr[i] > arr[j] * arr[j]) {
			ans[k--] = arr[i] * arr[i];
			i++;
		}
		else { //pow(arr[i],2) < pow(arr[j],2)
			ans[k--] = arr[j] * arr[j];
			j--;
		}
	}
	return ans;
}

int main() {
	//*********************************
	// NOTE: two pointer approach is used here
	// https: https://www.youtube.com/watch?v=u3A64HQq_Dw&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=4
	// QUESTION:
	// 1. Given an integer array 'nums' sorted in increasing order.
	// 2. Return an array of the squares of each number sorted in increasing order.
	//*********************************
	vector<int> nums = { -6 , -2, -1, 0 , 1, 4, 5, 7 , 9};
	vector<int> ans = squaresOfSortedArray(nums);
	for (auto ele : ans) cout << ele << " ";
}