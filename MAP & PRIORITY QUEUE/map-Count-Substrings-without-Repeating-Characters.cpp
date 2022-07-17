#include<bits/stdc++.h>
using namespace std;

int CountSubstringsWithoutRepeatingCharacters(string str) {
	int n = str.size();
	int i = 0, j = 0;
	int countOfSubstrings = 0;
	map<char, int> freqMap;

	while (j < n) {
		freqMap[str[j]]++;
		//LOGIC: agr char repeat nhi hoge to map ka size window ke size ke barabar hojaega.
		if (freqMap.size() == j - i + 1) {
			countOfSubstrings += j - i + 1;
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
					//NOTE: i change hua means j-i+1 bhi change hua hoga, toh below "if" lgana jruri hai(think)
					if (freqMap.size() == j - i + 1) {
						countOfSubstrings += j - i + 1;
					}
				}
			}
		}
		j++;
	}
	return countOfSubstrings;
}

int main() {
	/*
	PREREQUISITE: "Longest-Substring-Without repeating characters"
	PREREQUISITE: "Longest-Substring-With-K-Unique-Characters"
	NOTE: this is variable size sliding window question.
	NOTE: we use map here.
	LINK: https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/
	VIDEO LINK: https://www.youtube.com/watch?v=L6cffskouPQ&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=11
	*/
	string str = "aabcbcdbca";
	cout << "The count of the non-repeating "
	     "character substring is: " << CountSubstringsWithoutRepeatingCharacters(str);
}