#include <bits/stdc++.h>
using namespace std;

// THIS CODE IS NOT WORKING, there is a working code

int recHelper(vector<int> arr, int i) {
	if (i >= arr.size()) return 0;

	int minJumps = INT_MAX;
	int steps = arr[i];
	for (int s = 1; s <= steps; s++) {
		minJumps = min(minJumps, recHelper(arr, i + s));
	}
	return 1 + minJumps;
}

int minNoOfJumps(vector<int> &arr) {
	if (arr[0] == 0) return -1;
	else if (arr.size() == 1) return 1;
	else return recHelper(arr, 0);
}

int main()
{
	/*
	// THIS CODE IS NOT WORKING, there is a working code
	VIDEO LINK: https://www.youtube.com/watch?v=_6QpiqTw_ew
	QUESTION LINK: https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
	*/
	// vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	vector<int> arr = {1, 4, 3, 2, 6, 7};
	cout << minNoOfJumps(arr);
}