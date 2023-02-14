#include<bits/stdc++.h>
using namespace std;

string MinimumWindowSubstring(string s, string t) {
	int i = 0, j = 0, ans = INT_MAX, start = 0;
	unordered_map<char, int> mp;

	//filling mp(freq map) using given string "t"
	for (auto it : t)
		mp[it]++;
	int count = mp.size();

	//one check for j==0, mujhe nhi pata ise while loop ke ander kyo nhi kia gya
	if (mp.find(s[j]) != mp.end()) {
		mp[s[j]]--;
		if (mp[s[j]] == 0)
			count--;
	}

	while (j < s.length()) {
		if (count > 0) {
			j++;
			if (mp.find(s[j]) != mp.end()) {
				mp[s[j]]--;
				if (mp[s[j]] == 0)
					count--;
			}

		}
		else if (count == 0) {
			// ans=min(ans,j-i+1);
			if (ans > j - i + 1) {
				ans = j - i + 1;
				start = i;
			}
			//here, we are trying to reduce the window size, by incrementing "i" pointer
			while (count == 0) {
				if (mp.find(s[i]) != mp.end()) {
					mp[s[i]]++;
					if (mp[s[i]] == 1) {
						count++;
					}

				}
				if (ans > j - i + 1) {
					ans = j - i + 1;
					start = i;
				}
				i++;
			}
		}
	}
	string str = "";
	if (ans != INT_MAX)
		return str.append(s.substr(start, ans));
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
	string s = "timetopractice";
	string t = "toc";
	cout << MinimumWindowSubstring(s, t);
}