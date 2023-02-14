#include<bits/stdc++.h>
using namespace std;

string MinimumWindowSubstring(string s, string t) {
	int i = 0, j = 0, MinL = INT_MAX, start = 0;
	unordered_map<char, int> mp;
	for (auto it : t)
		mp[it]++;
	int count = mp.size();

	if (mp.find(s[j]) != mp.end()) {
		mp[s[j]]--;
		if (mp[s[j]] == 0)
			count--;
	}

	while (j < s.length()) {
		//keep this in mind --> j abhi jiss char me h use hm process kr chuke h, in contrast "i" abhi jiss char me h use hmne abhi process nhi kia h(think,cs)
		if (count > 0) {
			j++;
			if (mp.find(s[j]) != mp.end()) {
				mp[s[j]]--;
				if (mp[s[j]] == 0)
					count--;
			}
		}

		else if (count == 0) {
			while (count == 0) {
				if (MinL > j - i + 1) {
					MinL = j - i + 1;
					start = i;
				}

				if (mp.find(s[i]) != mp.end()) {
					mp[s[i]]++;
					if (mp[s[i]] == 1) {
						count++;
					}
				}
				i++;
			}
		}
	}
	string str = "";
	if (MinL != INT_MAX)
		return str.append(s.substr(start, MinL));
	else
		return str;
}

int main() {
	/*
	PREREQUISITE: "count occurences of anagram"
	NOTE: this is the best and toughest variable size sliding window question.
	NOTE: we use map here.
	LINK: https://leetcode.com/problems/minimum-window-substring/
	VIDEO LINK: https://www.youtube.com/watch?v=iwv1llyN6mo&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=13
	*/
	string s = "ADOBECODEBANC";
	string t = "ABC";
	cout << MinimumWindowSubstring(s, t);
}