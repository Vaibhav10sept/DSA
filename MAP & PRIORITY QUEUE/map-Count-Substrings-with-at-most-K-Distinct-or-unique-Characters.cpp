#include<bits/stdc++.h>
using namespace std;

int CountSubstringswithAtMostKDistinctCharacters(string str, int k) {
	int n = str.size();
	int i = 0, j = 0;
	int countOfSubstrings = 0;
	map<char, int> freqMap;
	int cnt = 0;

	while (j < n) {
		freqMap[str[j]]++;
		cnt++;
		if (freqMap.size() <= k) {
			countOfSubstrings += j - i + 1;
		}
		else if (freqMap.size() > k) {
			while (freqMap.size() > k) {
				if (freqMap.find(str[i]) != freqMap.end()) {
					freqMap[str[i]]--;
					if (freqMap[str[i]] == 0) {
						freqMap.erase(str[i]);
					}
					cnt--;
					i++;
					//NOTE: i change hua means j-i+1 bhi change hua hoga, toh below "if" lgana jruri hai(think)
					if (freqMap.size() <= k) {
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
	PREREQUISITE: longest substring with exactly k distinct characters
	NOTE: not similar to count substring with k distinct characters.
	VIDEO LINK: https://www.youtube.com/watch?v=shsYUyF7pEs&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=19
	*/
	string str = "aabcbcdbca";
	int k = 2;
	cout << "count " << CountSubstringswithAtMostKDistinctCharacters(str, k);
}