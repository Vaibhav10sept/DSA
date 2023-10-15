#include<bits/stdc++.h>
using namespace std;

int CountSubstringswithAtMostKDistinctCharacters(string s, int K) {
	//code generated from chatgpt
	int i = 0;
	int j = 0;
	int count = 0;
	unordered_map<char, int> freq;
	int n = s.size();

	while (j < n) {
		// Add the current character to the hashmap and update its frequency
		freq[s[j]]++;

		// Move the i pointer to the j until the number of distinct characters becomes K
		while (freq.size() > K) {
			freq[s[i]]--;
			if (freq[s[i]] == 0) {
				freq.erase(s[i]);
			}
			i++;
		}

		// For each valid substring (i to j), add the length of the substring to the count
		// In this approach, for each valid substring, we add its length to the count. This ensures that we count every distinct substring exactly once.
		// Therefore, adding the length of the substring to the count helps us keep track of the total number of substrings with at most K distinct characters.
		count += j - i + 1;
		j++;
	}

	return count;
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