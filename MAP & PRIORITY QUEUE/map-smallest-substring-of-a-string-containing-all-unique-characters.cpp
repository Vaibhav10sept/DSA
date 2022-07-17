#include<bits/stdc++.h>
using namespace std;

string MinimumWindowSubstring(string s, string t) {
	int i = 0, j = 0, ans = INT_MAX, start = 0;
	unordered_map<char, int> mp;

	//filling mp(freq map) using given string "t"
	for (auto it : t)
		mp[it]++;
	int count = mp.size();

	if (mp.find(s[j]) != mp.end()) {
		mp[s[j]]--;
		if (mp[s[j]] == 0)
			count--;
	}
	// cout << j << endl;

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
						// ans=min(ans,j-i+1);
						if (ans > j - i + 1) {
							ans = j - i + 1;
							start = i;
						}
					}
					i++;
				}
				else //s[i] mp me nhi hai, toh directly i++ kr do(think)
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

string smallestSubstringContainingAllUniqueCharaters(string str) {
	//first find the unique characters in str using set
	set<char> st;
	for (auto ele : str) {
		st.insert(ele);
	}
	string minString = "";
	for (auto ch : st) {
		minString += ch;
	}
	// cout << "minString " << minString << endl;
	//ab is minString(smaller) and str(larger) ko use krte hue min window substring call kro
	return MinimumWindowSubstring(str, minString);
}

int main() {
	/*
	HIGHLY PREREQUISITE: min window substring
	NOTE: an application of min window substring algorithm.
	PREREQUISITE: "count occurences of anagram"
	NOTE: this is the best and toughest variable size sliding window question.
	NOTE: we use map here.
	LINK: https://leetcode.com/problems/minimum-window-substring/
	VIDEO LINK: https://www.youtube.com/watch?v=iwv1llyN6mo&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=13
	*/
	string s = "aabcbcdbca";
	cout << smallestSubstringContainingAllUniqueCharaters(s);
}