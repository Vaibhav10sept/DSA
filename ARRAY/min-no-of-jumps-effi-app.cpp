#include <bits/stdc++.h>
using namespace std;

int minNoOfJumps(vector<int> &arr) {
	//edge cases
	if (arr.size() <= 1) return 0;
	if (arr[0] == 0) return -1;

	//WV highly recommended
	int jumps = 1;
	int maxReach = arr[0];
	int steps = arr[0];

	for (int i = 1; i < arr.size(); i++) {
		if (i == arr.size() - 1) return jumps;

		maxReach = max(maxReach, i + arr[i]);
		steps--;

		if (steps == 0) {
			jumps++; //steps ni h to jump kro(think, wv)
			if (i >= maxReach) {
				return -1; //think, wv
			}
			//update kro steps ko using max reach
			steps = maxReach - i; //thinkk, wv
		}
	}

	return -1;
}

int main()
{
	/*
	VIDEO LINK: https://www.youtube.com/watch?v=_6QpiqTw_ew
	QUESTION LINK: https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
	*/
	vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	// vector<int> arr = {1, 4, 3, 2, 6, 7};
	cout << minNoOfJumps(arr);
}