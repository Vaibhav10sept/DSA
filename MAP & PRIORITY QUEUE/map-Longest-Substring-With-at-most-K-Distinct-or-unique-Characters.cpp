#include<bits/stdc++.h>
using namespace std;

int LongestSubarrayOfSumk(string str, int k) {
	int n = str.size();
	int i = 0, j = 0;
	int ans = INT_MIN;
	map<char, int> freqMap;

	while (j < n) {
		freqMap[str[j]]++;
		if (freqMap.size() <= k) { //this is the only diff, from longest substring with exactly k unique characters
			ans = max(ans, j - i + 1);
		}
		while (freqMap.size() > k) {
			freqMap[str[i]]--;
			if (freqMap[str[i]] == 0) {
				freqMap.erase(str[i]);
			}
			i++;
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
	NOTE: almost same code as in "longest substring with exactly k distinct charaters" just a minute difference.
	PREREQUISITE: longest substring with exactly k distinct charaters.
	NOTE: this is variable size sliding window question.
	NOTE: we use map here.
	LINK: https://www.codingninjas.com/studio/problems/longest-substring-with-at-most-k-distinct-characters_2221410?leftPanelTab=1
	VIDEO LINK: https://www.youtube.com/watch?v=Lav6St0W_pQ&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=10
	OUTPUT: length of longest subString with "k" no. of unique character.
	*/
	string str = "ddacbbaccdedacebb";
	int k = 3;
	cout << LongestSubarrayOfSumk(str, k);
}