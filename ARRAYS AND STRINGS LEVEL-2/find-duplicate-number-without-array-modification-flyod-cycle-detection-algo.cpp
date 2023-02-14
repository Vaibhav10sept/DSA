#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& arr) {
	/*
	watch video recommended
	NOTE: we used flyod cycle detection algorithm here
	*/
	int slow = 0;
	int fast = 0;

	while (true) { //true islie kyoki hme pta hai while break hoga gauranteed
		slow = arr[slow];
		fast = arr[arr[fast]];
		if (slow == fast) {
			break;
		}
	}

	//find the intersection point
	int slow2 = 0;
	while (true) {
		slow = arr[slow];
		slow2 = arr[slow2];
		if (slow == slow2) {
			return slow; //this is actual value, not index
		}
	}
}

int main() {
	//*********************************
	// LEETCODE LINK: https://leetcode.com/problems/find-the-duplicate-number/
	//*********************************
	vector<int> arr = {1, 3, 4, 2, 2, 2, 2};
	cout << findDuplicate(arr) << endl;
}