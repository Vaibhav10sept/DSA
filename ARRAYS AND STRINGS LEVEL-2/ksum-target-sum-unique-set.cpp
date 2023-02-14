#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> TargetSumUniquePair(vector<int> arr, int target , int left) {
	sort(arr.begin(), arr.end());
	vector<vector<int>> ans;

	int n = arr.size();
	int right = n - 1;
	if (n - left < 2) return ans; //edge case
	while (left < right) {
		//this will ensure that the pair are unique(think)(remember)
		if (left != 0 and arr[left - 1] == arr[left]) {
			left++;
			continue;
		}

		//now, there would be 3 cases same as in "target sum pair"
		int sum = arr[left] + arr[right];
		if (target == sum) {
			//pair found
			vector<int> vec = {arr[left], arr[right]};
			ans.push_back(vec);
			left++;
			right--;
		}
		else if (target > sum) {
			left++;
		}
		else { //target < sum
			right--;
		}
	}
	return ans;
}

vector<vector<int>> targetSumUniqueSetHelper(vector<int> arr, int target, int k, int startIndex) {
	if (k == 2) {
		return TargetSumUniquePair(arr, target, startIndex);
	}
	// bc
	int n = arr.size();
	vector<vector<int>> ans;
	if (n - startIndex < k) { //n - startIndex -->  size of array, and if size of array is less than k then return an empty array
		return ans;
	}

	for (int i = startIndex; i <= n - k; i++) {
		//this will ensure that the sets are unique(think)(remember)
		if (i != startIndex and arr[i] == arr[i - 1]) continue;

		int val1 = arr[i];
		int newTarget = target - val1;
		vector<vector<int>> currAns = targetSumUniqueSetHelper(arr, newTarget, k - 1, i + 1);
		//creating the answer by giving the impact of val1
		for (vector<int> vec : currAns) {
			vec.push_back(val1);
			ans.push_back(vec);
		}
	}

	return ans;
}

vector<vector<int>> targetSumUniqueSet(vector<int> arr, int target, int k) {
	int n = arr.size();
	vector<vector<int>> res;
	if (n < k) {
		return res;
	}
	return targetSumUniqueSetHelper(arr, target, k, 0);
}



int main() {
	//*********************************
	// PREREQUISITE: "3sum-target-sum-unique-triplet"
	// VIDEO LINK: https://www.youtube.com/watch?v=LfB2tkmsrCA&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=42
	// QUESTION:
	// 1. Given an array nums of 'n' integers and a variable 'K'.
	// 2. You have to return an array of all the unique set [nums[a], nums[b], nums[c], nums[d] . . . K Elements] such that:
	//     2.1 a, b, c, d . . . K Elements are less than 'n' and greater than 0.
	//     2.2 a,. b, c, d upto K different indexes are Unique.
	//     2.3 nums[a] + nums[b] + nums[c] + nums[d] + . . . + nums[K distinct indexes] == target.
	// 3. You can return answer in any order.
	//*********************************
	vector<int> arr = { -1 , 0 , 1, 2, -1, -4};
	int target = 0;
	int k = 3;
	vector<vector<int>> res = targetSumUniqueSet(arr, target, k);
	for (auto vec : res) {
		for (auto ele : vec) cout << ele << " ";
		cout << endl;
	}

}