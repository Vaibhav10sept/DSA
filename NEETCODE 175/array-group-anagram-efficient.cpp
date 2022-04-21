#include <bits/stdc++.h>
using namespace std;

void displayMatrix(vector<vector<string>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

vector<vector<string>> groupAnagram(vector<string> arr) {
	//code is copied from leetcode discussion
	unordered_map<string, vector<string>> mp;
	for (string s : arr) {
		string t = s;
		sort(t.begin(), t.end());
		mp[t].push_back(s);
	}
	vector<vector<string>> ans;
	for (auto p : mp) {
		ans.push_back(p.second);
	}
	return ans;
}

int main() {
	/*
	LEETCODE LINK: https://leetcode.com/problems/group-anagrams/
	VIDEO LINK:
	*/
	vector<string> arr = {"eat", "tea", "tan", "ate", "nat", "bat"};

	vector<vector<string>> ans = groupAnagram(arr);
	displayMatrix(ans);
}