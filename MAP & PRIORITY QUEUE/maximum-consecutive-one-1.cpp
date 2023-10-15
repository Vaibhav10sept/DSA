#include<bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(vector<int> arr) {
	//this is my code, no video, no solution
	int i = 0;
	int j = 0;
	int ans = INT_MIN;
	int n = arr.size();

	while (j < arr.size()) {
		if (arr[j] == 1) {
			ans = max(ans, j - i + 1);
			j++;
		}
		else { //arr[j] = 0
			while (j < n and arr[j] == 0) j++;
			//now, j is at 1
			i = j;
		}
	}

	return ans == INT_MIN ? 0 : ans;
}

int main() {
	/*
	//this is my code, no video, no solution.
	QUESTION: https://leetcode.com/problems/max-consecutive-ones/description/
	NOTE: sliding windows is used here.
	VIDEO LINK:
	*/
	vector<int> arr = {1, 1, 0, 1, 1, 1};
	cout << "max length " << maxConsecutiveOnes(arr);
}