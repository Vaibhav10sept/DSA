#include <bits/stdc++.h>
using namespace std;

bool isMatching(string word, string pattern) {
	// word and pattern length is always same(given in question)
	map<char, char> mp;
	set<char> isWordAlreadyUsed;
	int i = 0; //pattern
	int j = 0; //word
	while (i < word.size() and j < pattern.size()) {
		auto it = mp.find(pattern[i]);
		if (it != mp.end()) { // found

			if (it->second != word[j]) {
				return false;
			}
		}
		else { //not found
			//here is check for the uniqueness of word
			if (isWordAlreadyUsed.find(word[j]) != isWordAlreadyUsed.end()) {
				return false;
			}
			mp[pattern[i]] = word[j];
			isWordAlreadyUsed.insert(word[j]);
		}

		i++;
		j++;
	}
	return true;
}

vector<string> findAndReplacePattern(vector<string> words, string pattern) {
	vector<string> ans;

	for (string word : words) {
		if (isMatching(word, pattern)) {
			ans.push_back(word);
		}
	}
	return ans;
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=4Ze_vLq5tPQ&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=46
	// QUESTION:
	// 	1. Given a list of strings words and a string pattern.
	// 2. Return a list of words[i] that match pattern. You may return the answer in any order.
	// 3. A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
	// 4. Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.
	//*********************************
	vector<string> words = {"mno", "rst", "rss", "bll", "lml", "aaa"};
	// vector<string> words = {"mno"};
	string pattern = "epp";

	vector<string> res = findAndReplacePattern(words, pattern);
	cout << "result: " << endl;
	for (auto ele : res) cout << ele << " ";
}