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
		slow = arr[slow]; //move by one step
		fast = arr[arr[fast]]; //move by two steps
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

int main()
{
	/*
	NOTE: we use flyod cycle detection algorithm here
	NOTE: there is no linked list as such here, we are only using an algo of linked list
	PREREQUISITE: detect cycle and find intersection node in linked list
	VIDEO LINK: https://www.youtube.com/watch?v=wjYnzkAhcNk
	LEETCODE LINK: https://leetcode.com/problems/find-the-duplicate-number/
	*/
	vector<int> arr = {1, 3, 4, 2, 2};
	cout << findDuplicate(arr);
}