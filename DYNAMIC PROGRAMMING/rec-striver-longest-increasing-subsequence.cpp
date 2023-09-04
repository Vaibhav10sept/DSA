#include <bits/stdc++.h>
using namespace std;

int rec(int ind, int prevInd, vector<int> arr) {
	if (ind == arr.size()) return 0; //we are returning the lenght of longest increasing subsequence.

	//base case ends
	//this is based on take and not take pattern
	int notTake = 0 + rec(ind + 1, prevInd, arr);

	//take case only happens when the arr[ind] > arr[prevInd] or starting call me hm -1 pass krre to use consider kro
	int take = INT_MIN;
	if (prevInd == -1 or arr[ind] > arr[prevInd]) { //if this condition hits then only take case will happen
		take = 1 + rec(ind + 1, ind, arr);
	}

	return max(take, notTake);
}

int longestIncreasingSubsequence(vector<int> arr) {
	//Please watch attached video(link) for more understanding.
	return rec(0, -1, arr);
}

int main()
{
	/***************************
	NOTE: a dp solution also there, this will not submit on leetcode
	// LEETCODE: https://leetcode.com/problems/longest-increasing-subsequence/
	// video link: https://www.youtube.com/watch?v=ekcwMsSIzVc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=43
	//**************************************************/
	vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
	cout << longestIncreasingSubsequence(arr);
}