#include<bits/stdc++.h>
using namespace std;

int LongestSubarrayOfSumkNegativeNumbers(vector<int> arr, int k) {
	//This is not sliding window question
	//we use map here.
	//this works for negative numbers as well
	//but sliding window approach is limited to positive numbers only.
	int n = arr.size();
	// unordered_map 'mp' implemented
	// as hash table
	unordered_map<int, int> mp;
	int sum = 0, maxLen = 0;

	// traverse the given array
	for (int i = 0; i < n; i++) {

		// accumulate sum
		sum += arr[i];

		// when subarray starts from index '0'
		if (sum == k)
			maxLen = i + 1;

		// make an entry for 'sum' if it is
		// not present in 'mp'
		if (mp.find(sum) == mp.end())
			//put it in mp.
			mp[sum] = i;

		// check if 'sum-k' is present in 'mp'
		// or not
		if (mp.find(sum - k) != mp.end()) {

			// update maxLength
			if (maxLen < (i - mp[sum - k]))
				maxLen = i - mp[sum - k];
		}
	}

	// required maximum length
	return maxLen;
}

int main() {
	/*
	NOTE: use map here.
	LINK: https://www.geeksforgeeks.org/longest-sub-array-sum-k/
	VIDEO LINK: https://www.youtube.com/watch?v=cyu_nuW5utA&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=8
	OUTPUT: size of longest subarray with sum "k".
	*/
	vector<int> arr = { -5, 8, -14, 2, 4, 12};
	int k = -5;
	cout << LongestSubarrayOfSumkNegativeNumbers(arr, k);
}