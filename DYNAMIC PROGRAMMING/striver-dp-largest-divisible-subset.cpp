#include <bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubsets(vector<int> arr) {
	//Please watch attached video(link) for more understanding.
	//we can sort because in finding the longest subset order doesn't matter, but in subsequence order matter, to agr subsequence find krna hota to hm sort nhi kr rhe hote.
	sort(arr.begin(), arr.end()); //logic: WV

	int n = arr.size();
	int maxLenghtLongestIncresingSubsequence = 0;
	vector<int> hash(n);
	for (int i = 0; i < hash.size(); i++) hash[i] = i;
	vector<int> dp(n);
	dp[0] = 1; //initialization --> means one size ka subarray to apne app me longest divisible subset hota h(think), islie 1 store krege coz dp me hm lenght store kr rhe h
	//NOTE: an index in dp defines, the lenght of divisible subset ending at that arr[index].
	int lastIndex = 0; //for print the longest incrasing subsequence

	for (int i = 1; i < dp.size(); i++) {
		int max = 0;

		for (int j = 0; j < i; j++) {
			if (arr[i] % arr[j] == 0) { //note: arr is sorted so arr[i] > arr[j]
				if (dp[j] > max) {
					max = dp[j];
					hash[i] = j;
				}
			}
		}
		dp[i] = max + 1; //+1 coz, dp me len store h, to +1 kregena uss element ke lie(WV)

		if (dp[i] > maxLenghtLongestIncresingSubsequence) {
			//logic: is question me dp ke end ya start me answer nhi hoga, coz dp me len store h lon inc subsequence ki to dp me jo sbse jyada value hogi vohi hmara answer hoga.
			maxLenghtLongestIncresingSubsequence = dp[i];
			lastIndex = i; //for print the longest incrasing subsequence
		}
	}

	//for printing the longest increasing subsequence
	vector<int> printing;
	printing.push_back(arr[lastIndex]);
	while (lastIndex != hash[lastIndex]) {
		lastIndex = hash[lastIndex];
		printing.push_back(arr[lastIndex]);
	}
	reverse(printing.begin(), printing.end());
	return printing;
}

int main()
{
	/***************************
	 * NOTE: subset is same as subsequence bss isme order matter nhi krta, subsequence are in order whereas subset may not be in order.
	SUBSET VS SUBSEQUENCE: A subsequence maintain relative ordering of elements but may or may not be a contiguous part of an array. For a sequence of size n, we can have 2^n-1 non-empty sub-sequences in total. A subset MAY NOT maintain relative ordering of elements and can or cannot be a contiguous part of an array.
	SAME CODE PATTERN AS IN: print longest increasing subsequence
	STRONG PREREQUISITE: print longest increasing subsequence
	QUESTION: https://leetcode.com/problems/largest-divisible-subset/
	VIDEO: https://www.youtube.com/watch?v=gDuZwBW9VvM&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=46
	/**************************************************/
	vector<int> arr = {1, 2, 4, 8};
	// cout << "fsd";
	vector<int> ans = largestDivisibleSubsets(arr);
	for (auto ele : ans) cout << ele << " ";
	cout << endl;
}