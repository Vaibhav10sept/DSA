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

void targetSumUniqueTriplet(vector<int> arr, int target) {
	vector<vector<int>> ans;
	int n = arr.size();
	if (n < 3) return;
	sort(arr.begin(), arr.end());

	for (int i = 0; i <= n - 3; i++) {
		//this will ensure that the triplet are unique(think)(before "2sum-target-sum-unique-pair")
		if (i != 0 and arr[i] == arr[i - 1]) continue;

		int val1 = arr[i];
		int newTarget = target - val1;
		vector<vector<int>> currAns = TargetSumUniquePair(arr, i , n - 1, newTarget);
		//printing the answer
		for (vector<int> vec : currAns) {
			cout << val1 << " " << vec[0] << " " << vec[1] << endl;
		}
	}

}

int main() {
	//*********************************
	// PREREQUISITE: "2sum-target-sum-unique-pair"
	// VIDEO LINK: https://www.youtube.com/watch?v=1IBgYGJqKP8&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=40
	// QUESTION:
	// 1. Given an integer array 'nums', and a 'target', return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k.
	// 2. Another thing is nums[i] + nums[j] + nums[k] == target.
	// 3. Notice that the solution set must not contain duplicate triplets.
	//*********************************
	vector<int> arr = { -1, 0, 1 , 2 , -1, -4};
	int target = 0;
	targetSumUniqueTriplet(arr, target);
}