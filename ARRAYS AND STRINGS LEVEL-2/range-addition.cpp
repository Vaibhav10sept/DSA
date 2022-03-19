#include <bits/stdc++.h>
using namespace std;

vector<int> rangeAddition(int n, vector<vector<int>> queries) {
	vector<int> res(n, 0);
	for (vector<int> vec : queries) {
		int low = vec[0];
		int high = vec[1];
		int add = vec[2];

		res[low] += add;

		if (high + 1 < res.size()) {
			res[high + 1] -= add;
		}
	}

	// presum vali technique use krege
	for (int i = 1; i < res.size(); i++) {
		res[i] += res[i - 1];
	}

	return res;
}

int main() {
	//*********************************
	// NOTE: presum array approach is used here
	// https://www.youtube.com/watch?v=fBT0VKkqvtY&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=2
	// QUESTION:
	// 1. Assume you have an array of length 'n' initialized with all 0's and are given 'q' queries to update.
	// 2. Each query is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.
	// 3. Return the modified array after all 'q' queries were executed.
	//*********************************

	int length = 5;
	vector<vector<int>> queries =
	{
		{1,  3,  2},
		{2,  4,  3},
		{0,  2, -2}
	};

	vector<int> ans = rangeAddition(length, queries);
	for (auto ele : ans) cout << ele << " ";
}