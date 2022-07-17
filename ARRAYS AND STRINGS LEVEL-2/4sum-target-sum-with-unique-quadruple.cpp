#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> TargetSumUniquePair(vector<int> arr, int left, int right, int target) {
	sort(arr.begin(), arr.end());
	vector<vector<int>> ans;
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

vector<vector<int>> targetSumUniqueTriplet(vector<int> arr, int left, int target) {
	vector<vector<int>> ans;
	int n = arr.size();
	if (n - left < 3) return ans;
	sort(arr.begin(), arr.end());

	for (int i = left; i <= n - 3; i++) {
		//this will ensure that the triplet are unique(think)(before "2sum-target-sum-unique-pair")
		if (i != left and arr[i] == arr[i - 1]) continue;

		int val1 = arr[i];
		int newTarget = target - val1;
		vector<vector<int>> currAns = TargetSumUniquePair(arr, i, n - 1, newTarget);
		//printing the answer
		for (vector<int> vec : currAns) {
			vec.push_back(val1);
			ans.push_back(vec);
		}
	}
	return ans;
}

vector<vector<int>> targetSumUniqueQuadruple(vector<int> arr, int target) {
	vector<vector<int>> ans;
	int n = arr.size();
	if (n < 4) return ans;
	sort(arr.begin(), arr.end());

	for (int i = 0; i <= n - 4; i++) {
		//this will ensure that the triplet are unique(think)(before "2sum-target-sum-unique-pair")
		if (i != 0 and arr[i] == arr[i - 1]) continue;

		int val1 = arr[i];
		int newTarget = target - val1;
		vector<vector<int>> currAns = targetSumUniqueTriplet(arr, i + 1, newTarget);
		//printing the answer
		for (vector<int> vec : currAns) {
			vec.push_back(val1);
			ans.push_back(vec);
		}
	}
	return ans;
}


int main() {
	//*********************************
	// PREREQUISITE: "3sum-target-sum-unique-triplet"
	// VIDEO LINK: https://www.youtube.com/watch?v=hGz0b8L7plI&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=41
	// QUESTION:
	// 	1. Given an array nums of 'n' integers.
	// 2. You have to return an array of all the unique quadruple [nums[a], nums[b], nums[c], nums[d]] such that:
	//     2.1 a, b, c, and d are less than 'n' and greater than 0
	//     2.2 a,. b, c, and d are Unique.
	//     2.3 nums[a] + nums[b] + nums[c] + nums[d] == target.
	// 3. You can return answer in any order.
	//*********************************
	vector<int> arr = { 1, 0 , -1 , 0, -2, 2};
	int target = 0;
	vector<vector<int>> res = targetSumUniqueQuadruple(arr, target);
	for (auto vec : res) {
		for (auto ele : vec) cout << ele << " ";
		cout << endl;
	}

}



