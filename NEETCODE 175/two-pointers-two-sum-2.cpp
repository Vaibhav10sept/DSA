#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> arr, int target) {
	// NOTE: in two sum 2 the given array is sorted
	int i = 0;
	int j = arr.size() - 1;
	vector<int> ans;
	while (i < j)
	{
		int sum = arr[i] + arr[j];
		if (sum > target) {
			j--;
		}
		else if (sum < target) {
			i++;
		}
		else {
			ans.push_back(i + 1);
			ans.push_back(j + 1);
			return ans;
		}
	}
	return ans;
}

int main() {
	/*
	*********************************
	VIDEO LINK:
	*********************************
	*/
	vector<int> arr = {2, 7, 11, 15};
	int target = 9;
	vector<int> ans = twoSum(arr, target);
	for (auto ele : ans) cout << ele << " ";
}