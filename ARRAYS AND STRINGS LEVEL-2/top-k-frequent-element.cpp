#include <bits/stdc++.h>
using namespace std;

bool comparator(vector<int> v1, vector<int> v2) {
	//sort in decreasing order.
	return v1[0] > v2[0];
}

vector<int> topKFreqElement(vector<int> arr, int k) {

	map<int, int> mp;
	vector<vector<int>> freqVec;
	vector<int> ans;

	//filling frequency map
	for (auto ele : arr) {
		mp[ele]++;
	}

	//filling freq vector for sorting
	for (auto i = mp.begin(); i != mp.end(); i++) {
		vector<int> temp;
		temp.push_back(i->second);
		temp.push_back(i->first);
		freqVec.push_back(temp);
	}

	sort(freqVec.begin(), freqVec.end(), comparator);

	//add the first k element in ans vector.
	for (int i = 0; i < k; i++) {
		ans.push_back(freqVec[i][1]);
	}
	return ans;
}

int main() {
	//*********************************
	// LEETCODE LINK: https://leetcode.com/problems/top-k-frequent-elements/
	// VIDEO LINK: https://www.youtube.com/watch?v=HkPDkRpScSs&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=80
	//*********************************
	vector<int> nums = {1, 1, 1, 2, 2, 3};
	int k = 2;
	vector<int> ans = topKFreqElement(nums, k);
	for (auto ele : ans) cout << ele << " ";
}