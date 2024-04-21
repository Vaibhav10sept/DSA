#include <bits/stdc++.h>
using namespace std;

bool rec(int prevInd, int ind, int jumpSize, vector<int> arr) {
	if (ind >= arr.size()) return true;

	if (prevInd < arr.size() and arr[ind] - arr[prevInd] != jumpSize) return false;
	//rec calls
	return rec(ind, ind + jumpSize, jumpSize, arr) or rec(ind, ind + (jumpSize - 1), jumpSize - 1, arr) or rec(ind, ind + jumpSize + 1, jumpSize + 1 , arr);
}

bool frogJumps(vector<int> arr) {
	int jumpSize = 1;
	if (arr[0] + 1 != arr[1]) return false;
	return rec(0, 1, jumpSize, arr);
}

int main()
{
	/***************************
	VIDEO LINK:
	LEETCODE LINK:
	//**************************************************/
	vector<int> stones = {0, 1, 2, 3, 4, 8, 9, 11};
	if (frogJumps(stones)) cout << "true" << endl;
	else cout << "false" << endl;
}