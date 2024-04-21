#include <bits/stdc++.h>
using namespace std;

bool dfs(string word, unordered_set<string>& st, unordered_map<string, bool> &memo) {
	if (word.size() == 0) return false;
	//BC ends

	if (memo.find(word) != memo.end()) //memoization
		return memo[word];

	for (int i = 0; i < word.size(); i++) {
		string prefix  = word.substr(0, i + 1);
		string suffix  = word.substr(i + 1);

		if ((st.find(prefix) != st.end() && dfs(suffix, st, memo)) ||
		        (st.find(prefix) != st.end() && st.find(suffix) != st.end()))
			return memo[word] = true;
	}


	return memo[word] = false;

}

vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
	//wv
	vector<string> result;
	unordered_set<string> st(words.begin(), words.end());
	unordered_map<string, bool> memo;

	for (int i = 0; i < words.size(); i++) {
		if (dfs(words[i], st, memo))
			result.push_back(words[i]);
	}

	return result;
}

int main() {
	/*********************************
	 * NOTE: one more sol is there that give you TLE.
	LEETCODE: https://leetcode.com/problems/concatenated-words/
	VIDEO LINK: https://www.youtube.com/watch?v=zZsnMAgM6Q0
	*********************************/

	vector<string> words = {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};
	vector<string> ans = findAllConcatenatedWordsInADict(words);
	for (auto ele : ans) cout << ele << endl;
}