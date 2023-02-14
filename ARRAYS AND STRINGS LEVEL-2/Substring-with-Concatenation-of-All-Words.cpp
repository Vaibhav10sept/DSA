#include <bits/stdc++.h>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
	//code is copied from leetcode but the the given video link explaination is same as the code here
	unordered_map<string, int> freqMap;
	vector<int> ans;
	for (string word : words)
		freqMap[word]++;

	int n = s.length();
	int wordsSize = words.size();

	if (n == 0 || wordsSize == 0) return ans; //edge cases

	int eachWordSize = words[0].length();
	for (int i = 0; i <= n - wordsSize * eachWordSize; i++) {
		unordered_map<string, int> seen;
		int j = 0;

		for (; j < wordsSize; j++) {
			string word = s.substr(i + j * eachWordSize, eachWordSize);
			if (freqMap.find(word) != freqMap.end()) { //found
				seen[word]++;
				if (seen[word] > freqMap[word])
					break;
			}
			else break; // not found
		}

		if (j == wordsSize) ans.push_back(i);
	}

	return ans;
}

int main() {
	/*
	VIDEO LINK: https://www.youtube.com/watch?v=Bbu4Qjzf7A0
	QUESTION LINK: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
	*/
	string str = "barfoofoobarthefoobarman";
	vector<string> words = {"bar", "foo", "the"};
	vector<int> ans = findSubstring(str, words);
	for (auto ele : ans) cout << ele << " ";
}



