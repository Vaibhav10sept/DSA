#include <bits/stdc++.h>
using namespace std;

void rec(int idx, int target, int count, vector<bool> &visited, int &r,  vector<int> ans, vector<vector<int>> &res) {
	//I WROTE THIS CODE MYSELF, NO VIDEO IS THERE
	if (target < 0) return;
	if (target == 0 and count == r) {
		res.push_back(ans);
		return;
	}
	if (idx >= visited.size()) return;


	for (int i = idx; i < visited.size(); i++) {
		if (visited[i] == false) {
			ans.push_back(i);
			rec(i + 1, target - i, count + 1, visited, r, ans, res);
			//backtrack
			ans.pop_back();
		}
	}
}


vector<vector<int>> combinationSum3(int r, int target) {
	vector<bool> visited(10, false);
	vector<vector<int>> res;
	vector<int> ans;

	rec(1, target, 0, visited, r, ans, res);

	return res;
}

int main() {
	/**************************************************
	 * PREREQUISITE: print combination ncr (some what similar code pattern)
	//I WROTE THIS CODE MYSELF, NO VIDEO IS THERE
	VIDEO LINK:
	LEETCODE LINK: https://leetcode.com/problems/combination-sum-iii/description/
	*********************************/
	int r = 3;
	int target = 9;

	vector<vector<int>> ans = combinationSum3(r, target);
	for (auto vec : ans) {
		for (auto ele : vec) {
			cout << ele << " ";
		}
		cout << endl;
	}
}