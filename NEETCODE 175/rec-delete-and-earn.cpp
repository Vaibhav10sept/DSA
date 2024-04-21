#include <bits/stdc++.h>
using namespace std;

int rec(int ind, vector<int> &arr, vector<int> &memo) {
	if (ind >= arr.size()) return 0;
	//BC ends

	if (memo[ind] != -1) return memo[ind]; //memoization
	int i = ind;
	int val = arr[ind];
	int allValueSum = 0;
	while (ind < arr.size() and arr[ind] == val) {
		allValueSum += arr[ind];
		ind++;
	}

	//exclude all arr[ind] + 1;
	int index = ind;
	int nextVal = val + 1;
	while (index < arr.size() and arr[index] == nextVal) {
		index++;
	}

	//make recursive call using pick and not pick strategy
	int pick = allValueSum + rec(index, arr, memo);
	int notPick = rec(ind, arr, memo);

	return memo[i] = max(pick, notPick);
}
int deleteAndEarn(vector<int>& arr) {
	sort(arr.begin(), arr.end());
	vector<int> memo(20001, -1);
	return rec(0, arr, memo);
}
int main()
{
	/***************************
	PREREQUISITE: max sum non adjacent elements(recursive)
	NOTE: a DP solution is also there.
	NOTE: I wrote this code after going through a solution of leetcode(below link)
	video link: https://leetcode.com/problems/delete-and-earn/solutions/1820279/c-detailed-explanation-w-recursion-to-memoziation-understand-concept/
	LEETCODE: https://leetcode.com/problems/delete-and-earn/description/
	//********************************/
	vector<int> arr = {3, 4, 2};
	cout << deleteAndEarn(arr);
}