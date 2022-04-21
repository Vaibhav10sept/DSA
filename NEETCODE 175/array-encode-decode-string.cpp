#include <bits/stdc++.h>
using namespace std;

string encode(vector<string> arr) {
	//we use 4# as the delimiter, ie. 4 is the number of charater for the following string.
	string ans = "";
	for (auto ele : arr) {
		ans += to_string(ele.size()) + "#" + ele;
	}
	return ans;
}

vector<string> decode(string str) {
	vector<string> ans;
	for (int i = 0; i < str.size(); i++) {
		if (isdigit(str[i]) and i + 1 < str.size() and str[i + 1] == '#') {
			string word = "";
			int n = str[i] - '0';
			i += 2;
			for (int j = 0; j < n; j++) {
				word += str[i];
				i++;
			}
			i--; //think, logic
			ans.push_back(word);
		}
	}
	return ans;
}

int main() {
	/*
	*********************************
	VIDEO LINK: https://www.youtube.com/watch?v=pdRZrjlqSbs
	LEETCODE LINK: https://www.lintcode.com/problem/659/
	*********************************
	*/
	vector<string> arr = {"lint", "code", "love", "you"};
	string encoded = encode(arr);
	cout << "encoded string is: " << encoded << endl;
	cout << "after decoding" << endl;
	vector<string> ans = decode(encoded);
	for (auto ele : ans) cout << ele << " ";
}