#include<bits/stdc++.h>
using namespace std;

int LongestSubarrayOfSumk(vector<int> arr, int k) {
	//This approach won’t work for negative numbers
	int n = arr.size();
	int i = 0, j = 0, sum = 0;
	int ans = INT_MIN;
	while (j < n) {
		sum += arr[j];
		if (sum < k) {

		} else if (sum == k) {
			ans = max(ans, j - i + 1);
		} else if (sum > k) {
			while (sum > k) {
				sum = sum - arr[i];
				i++;
			}
		}
		j++;
	}
	return ans;
}

int main() {
	/*
	NOTE: this is variable size sliding window question.
	VIDEO LINK: https://www.youtube.com/watch?v=cyu_nuW5utA&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=8
	OUTPUT: size of longest subarray with sum "k".
	*/
	vector<int> arr = { 10, 5, 2, 7, 1, 9 };
	int k = 15;
	cout << LongestSubarrayOfSumk(arr, k);
}