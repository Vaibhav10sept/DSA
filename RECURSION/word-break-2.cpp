#include <bits/stdc++.h>
using namespace std;

bool subStringIsFoundInDictionary(string sub, set<string> dictionary) {
	if (dictionary.find(sub) == dictionary.end()) { //not found, return false
		return false;
	}
	return true;
}

void helperRecursive(int idx, string str, set<string> dictionary, vector<string> ans) {
	if (idx == str.size()) {
		//base case
		for (auto ele : ans) {
			cout << ele << " ";
		}
		cout << endl;
	}

	for (int i = idx; i < str.size(); i++) {
		string sub = str.substr(idx, i - idx + 1); //str.substr(starting index, length)
		if (subStringIsFoundInDictionary(sub, dictionary)) {
			ans.push_back(sub);
			helperRecursive(i + 1, str, dictionary, ans);
			//backtrack
			ans.pop_back();
		}
	}
}

void wordBreak2(string str, set<string> dictionary) {
	vector<string> ans;
	helperRecursive(0, str , dictionary, ans);
}

int main()
{
	/*
	NOTE:
	QUESTION: https://www.codingninjas.com/codestudio/problems/983635?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
	VIDEO:
	*/
	vector<string> dictionary =  {"god", "is", "now", "no", "where", "here"};
	set<string> dict(dictionary.begin(), dictionary.end());
	string str = "godisnowherenowhere";
	wordBreak2(str, dict);

}