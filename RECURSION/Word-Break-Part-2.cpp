#include <bits/stdc++.h>
using namespace std;

void rec(int ind, string asf, unordered_set<string> &set, string &str, vector<string> &ans) {

	if (ind == str.size()) {
		asf.pop_back();
		asf += ")";
		ans.push_back(asf);
		// ans.push_back(")")
	}
	//BC ends

	for (int i = ind; i < str.size(); i++) {
		string sub = str.substr(ind, i - ind + 1);
		if (set.find(sub) != set.end()) {
			rec(i + 1, asf + sub + " ", set, str, ans);
		}
	}
}

vector<string> wordBreak(int n, vector<string>& arr, string str)
{
	// NOTE: i wrote it myself
	vector<string> ans;
	unordered_set<string> set;
	for (auto ele : arr) {
		set.insert(ele);
	}
	rec(0, "(", set, str, ans);
	return ans;
}

int main()
{
	/*
	NOTE: i wrote it myself
	VIDEO:
	QUESTION: https://practice.geeksforgeeks.org/problems/word-break-part-23249/1
	*/
	string s = "catsanddog";
	int n = 5;
	vector<string> dict = {"cats", "cat", "and", "sand", "dog"};
	vector<string> ans = wordBreak(n, dict, s);
	for (auto ele : ans) cout << ele << endl;
}