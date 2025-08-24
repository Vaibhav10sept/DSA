#include <bits/stdc++.h>
using namespace std;

void combinationSum2Backtracking(vector<int> arr, int idx, vector<int> ans, vector<vector<int>> &res, int target) {
	//EXACTLY SAME CODE AS IN: backtracking-subsets-2
	if (target < 0) return; //really important BC agr hata doge to submit ni hoga
	if (target == 0) {
		res.push_back(ans);
		return;
	}
	if (idx >= arr.size()) {
		return;
	}
	//BC ends

	//subsets bnane h, to ek call arr[idx] ko include krke hogi or doosri call arr[idx] ko remove krke hogi(backtrack)
	ans.push_back(arr[idx]);

	combinationSum2Backtracking(arr, idx + 1, ans, res, target - arr[idx]);

	//backtrack --> second call after removing the arr[idx]
	ans.pop_back();
	//but here we have to stop the generation of duplicate subsets
	//same logic is used in backtracking subset sum 2
	while (idx + 1 < arr.size() and arr[idx] == arr[idx + 1]) {
		idx++;
	}
	// NOTE: arr ko sort kr liya tha
	combinationSum2Backtracking(arr, idx + 1, ans, res, target);
}

vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
	vector<vector<int>> res;
	vector<int> ans;
	sort(arr.begin(), arr.end());

	combinationSum2Backtracking(arr, 0, ans, res, target);

	return res;
}

int main() {
	/*********************************
	 * 	EXACTLY SAME CODE AS IN: backtracking-subsets-2
	 * STRONG PREERQUISITE: backtracking-subsets-2
	 * NOTE: here, the only diff from "backtracking-combination-sum" is the result should be unique
	 * NOTE: there is one more diff i.e., each number can be used once, but in backtracking-combination-sum each number can be used multiple times.
	VIDEO LINK:
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