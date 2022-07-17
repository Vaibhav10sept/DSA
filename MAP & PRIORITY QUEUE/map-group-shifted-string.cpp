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

string getKey(string str) {
	string key = "";
	for (int i = 1; i < str.size(); i++) {
		char curr = str[i];
		char prev = str[i - 1];
		int diff = curr - prev;
		if (diff < 0) diff += 26; //coz circular hai

		key += diff;
	}

	return key;
}

vector<vector<string>> groupShiftedString(vector<string> arr) {
	map<string, vector<string>> mp;

	for (string str : arr) {
		string key = getKey(str);
		mp[key].push_back(str);
	}

	vector<vector<string>> ans;
	for (auto it : mp) {
		ans.push_back(it.second);
	}
	return ans;
}

int main() {
	/*
	QUESTION LINK: https://www.geeksforgeeks.org/group-shifted-string/
	VIDEO LINK: https://www.youtube.com/watch?v=uEXJSRLqoKY&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=25
	*/
	vector<string> strs  = {"acd", "dfg", "wyz", "yab", "mop",
	                        "bdfh", "a", "x", "moqs"
	                       };

	vector<vector<string>> ans = groupShiftedString(strs);
	displayMatrix(ans);
}