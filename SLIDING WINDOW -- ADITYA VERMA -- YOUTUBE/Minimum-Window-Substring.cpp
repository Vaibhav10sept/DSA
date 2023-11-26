#include<bits/stdc++.h>
using namespace std;

string MinimumWindowSubstring(string pattern, string str) {
	int i = 0;
	int j = 0;
	int k = pattern.size(); //think
	int ans = INT_MAX;
	string res = "";
	// i --> represent start of window
	// j --> represent end of window
	// j-i+1 --> is the size of window

	map<char, int> mp;
	//now fill this map with the given pattern
	for (char ch : pattern) {
		mp[ch]++;
	}
	int count = mp.size(); //represent total no. of distinct character in pattern

	while (j < str.size()) {
		if (mp.find(str[j]) != mp.end()) { //found
			//str[j] present h map me
			mp[str[j]]--;
			if (mp[str[j]] == 0) {
				count--;
			}
		}

		if (count == 0) { //means, pattern ke sare char mil gae h
			// ans = min(j - i + 1, ans); //min window size chahiye jisme pattern ho

			//try reducing the win size using i
			while (count == 0) {
				//now, slide the window
				if (mp.find(str[i]) != mp.end()) { //found
					//means str[i] is there in the map
					if (mp[str[i]] == 0) {
						count++;
					}
					mp[str[i]]++;
				}
				i++;

			}
			if (j - (i - 1) + 1 < ans) { // think why (i-1) -> my code, no video, smjh aa gya h
				ans = j - (i - 1) + 1;
				res = str.substr((i - 1), j - (i - 1) + 1);
			}
		}

		j++;
	}
	return res;
}

int main() {
	/*
	NOTE: i wrote this code after modifying code of "count occurences of anagram"
	SAME CODE WITH SLIGHT VARIATION: "count occurences of anagram"
	STRONG PREREQUISITE: "count occurences of anagram"
	NOTE: this is the best and toughest variable size sliding window question.
	NOTE: we use map here.
	LINK: https://leetcode.com/problems/minimum-window-substring/
	VIDEO LINK: https://www.youtube.com/watch?v=iwv1llyN6mo&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=13
	*/
	string str = "ADOBECODEBANC";
	string pattern = "ABC";
	cout << MinimumWindowSubstring(pattern, str);
}