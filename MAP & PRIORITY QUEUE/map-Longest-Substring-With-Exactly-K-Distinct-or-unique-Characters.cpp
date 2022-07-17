#include<bits/stdc++.h>
using namespace std;

int LongestSubarrayOfSumk(string str, int k) {
	int n = str.size();
	int i = 0, j = 0;
	int ans = INT_MIN;
	map<char, int> freqMap;
	int cnt = 0;

	while (j < n) {
		freqMap[str[j]]++;
		cnt++;
		if (freqMap.size() == k) {
			ans = max(ans, cnt);
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
	NOTE: this is variable size sliding window question.
	NOTE: we use map here.
	LINK: https://www.geeksforgeeks.org/find-the-longest-substring-with-k-unique-characters-in-a-given-string/
	VIDEO LINK: https://www.youtube.com/watch?v=Lav6St0W_pQ&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=10
	OUTPUT: length of longest subString with "k" no. of unique character.
	*/
	string str = "WORLD";
	int k = 4;
	cout << LongestSubarrayOfSumk(str, k);
}