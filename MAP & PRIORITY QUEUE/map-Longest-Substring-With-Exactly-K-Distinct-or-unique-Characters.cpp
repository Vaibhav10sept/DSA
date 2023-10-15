#include<bits/stdc++.h>
using namespace std;

int LongestSubarrayOfSumk(string str, int k) {
	int n = str.size();
	int i = 0, j = 0;
	int ans = INT_MIN;
	map<char, int> freqMap;

	while (j < n) {
		freqMap[str[j]]++;
		if (freqMap.size() == k) {
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
	NOTE: this is variable size sliding window question.
	NOTE: we use map here.
	LINK: https://www.geeksforgeeks.org/find-the-longest-substring-with-k-unique-characters-in-a-given-string/
	VIDEO LINK: smjh jaoge video ki jrurt nhi
	OUTPUT: length of longest subString with "k" no. of unique character.
	*/
	string str = "WORLD";
	int k = 4;
	cout << LongestSubarrayOfSumk(str, k);
}