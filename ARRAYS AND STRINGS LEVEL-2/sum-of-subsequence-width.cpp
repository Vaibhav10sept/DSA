#include <bits/stdc++.h>
using namespace std;

int sumOfSubsequenceWidth(vector<int> arr) {
	//leetcode hard question
	sort(arr.begin(), arr.end());
	long ans = 0;
	long mod = 1000000007;
	int n = arr.size();
	vector<long> pow(n);
	pow[0] = 1;
	//this is pre computation
	for (int i = 1; i < n; i++) {
		pow[i] = (pow[i - 1] * 2) % mod;
	}

	for (int i = 0; i < arr.size(); i++) {
		ans = (ans + ( arr[i] * pow[i]) - (arr[i] * pow[n - i - 1])) % mod;
	}
	return ans;
}

int main() {
	//NOTE:
// Subarray = n*(n+1)/2
// Subseqeunce = (2^n) -1 (non-empty subsequences)
// Subset = 2^n
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=kSo8W6ZGYqw&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=50
	// QUESTION:
// The width of a sequence is the difference between the maximum and minimum elements in the sequence.

// Given an array of integers nums, return the sum of the widths of all the non-empty subsequences of nums. Since the answer may be very large, return it modulo 109 + 7.

// A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
	//*********************************
	vector<int> arr = {2, 1, 3};
	cout << sumOfSubsequenceWidth(arr);
}