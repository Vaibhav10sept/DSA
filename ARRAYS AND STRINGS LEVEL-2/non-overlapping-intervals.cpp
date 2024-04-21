#include <bits/stdc++.h>
using namespace std;

bool comparator(vector<int> a, vector<int> b) {
	if (a[0] == b[0]) return a[1] < b[1];
	else return a[0] < b[0];
}

int nonOverLappingIntervals(vector<vector<int>> arr) {
	sort(arr.begin(), arr.end(), comparator);

	stack<int> st;
	st.push(arr[0][1]);
	int countOfOverlappingIntervals = 0;

	for (int i = 1; i < arr.size(); i++) {
		vector<int> vec = arr[i];


		if (!st.empty() and vec[0] < st.top()) {
			st.top() = min(st.top(), vec[1]);
			countOfOverlappingIntervals++;
		}
		else {
			st.push(vec[1]);
		}

	}

	return countOfOverlappingIntervals;
}

int main() {
	//*********************************
	// STRONG PREQ: merge intervals
	// NOTE: we use stack here
	// VIDEO LINK: https://www.youtube.com/watch?v=2JzRBPFYbKE
	// LEETCODE LINK: https://leetcode.com/problems/merge-intervals/
	//*********************************
	vector<vector<int>> intervals = {{1, 100}, {11, 22}, {1, 11}, {2, 12}};
	cout << nonOverLappingIntervals(intervals);
}