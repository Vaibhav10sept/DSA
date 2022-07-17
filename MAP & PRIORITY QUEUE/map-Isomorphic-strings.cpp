#include <bits/stdc++.h>
using namespace std;

bool isomorphicStrings(string str1, string str2) {
	if (str1.size() != str2.size()) return false;

	//2 maps are used here, watch video recommended
	map<char, char> mp1;
	map<char, bool> mp2;

	for (int i = 0; i < str1.size(); i++) {
		char ch1 = str1[i];
		char ch2 = str2[i];

		if (mp1.find(ch1) != mp1.end()) { //found in mp1
			if (mp1[ch1] != ch2) return false;
		}

		else { //not found in mp1
			if (mp2[ch2] == true) return false; //means ch2 already used ho chuka hai
			else { //maping kr do in both the maps
				mp1[ch1] = ch2;
				mp2[ch2] = true;
			}
		}
	}
	return true;
}

int main() {
	/*
	NOTE: Two strings s and t are isomorphic if the characters in s can be replaced to get t.
	QUESTION LINK: https://leetcode.com/problems/isomorphic-strings/
	VIDEO LINK: https://www.youtube.com/watch?v=6Qkail843d8&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=26
	*/
	string s = "egg";
	string t = "add";
	cout << isomorphicStrings(s, t);
}