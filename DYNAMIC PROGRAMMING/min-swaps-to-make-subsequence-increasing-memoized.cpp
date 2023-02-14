#include <bits/stdc++.h>
using namespace std;

int solveMemoized(vector<int> arr1, vector<int> arr2, int idx, bool swapped, vector<vector<int>> &memo) {
	//swapped --> we are not changing the arrays, so swapped ye btaega ki pichle index me swapping hue h ya nhi
	//base case
	if (idx == arr1.size()) { // or idx == arr2.size() does matter both arrays has same size
		return 0;
	}

	if (memo[idx][swapped] != -1) return memo[idx][swapped];

	int ans = INT_MAX;
	int prev1 = arr1[idx - 1];
	int prev2 = arr2[idx - 1];

	if (swapped) { //think, WV
		swap(prev1, prev2);
	}

	if (arr1[idx] > prev1 and arr2[idx] > prev2) {
		//no swap
		ans = solveMemoized(arr1, arr2, idx + 1, false, memo);
	}
	if (arr1[idx] > prev2 and arr2[idx] > prev1) { //see the if clearly, think, WV
		//swap happened
		ans = min(ans, 1 + solveMemoized(arr1, arr2, idx + 1, true, memo)); // + 1 bcoz , swapping hue to count of swapping is incresed by 1
	}

	return memo[idx][swapped] = ans; //ans is the min no of swapping.
}

int minSwapToMakeSubsequenceIncreasing(vector<int> arr1, vector<int> arr2) {
	arr1.insert(arr1.begin(), -1);
	arr2.insert(arr2.begin(), -1);

	int n = arr1.size();
	//1 d vector hue, ache se dekho
	vector<vector<int>> memo(n, vector<int>(2, -1));

	return solveMemoized(arr1, arr2, 1, false, memo);
}

int main()
{
	/***************************
	 * NOTE: this is  a memoized solution, a DP solution is also there
	VIDEO LINK: https://www.youtube.com/watch?v=IeT9Qz_vqHo
	LEETCODE LINK: https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/
	//**************************************************/
	vector<int> nums1 = {0, 3, 5, 8, 9};
	vector<int> nums2 = {2, 1, 4, 6, 9};
	cout << minSwapToMakeSubsequenceIncreasing(nums1, nums2);
}