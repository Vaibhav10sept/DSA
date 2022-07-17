#include <bits/stdc++.h>
using namespace std;

bool validAnagram(string s, string t) {
	if (s.length() != t.length()) return false;
	int n = s.length();

	unordered_map<char, int> mp;

	//filling up the map(mp)
	for (int i = 0; i < n; i++) {
		mp[s[i]]++;
		mp[t[i]]--;
	}

	//checking if any value inside the map is not zero, if yes then return false
	for (auto count : mp)
		if (count.second != 0) return false;
	return true;
}

int main() {
	/*
	LEETCODE LINK: https://leetcode.com/problems/valid-anagram/
	VIDEO LINK:
	*/
	string s = "anagram";
	string t = "nagaram";

	cout << validAnagram(s, t);
}