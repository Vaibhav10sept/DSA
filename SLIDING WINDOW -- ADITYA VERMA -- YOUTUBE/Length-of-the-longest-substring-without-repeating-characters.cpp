#include<bits/stdc++.h>
using namespace std;

int longestsubstringwithoutrepeatingcharacters(string str) {
	int n = str.size();
	int i = 0, j = 0;
	int ans = INT_MIN;
	map<char, int> freqMap;
	while (j < n) {
		freqMap[str[j]]++;
		if (freqMap.size() == j - i + 1) {
			ans = max(ans, j - i + 1);
		}
		//think for below condition.
		else if (freqMap.size() < j - i + 1) {
			while (freqMap.size() < j - i + 1) {
				if (freqMap.find(str[i]) != freqMap.end()) {
					freqMap[str[i]]--;
					if (freqMap[str[i]] == 0) {
						freqMap.erase(str[i]);
					}
					i++;
				}
			}
		}
		j++;
	}
	if (ans == INT_MIN) {
		return -1;
	}
	return ans;
}

int main() {
	/*
	PREREQUISITE: "Longest-Substring-With-K-Unique-Characters"
	NOTE: this is variable size sliding window question.
	NOTE: we use map here.
	LINK: https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/
	VIDEO LINK: https://www.youtube.com/watch?v=L6cffskouPQ&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=11
	*/
	string str = "ABDEFGABEF";
	cout << "The length of the longest non-repeating "
	     "character substring is: " << longestsubstringwithoutrepeatingcharacters(str);
}