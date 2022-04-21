#include<bits/stdc++.h>
using namespace std;

bool permutationsInString(string str, string pattern) {
	int i = 0;
	int j = 0;
	int k = pattern.size(); //think
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
		if (mp.find(str[j]) != mp.end()) {
			//str[j] present h map me
			mp[str[j]]--;
			if (mp[str[j]] == 0) {
				count--;
			}
		}
		if (j - i + 1 == k) { //window size hit
			//calculations
			if (count == 0) {
				return true;
			}

			//now, slide the window
			if (mp.find(str[i]) != mp.end()) {
				//means str[i] is there in the map
				if (mp[str[i]] == 0) {
					count++;
				}
				mp[str[i]]++;
			}
			i++;
		}
		j++;
	}
	return false;
}

int main() {
	/*
	PREREQUISITE: "count occcurences of anagram"
	LOGIC: here "k" is the size of pattern(think)
	NOTE: here we use map
	LEETCODE LINK: https://leetcode.com/problems/permutation-in-string/submissions/
	*/
	string s1 = "ab";
	string s2 = "eidbaooo";
	cout << permutationsInString(s2, s1);
}