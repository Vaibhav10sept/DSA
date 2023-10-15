#include<bits/stdc++.h>
using namespace std;

int maxValue(map<char, int> mp) {
	int ans = INT_MIN;

	for (const auto &entry : mp)
	{
		if (ans < entry.second)
		{
			ans = entry.second;
		}
	}
	return ans;
}

int longestsubstringwithoutrepeatingcharacters(string str, int k) {
	int n = str.size();
	int i = 0, j = 0;
	int ans = INT_MIN;
	map<char, int> freqMap;
	int maxFreq = INT_MIN;
	while (j < n) {
		freqMap[str[j]]++;
		maxFreq = maxValue(freqMap);

		if ((j - i + 1) - maxFreq <= k) {
			// cout << "i " << i << " " << j << endl;
			ans = max(ans, j - i + 1);
		}

		else if ((j - i + 1) - maxFreq > k) {
			while ((j - i + 1) - maxFreq > k) {
				if (freqMap.find(str[i]) != freqMap.end()) {
					freqMap[str[i]]--;
				}
				i++;
			}
		}
		j++;
	}
	if (ans == INT_MIN) {
		return 0;
	}
	return ans;
}

int main() {
	/*
	PREREQUISITE: "Longest-Substring-With-K-unique-Characters"
	NOTE: this is variable size sliding window question.
	NOTE: we use map here.
	VIDEO LINK: https://www.youtube.com/watch?v=gqXU1UyA8pk
	*/
	string str = "AABABBA";
	int k = 1;
	cout << longestsubstringwithoutrepeatingcharacters(str, k);
}