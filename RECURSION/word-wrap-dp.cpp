#include <bits/stdc++.h>
using namespace std;

int solveWordWrap(vector<int>nums, int k)
{
	int n = nums.size();
	vector<int> cur(k + 1, 0), ahead(k + 1, 0);

	for (int index = n - 1; index >= 0; index--) {
		for (int spaces_left = 0; spaces_left <= k; spaces_left++) {
			if (spaces_left == k) {
				// new-line
				cur[spaces_left] = ahead[k - nums[index]];
			} else if (nums[index] + 1 > spaces_left) {
				// next-line
				cur[spaces_left] = ahead[k - nums[index]] + spaces_left * spaces_left;
			} else {
				cur[spaces_left] = min(ahead[spaces_left - nums[index] - 1],
				                       ahead[k - nums[index]] + spaces_left * spaces_left);
			}
		}

		ahead = cur;
	}

	return ahead[k];
}


int main()
{
	/*******************************
	 * NOTE: this code is copied from gfg solution.
	 * PREREQUISITE: memo word wrap
	 QUESTION LINK: https://practice.geeksforgeeks.org/problems/word-wrap1646/1
	 * *************************************/
	vector<int> arr = {3, 2, 2, 5};
	int k = 6;
	cout << "result " << solveWordWrap(arr, k);
}