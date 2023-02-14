#include <bits/stdc++.h>
using namespace std;

void TargetSumUniquePair(vector<int> arr, int target) {
	sort(arr.begin(), arr.end());
	int left = 0;
	int right = arr.size() - 1;
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
			cout << arr[left] << " " << arr[right] << endl;
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
}

int main() {
	//*********************************
	// PREREQUISITE: target sum pair(not done in code)
	// VIDEO LINK: https://www.youtube.com/watch?v=l5Ruk_Ub8B4&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=38
	// QUESTION:
	// 1. Given an Array of size 'n' have may or may not be repeated elements.
	// 2. A 'target' is provided.
	// 3. Return Pair of target sum in which all pairs are unique, for example : [1, 2], [2, 1] are consider as same pair.
	// 4. If array have repeated element then return only unique pair, for example : if array is arr = [2, 2, 4, 4], and target = 6 then res have only one pair, i.e. [2, 4]
	//*********************************
	vector<int> arr = {3, 2, 4};
	int target = 6;
	TargetSumUniquePair(arr, target);
}