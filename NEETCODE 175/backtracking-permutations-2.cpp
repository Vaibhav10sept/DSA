#include <bits/stdc++.h>
using namespace std;

void permutationsBacktracking(vector<int> arr, int idx, vector<int> ans, set<vector<int>> &res, vector<bool> &visited) {
	// WV recommended
	if (idx == arr.size()) {
		res.insert(ans);
		return;
	}

	for (int i = 0 ; i < arr.size(); i++) {
		if (visited[i] == false) {
			ans[i] = arr[idx];
			visited[i] = true;
			permutationsBacktracking(arr, idx + 1, ans, res, visited);

			//backtrack
			visited[i] = false;
		}
	}
}

vector<vector<int>> permutations(vector<int>& arr) {
	set<vector<int>> res;
	vector<int> ans(arr.size(), 0);
	vector<bool> visited(arr.size(), false);

	permutationsBacktracking(arr, 0, ans, res, visited);

	vector<vector<int>> returnRes;
	for (auto vec : res) {
		returnRes.push_back(vec);
	}
	return returnRes;
}

int main() {
	/*********************************
	 * NOTE: I wrote this code from the prerequisite(below)
	STRONG PREQ: backtracking-permutations
	VIDEO LINK: https://www.youtube.com/watch?v=QKkHCS5bq0I
	LEETCODE LINK: https://leetcode.com/problems/permutations-ii/description/
	*********************************/
	vector<int> arr = {1, 1, 2};
	vector<vector<int>> ans = permutations(arr);
	for (auto vec : ans) {
		for (auto ele : vec) {
			cout << ele << " ";
		}
		cout << endl;
	}
}