#include <bits/stdc++.h>
using namespace std;



int transformString(string s1, string s2) {
	//NOTE: my code, no video, no reading
	unordered_map<char, int> freqMap;

	for (auto ch : s1) {
		freqMap[ch]++;
	}

	for (auto ch : s2) {
		freqMap[ch]--;
		if (freqMap.find(ch) == freqMap.end()) { //not found
			return -1;
		}
		if (freqMap[ch] == 0) {
			freqMap.erase(ch);
		}
	}

	if (!freqMap.empty()) return -1;


	int i = s1.size() - 1; //pointer for string s1
	int j = s2.size() - 1; //pointer for string s2
	int ans = 0;
	while (i >= 0) {
		if (s1[i] == s2[j]) {
			i--;
			j--;
		}
		else { //s1[i] != s2[j]
			while (i >= 0 and s1[i] != s2[j]) {
				ans++;
				i--;
			}
		}
	}
	return ans;
}


int main() {
	/************************************
	 * //NOTE: my code, no video, no reading
	 * QUESTION: https://practice.geeksforgeeks.org/problems/transform-string5648/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
	// VIDEO LINK:
	//************************************/
	string A = "GeeksForGeeks";
	string B = "ForGeeksGeeks";
	cout << transformString(A, B);

}


