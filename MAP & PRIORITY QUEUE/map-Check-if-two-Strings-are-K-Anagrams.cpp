#include<bits/stdc++.h>
using namespace std;

bool CheckiftwoStringsareKAnagrams(string s1, string s2, int k) {
	// WV
	if (s1.size() != s2.size()) return false;
	map<char, int> mp;
	for (auto ele : s1) mp[ele]++;

	for (auto ele : s2) {
		if (mp.find(ele) != mp.end()) { //found
			if (mp[ele] > 0) mp[ele]--;
		}
	}

	int count = 0;
	for (auto it : mp) {
		count += it.second;
	}

	return count <= k;
}

int main() {
	/*
	PREREQUISITE: count occurences of anagram -- sliding window
	NOTE: sliding window approach is used here.
	NOTE: here we use map
	VIDEO LINK: https://www.youtube.com/watch?v=VyQbl13RGiw&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=20
	*/
	string s1 = "aabbbc";
	string s2 = "badaba";
	int k = 3;
	cout << CheckiftwoStringsareKAnagrams (s1, s2, k);
}