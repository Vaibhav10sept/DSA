#include <bits/stdc++.h>
using namespace std;

void combinationSumBacktracking(vector<int> arr, int idx, int sum, vector<int> ans, vector<vector<int>> &res, int target) {
	if (idx >= arr.size() or sum > target) {
		return;
	}
	if (target == sum) {
		res.push_back(ans);
		return;
	}
	//bc ends

	// recursive calls
	//IMPORTANT NOTE: the diff of calls between "backtracking-subsets" and "backtracking-combination-sum"

	//recursive call --> include
	ans.push_back(arr[idx]);
	// NOTICE here is below call we are not doing "idx+1" but in backtracking-subsets we are doing "idx+1"
	// we are pasing "idx" not "idx+1" iski vajah se repetiition(duplicacy aaegi) kyoki ham ek element ko ek se jyada baar use kr skte h is problem me to achieve the target
	combinationSumBacktracking(arr, idx, sum + arr[idx], ans, res, target);

	//backtrack
	ans.pop_back();

	//recursive call --> not include arr[idx]
	combinationSumBacktracking(arr, idx + 1, sum, ans, res, target);
}

vector<vector<int>> combinationSum(vector<int>& arr, int target) {
	vector<vector<int>> res;
	vector<int> ans;

	combinationSumBacktracking(arr, 0, 0, ans, res, target);
	return res;
}

int main() {
	/*********************************
	STRONG NOTE: there is DP problem "coin change combination" which given the no of possible ways
	             in this problem(backtracking) you have to print those possible ways.
	VIDEO LINK: https://www.youtube.com/watch?v=GBKI9VSKdGg
	LEETCODE LINK: https://leetcode.com/problems/subsets/
	*********************************/
	vector<int> candidates = {1, 3, 4, 5};
	int target = 7;
	vector<vector<int>> ans = combinationSum(candidates, target);
	for (auto vec : ans) {
		for (auto ele : vec) {
			cout << ele << " ";
		}
		cout << endl;
	}
}