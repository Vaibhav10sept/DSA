#include <bits/stdc++.h>
using namespace std;

void combinationSum2Backtracking(vector<int> arr, int idx, int target, vector<int> ans, vector<vector<int>> &res) {
	//BC
	if (target == 0) {
		res.push_back(ans);
		return;
	}
	if (idx >= arr.size()) {
		return;
	}
	//BC ends.


	for (int i = idx; i < arr.size(); i++) {
		//below if is to remove the regenaration of duplicate subsets
		if (i > idx and arr[i] == arr[i - 1]) continue;

		if (arr[i] > target) { //this is for optimization
			break;
			//agr ith hi bda h target se to ith ke age bhi bde hoge as the arr is sorted
		}
		else { //arr[i] <= target
			ans.push_back(arr[i]);
			combinationSum2Backtracking(arr, i + 1, target - arr[i], ans, res);
			//backtrack
			ans.pop_back();
		}
	}
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
	 * PREERQUISITE: backtracking-combination-sum
	 * PREERQUISITE: backtracking-subsets-2
	 * NOTE: here, the only diff from "backtracking-combination-sum" is the result should be unique
	 * NOTE: there is one more diff i.e., each no can be used once, but in backtracking-combination-sum each no can be used multiple times.
	VIDEO LINK: https://www.youtube.com/watch?v=G1fRTGRxXU8
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