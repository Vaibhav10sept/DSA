#include <bits/stdc++.h>
using namespace std;

bool continuousSubarraySum(vector<int> arr, int k) {
	//I wrote this code after going throught the strong prerequisite.
	unordered_map<int, int> mp; //remainder->index
	mp[0] = -1;
	int sum = 0;

	for (int i = 0; i < arr.size(); i++) {
		sum += arr[i];
		int remainder = sum % k;

		if (mp.find(remainder) != mp.end()) { //found
			if (i - mp[remainder] >= 2) return true; //that's the condition given in question(read question)
		}
		else { //not found
			mp[remainder] = i;
		}
	}
	return false;
}

int main() {
	/*
	STRONG PREREQUISITE: subarray with sum divisible by k(almost same question)
	NOTE: I wrote this code after going throught the strong prerequisite.
	QUESTION LINK: https://leetcode.com/problems/continuous-subarray-sum/description/
	VIDEO LINK:
	*/
	vector<int> arr = {23, 2, 4, 6, 7};
	int k = 6;
	if (continuousSubarraySum(arr, k)) cout << "true" << endl;
	else cout << "false" << endl;
}