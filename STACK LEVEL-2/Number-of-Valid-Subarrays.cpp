#include<bits/stdc++.h>
using namespace std;

int numberOfValidSubarrays(vector<int> arr) {
	int noOfSubarray = 0;
	int n = arr.size();
	//create the array of index of next smaller on right
	vector<int> nextSmallerIndexRight(n);
	stack<int> st;
	//travel from right to left
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() and arr[st.top()] >= arr[i]) {
			st.pop();
		}
		if (st.empty()) nextSmallerIndexRight[i] = INT_MAX;
		else nextSmallerIndexRight[i] = st.top();

		st.push(i);
	}

	for (int i = 0; i < n; i++) {
		if (nextSmallerIndexRight[i] == INT_MAX) {
			noOfSubarray += n - i;
		}
		else {
			noOfSubarray += nextSmallerIndexRight[i] - i;
		}
	}
	return noOfSubarray;
}

int main() {
	/*
	NOTE: this question is paid in leetcode
	PREREQUISITE: next smaller index to the right.
	VIDEO LINK: https://www.youtube.com/watch?v=P0Fz-ZIVY5k&list=PL-Jc9J83PIiE1_SifBEWRsD-fzxrvkja9&index=23
	LEETCODE LINK:
	*/
	vector<int> arr = {1, 4, 2, 5, 3};
	cout << numberOfValidSubarrays(arr);
}