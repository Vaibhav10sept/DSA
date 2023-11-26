#include<bits/stdc++.h>
using namespace std;

int CountOccurrencesOfAnagrams(string pattern, string str) {
	int i = 0;
	int j = 0;
	int k = pattern.size(); //think
	int ans = 0;
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
		if (j - i + 1 == k) { //window size hit
			//calculations
			if (count == 0) {
				ans++;
			}

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
		j++;
	}
	return ans;
}

int main() {
	/*
	LOGIC: here "k" is the size of pattern(think)
	NOTE: here we use map
	VIDEO LINK: https://www.youtube.com/watch?v=MW4lJ8Y0xXk&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=5
	LEETCODE: https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
	*/
	string str = "aabaabaa";
	string pattern = "aaba";
	cout << CountOccurrencesOfAnagrams(pattern, str);
}