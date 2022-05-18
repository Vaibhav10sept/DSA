#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> arr, int target) {
	//Key is the number and value is its index in the vector.
	unordered_map<int, int> mp;
	vector<int> ans;
	for (int i = 0; i < arr.size(); i++) {
		int numberToFind = target - arr[i];

		//if numberToFind is found in map, return them
		if (mp.find(numberToFind) != mp.end()) { //found it
			ans.push_back(mp[numberToFind] );
			ans.push_back(i);
			return ans;
		}

		//number is not found. Put it in the map.
		mp[arr[i]] = i;
	}
	return ans;
}

int main() {
	/*
	LEETCODE LINK: https://leetcode.com/problems/two-sum/
	VIDEO LINK:
	*/
	vector<int> arr = {2, 7, 11, 15};
	int target = 9;

	vector<int> ans = twoSum(arr, target);
	for (auto ele : ans)cout << ele << endl;
}