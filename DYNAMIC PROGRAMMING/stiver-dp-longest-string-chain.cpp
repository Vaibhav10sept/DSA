#include <bits/stdc++.h>
using namespace std;

bool comparator(string s1, string s2) { //sort in increasing order of length of string
	return s1.size() < s2.size();
}

bool compare(string str1, string str2) {
	//str1 is always greater in size as string 2, see the calls, note: arr is sorted in terms of string size
	int i = 0; //iterator for str1
	int j = 0; //iterator for str2
	if (str1.size() != str2.size() + 1) return false; //str1 should always be one greater then str2, otherwise return false.

	while (i < str1.size()) {
		if (str1[i] == str2[j]) {
			i++;
			j++;
		}
		else { //coz we are sure that str1.size() + 1 == str2.size()  [WV, THINK, CS]
			i++;
		}
	}

	if (i == str1.size() and j == str2.size()) return true;
	return false;
}

int longestStringChain(vector<string> arr) {
	//Please watch attached video(link) for more understanding.
	//we can sort because in finding the longest subset order doesn't matter, but in subsequence order matter, to agr subsequence find krna hota to hm sort nhi kr rhe hote.
	sort(arr.begin(), arr.end(), comparator); //sort in increasing order of length of string

	int n = arr.size();
	if (n == 1) return 1; //edge case:
	int maxLenghtLongestStringChain = 0;
	vector<int> dp(n);
	dp[0] = 1; //initialization --> means one size ka subarray to apne app me longest string chain hota h(think), islie 1 store krege coz dp me hm lenght store kr rhe h
	//NOTE: an index in dp defines, the lenght of longest string chain ending at that arr[index].

	for (int i = 1; i < dp.size(); i++) {
		int max = 0;

		for (int j = 0; j < i; j++) {
			if (compare(arr[i], arr[j])) { //note: arr is sorted so arr[i] > arr[j] in terms of size
				if (dp[j] > max) {
					max = dp[j];
				}
			}
		}
		dp[i] = max + 1; //+1 coz, dp me len store h, to +1 kregena uss element ke lie(WV)

		if (dp[i] > maxLenghtLongestStringChain) {
			//logic: is question me dp ke end ya start me answer nhi hoga, coz dp me len store kr rhe h to dp me jo sbse jyada value hogi vohi hmara answer hoga.
			maxLenghtLongestStringChain = dp[i];
		}
	}

	return maxLenghtLongestStringChain;
}

int main()
{
	/***************************
	 * NOTE: subset is same as subsequence bss isme order matter nhi krta, subsequence are in order whereas subset may not be in order.
	SUBSET VS SUBSEQUENCE: A subsequence maintain relative ordering of elements but may or may not be a contiguous part of an array. For a sequence of size n, we can have 2^n-1 non-empty sub-sequences in total. A subset MAY NOT maintain relative ordering of elements and can or cannot be a contiguous part of an array.
	SAME CODE PATTERN AS IN: longest increasing subsequence
	STRONG PREREQUISITE: longest increasing subsequence
	QUESTION: https://leetcode.com/problems/longest-string-chain/description/
	VIDEO: https://www.youtube.com/watch?v=YY8iBaYcc4g&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=48
	/**************************************************/
	vector<string> arr = {"a", "b", "ba", "bca", "bda", "bdca"};
	cout << longestStringChain(arr);
}