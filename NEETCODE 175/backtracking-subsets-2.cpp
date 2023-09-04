#include <bits/stdc++.h>
using namespace std;

void subsetsWithoutDuplicatesBacktracking(vector<int> arr, int idx, vector<int> ans, vector<vector<int>> &res, int sum) {
	if (idx >= arr.size()) {
		// res.push_back(ans);
		for (auto ele : ans) cout << ele << " ";
		cout << endl;
		cout << "sum " << sum << endl;
		return;
	}

	//subsets bnane h, to ek call arr[idx] ko include krke hogi or doosri call arr[idx] ko remove krke hogi(backtrack)
	ans.push_back(arr[idx]);
	subsetsWithoutDuplicatesBacktracking(arr, idx + 1, ans, res, sum + arr[idx]);

	//backtrack --> second call after removing the arr[idx]
	ans.pop_back();
	//but here we have to stop the generation of duplicate subsets
	while (idx + 1 < arr.size() and arr[idx] == arr[idx + 1]) {
		idx++;
	}
	// NOTE: arr ko sort kr liya tha
	subsetsWithoutDuplicatesBacktracking(arr, idx + 1, ans, res, sum);
}

vector<vector<int>> subsetsWithoutDuplicates(vector<int>& arr) {
	// WV
	vector<vector<int>> res;
	vector<int> ans;
	//rem. to remove duplicate subsets we are sorting the arr.
	sort(arr.begin(), arr.end());
	subsetsWithoutDuplicatesBacktracking(arr, 0, ans, res, 0);
	return res;
}

int main() {
	/*********************************
	 * SAME QUESTION: backtracking-combination-sum-2
	 * PREERQUISITE: backtracking-subsets
	 * NOTE: in subsets-2 we don't want duplicate subsets
	VIDEO LINK: https://www.youtube.com/watch?v=Vn2v6ajA7U0
	LEETCODE LINK: https://leetcode.com/problems/subsets-ii/
	*********************************/
	vector<int> arr = {2, 5, 2, 1, 2};
	vector<vector<int>> ans = subsetsWithoutDuplicates(arr);
	for (auto vec : ans) {
		for (auto ele : vec) {
			cout << ele << " ";
		}
		cout << endl;
	}
}