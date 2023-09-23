#include <bits/stdc++.h>
using namespace std;

int longestIncreasingPathRecursive(int i, int j, vector<vector<int>> &arr, map<pair<int, int>, int> &memo) {
	//BC
	// if (i<0 or j<0 or i >= arr.size() or j >= arr[0].size()) return 0;
	// if (arr[i][j] <= prev) return 0;
	if (memo.find({i, j}) != memo.end()) return memo[ {i, j}];
	//BC ends

	vector<pair<int, int>> dir{{0, 1}, {1, 0}, { -1, 0}, {0, -1}};
	int ans = 0;
	for (auto x : dir) {
		int a = i + x.first;
		int b = j + x.second;
		if (a >= 0 && a < arr.size() && b >= 0 && b < arr[i].size() && arr[a][b] > arr[i][j]) {
			ans = max(ans, longestIncreasingPathRecursive(a, b, arr, memo));
		}
	}
	return memo[ {i, j}] = ans + 1;
}

int longestIncreasingPath(vector<vector<int>> arr) {
	// WV recommended.
	map < pair<int, int>, int> memo; //pair --> i,j VS length of longest increasing path starting from arrr[i][j]
	int ans = 1;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			memo[ {i, j}] = longestIncreasingPathRecursive(i, j,  arr, memo);
			ans = max(ans, memo[ {i, j}]);
		}
	}

	return ans;
}

int main()
{
	/***************************
	 * NOTE: this will give TLE
	 * recursive(memoized) solution is also there.
	VIDEO LINK: https://www.youtube.com/watch?v=wCc_nd-GiEc
	QUESTION LINK: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
	//**************************************************/
	vector<vector<int>> arr = {{3, 4, 5}, {3, 2, 6}, {2, 2, 1}};

	cout << "result " << longestIncreasingPath(arr);
}