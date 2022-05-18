#include <bits/stdc++.h>
using namespace std;

int maxNoOfKSumPairsSpaceEfficient(vector<int> arr, int k) {
	sort(arr.begin(), arr.end());
	int i = 0;
	int j = arr.size() - 1;
	int ans = 0;
	while (i < j) {
		int sum = arr[i] + arr[j];
		if (sum > k) {
			j--;
		}
		else if (sum < k) {
			i++;
		}
		else { //sum == k, we got the ans increment ans;
			ans++;
			i++;
			j--;
		}
	}
	return ans;
}

int main() {
	/*
	SPACE: O(1)
	TIME: O(logn)
	LEETCODE LINK: https://leetcode.com/problems/max-number-of-k-sum-pairs/
	VIDEO LINK: https://www.youtube.com/watch?v=FevSHchkCeo
	*/
	vector<int> arr = {1, 2, 3, 4};
	int k = 5;
	cout << maxNoOfKSumPairsSpaceEfficient(arr, k);
}