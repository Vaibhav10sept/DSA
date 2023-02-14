#include <bits/stdc++.h>
using namespace std;

void combinationSum2Backtracking(vector<int> arr, int idx, int target, vector<int> ans, vector<vector<int>> &res) {
	//BC
	if (idx >= arr.size()) {
		if (target == 0) {
			res.push_back(ans);
		}
		return;
	}
	//BC ends.

	//subsets bnane h, to ek call arr[idx] ko include krke hogi or doosri call arr[idx] ko remove krke hogi(backtrack)
	ans.push_back(arr[idx]);
	combinationSum2Backtracking(arr, idx + 1, target - arr[idx], ans, res);

	//backtrack --> second call after removing the arr[idx]
	ans.pop_back();
	//but here we have to stop the generation of duplicate subsets
	while (idx + 1 < arr.size() and arr[idx] == arr[idx + 1]) {
		idx++;
	}
	// NOTE: arr ko sort kr liya tha
	// second call --> arr[idx] ko remove krke or duplicacy ko hata ke kri h
	combinationSum2Backtracking(arr, idx + 1, target, ans, res);
}

vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
	vector<vector<int>> res;
	vector<int> ans;
	sort(arr.begin(), arr.end());

	combinationSum2Backtracking(arr, 0, target, ans, res);

	return res;
}

int main() {
	/*********************************
	 * NOTE: this solution is giving TLE in leetcode. there is a optimized solution also check that.
	 * PREERQUISITE: backtracking-combination-sum
	 * PREERQUISITE: backtracking-subsets-2
	 * NOTE: here, the only diff from "backtracking-combination-sum" is the result should be unique
	 * NOTE: there is one more diff i.e., each no can be used once, but in backtracking-combination-sum each no can be used multiple times.
	VIDEO LINK: https://www.youtube.com/watch?v=Vn2v6ajA7U0
	LEETCODE LINK: https://leetcode.com/problems/combination-sum-ii/
	*********************************/
	vector<int> candidates = {2, 5, 2, 1, 2};
	int target = 5;

	vector<vector<int>> ans = combinationSum2(candidates, target);
	for (auto vec : ans) {
		for (auto ele : vec) {
			cout << ele << " ";
		}
		cout << endl;
	}
}