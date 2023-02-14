#include <bits/stdc++.h>
using namespace std;

void combinationSumBacktracking(vector<int> arr, long long idx, long long sum, vector<long long> ans, int target, int &minNoOfCoins) {
	if (idx >= arr.size() or sum > target) {
		return;
	}
	if (target == sum) {
		minNoOfCoins = min(minNoOfCoins, (int)ans.size());
		return;
	}
	//bc ends

	// recursive calls
	//IMPORTANT NOTE: the diff of calls between "backtracking-subsets" and "backtracking-combination-sum"

	//recursive call --> include
	ans.push_back(arr[idx]);
	// NOTICE here is below call we are not doing "idx+1" but in backtracking-subsets we are doing "idx+1"
	// we are pasing "idx" not "idx+1" iski vajah se repetiition(duplicacy aaegi) kyoki ham ek element ko ek se jyada baar use kr skte h is problem me to achieve the target
	combinationSumBacktracking(arr, idx, sum + arr[idx], ans,  target, minNoOfCoins);

	//backtrack
	ans.pop_back();

	//recursive call --> not include arr[idx]
	combinationSumBacktracking(arr, idx + 1, sum, ans, target, minNoOfCoins);
}

int combinationSum(vector<int>& arr, int target) {
	vector<long long> ans;
	int minNoOfCoins = INT_MAX;

	combinationSumBacktracking(arr, 0, 0, ans, target, minNoOfCoins);
	if (minNoOfCoins == INT_MAX) return -1;
	return minNoOfCoins;
}

int main() {
	/*********************************
	 * NOTE: a dp solution is also there, which won't give you TLE.
	 * PREREQUISITE: coin-change-combination-resursive( just a slight change in code will give you the solution for this problem)
	STRONG NOTE: there is DP problem "coin change combination" which given the no of possible ways
	             in this problem(backtracking) you have to print those possible ways.
	VIDEO LINK: https://www.youtube.com/watch?v=H9bfqozjoqs
	LEETCODE LINK: https://leetcode.com/problems/coin-change/
	*********************************/
	vector<int> candidates = {1, 3, 4, 5};
	int target = 7;
	cout << combinationSum(candidates, target);

}