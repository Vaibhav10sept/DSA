#include <bits/stdc++.h>
using namespace std;

int minDeletion(string str) {
	vector<int> freq(26);
	int ans = 0;
	for (char ch : str) {
		freq[ch - 'a']++;
	}
	sort(freq.begin(), freq.end(), greater<int>()); // sort in decreasing order
	int maxAllowedFrequency = freq[0];
	for (int ele : freq) {
		if (ele > maxAllowedFrequency) {
			if (maxAllowedFrequency > 0) {
				ans += (ele - maxAllowedFrequency);
			}
			else {
				ans += ele;
			}
		}
		maxAllowedFrequency = min(maxAllowedFrequency - 1, ele - 1);
	}
	return ans;
}


int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=xzsAFSFiVF8
	//*********************************
	string str = "ceabaacb";
	cout << minDeletion(str);
}