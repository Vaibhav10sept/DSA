#include <bits/stdc++.h>
using namespace std;

int targetSumRecursiveMemoized(int idx, vector<int> arr, int target, map<pair<int, int>, int> &memo) {
	//BC
	if (idx == arr.size()) {
		if (target == 0) {
			return 1;
		}
		else return 0;
	}

	//memoization check
	if (memo.find({idx, target}) != memo.end()) { //found
		return memo[ {idx, target}];
	}

	//recursive calls
	//LOGIC: ek call hm arr[idx] ko add krke krege or doosri call hm arr[idx] ko substract krke krege
	//or dono calls ka jo ans aega uska sum return kr dege (think, WV)
	memo[ {idx, target}] = targetSumRecursiveMemoized(idx + 1, arr, target + arr[idx], memo) + targetSumRecursiveMemoized(idx + 1, arr, target - arr[idx], memo);
	return memo[ {idx, target}];
}

int targetSum(vector<int> arr, int target) {
	map<pair<int, int>, int> memo; //pair --> index,total  VS no of ways
	//this map is used for memoization
	return targetSumRecursiveMemoized(0, arr, target, memo);
}

int main()
{
	//***************************
	// NOTE: this recusive solution will give you TLE, other solution are also there, search
	// NOTE: there is a memoized and dp solution also.
	//       you can search it using ctrl + p.
	// VIDEO LINK: https://leetcode.com/problems/target-sum/
	// LEETCODE LINK: https://www.youtube.com/watch?v=g0npyaQtAQM
	//**************************************************
	vector<int> arr = {1, 1, 1, 1, 1};
	int target = 3;

	cout << targetSum(arr, target);
}