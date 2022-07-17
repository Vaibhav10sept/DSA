#include <bits/stdc++.h>
using namespace std;


int wiggleMaxLength(vector<int>& arr) {
	//edge case
	if (arr.size() <= 1) return arr.size();

	int up = 1;
	int down = 1;

	for (int i = 0; i < arr.size() - 1; i++) {
		if (arr[i] < arr[i + 1]) { //uphill case
			up = down + 1;
		}
		else if (arr[i] > arr[i + 1]) { //downhill case
			down = up + 1;
		}
	}
	return max(up, down);
}

int main() {
	/*
	NOTE: daily challenge question
	NOTE: A subarray or substring will always be contiguous, but a subsequence need not be contiguous.
	VIDEO LINK: https://www.youtube.com/watch?v=iJIAPtd9Z9s
	LEETCODE: https://leetcode.com/problems/wiggle-subsequence/
	*/
	vector<int> arr = {1, 7, 4, 9, 2, 5};
	cout << wiggleMaxLength(arr);

}



