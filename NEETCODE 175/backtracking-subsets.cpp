#include <bits/stdc++.h>
using namespace std;

void printSubsetsBacktracking(vector<int> arr, int idx, vector<int> ans, vector<vector<int>> &res ) {
	if (idx >= arr.size()) {
		res.push_back(ans);
		return;
	}

	ans.push_back(arr[idx]);
	printSubsetsBacktracking(arr, idx + 1, ans, res);

	//backtrack, for not including vali call
	ans.pop_back();
	printSubsetsBacktracking(arr, idx + 1, ans, res);

}

vector<vector<int>> printSubsets(vector<int> arr) {
	vector<vector<int>> res;
	vector<int> ans;
	printSubsetsBacktracking(arr, 0, ans, res);
	return res;
}

int main() {
	/*********************************
	 * NOTE: a recusive solution "print subsets of an array" is also present
	 *       this one is the backtracking solution
	VIDEO LINK:
	LEETCODE LINK: https://leetcode.com/problems/subsets/
	*********************************/
	vector<int> arr = {1, 2, 2};
	vector<vector<int>> ans = printSubsets(arr);
	for (auto vec : ans) {
		for (auto ele : vec) {
			cout << ele << " ";
		}
		cout << endl;
	}
}