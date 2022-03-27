#include <bits/stdc++.h>
using namespace std;

vector<int> findAllDuplicates(vector<int> arr) {
	vector<int> ans;

	for (int i = 0; i < arr.size(); i++) {
		int idx = abs(arr[i]) - 1;
		int val = arr[idx];

		if (val < 0) {
			ans.push_back(idx + 1);
		}
		else {
			arr[idx] = arr[idx] * -1;
		}
	}
	return ans;
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=YoPx8sG_a7E&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=47
	// QUESTION:
	// 1. Given an integer array nums of length n where all the integers of nums are in the range [1, n].
	// 2. Each integer appears once or twice, return an array of all the integers that appears twice.
	// 3. You must write an algorithm that runs in O(n) time and uses only constant extra space.
	//*********************************
	vector<int> arr = {4, 3, 2, 7, 8, 2, 3, 1};

	vector<int> res = findAllDuplicates(arr);
	for (auto ele : res) cout << ele << " ";
}