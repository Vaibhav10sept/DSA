#include <bits/stdc++.h>
using namespace std;

void permutationsBacktracking(vector<int> arr, int idx, vector<int> ans, vector<vector<int>> &res) {
	// WV recommended
	if (idx == arr.size()) {
		res.push_back(ans);
		return;
	}

	for (int i = 0 ; i < arr.size(); i++) {
		if (ans[i] == -1) {
			ans[i] = arr[idx];
			permutationsBacktracking(arr, idx + 1, ans, res);

			//backtrack(wv, cs, think)
			ans[i] = -1;
		}
	}
}

vector<vector<int>> permutations(vector<int>& arr) {
	vector<vector<int>> res;
	vector<int> ans(arr.size(), -1);

	permutationsBacktracking(arr, 0, ans, res);
	return res;
}

int main() {
	/*********************************
	STRONG NOTE: there is a recursive problem "print permutations"
	VIDEO LINK: https://www.youtube.com/watch?v=QKkHCS5bq0I
	LEETCODE LINK: https://leetcode.com/problems/permutations/
	*********************************/
	vector<int> arr = {1, 2, 3};
	vector<vector<int>> ans = permutations(arr);
	for (auto vec : ans) {
		for (auto ele : vec) {
			cout << ele << " ";
		}
		cout << endl;
	}
}