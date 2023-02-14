#include <bits/stdc++.h>
using namespace std;

bool wordBreakRecursiveOptmized(string str, vector<string> arr) {
	//BC
	if (str.size() == 0) return true;

	cout << "Str " << str << endl;
	int i = 0;
	for (; i < arr.size(); i++) {
		int stringSize = arr[i].size();
		cout << "stringSize " << stringSize << endl;
		string curr = "";
		if (stringSize <= str.size()) {
			curr = str.substr(0, stringSize);
			cout << "curr " << curr << endl;
			if (curr == arr[i]) {
				//call for to check further part of str.
				string restOfQuestion = stringSize < str.size() ? str.substr(stringSize) : "";
				cout << "rest " << restOfQuestion << endl;

				return wordBreakRecursiveOptmized(restOfQuestion, arr);
			}
		}
		else continue;
	}
	if (i == arr.size()) return false;
}


int main() {
	/*********************************
	LEETCODE: https://leetcode.com/problems/word-break/
	VIDEO LINK: https://www.youtube.com/watch?v=Sx9NNgInc3A
	*********************************/
	// string str = "catsandog";
	// vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};

	// string str = "leetcode";
	// vector<string> wordDict = {"leet", "code"};

	// string str = "applepenapple";
	// vector<string> wordDict = {"apple","pen"};


	string str = "cars";
	vector<string> wordDict = {"car", "ca", "rs"};

	bool ans = wordBreakRecursiveOptmized(str, wordDict);
	if (ans) cout << "true";
	else cout << "false";
}