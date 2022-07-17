#include <bits/stdc++.h>
using namespace std;

vector<string> getSplitString(string S) {
	string T;  // declare string variables
	vector<string> ans;

	stringstream X(S); // X is an object of stringstream that references the S string

	// use while loop to check the getline() function condition
	while (getline(X, T, ' ')) {
		/* X represents to read the string from stringstream, T use for store the token string and,
		 ' ' whitespace represents to split the string where whitespace is found. */
		ans.push_back(T);
	}
	return ans;
}

bool wordPattern(string pattern, string str) {
	//get splitted vector of string from str
	vector<string> strArray = getSplitString(str);
	if (pattern.size() != strArray.size()) return false;
	//2 maps are used here, watch video recommended
	map<char, string> mp1;
	map<string, bool> mp2;

	for (int i = 0; i < pattern.size(); i++) {
		char ch1 = pattern[i];
		string ch2 = strArray[i];
		// cout << "test " << ch1 << " " << ch2 << endl;
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
	PREREQUISITE: isomorphic string.
	QUESTION LINK: https://leetcode.com/problems/word-pattern/
	VIDEO LINK: https://www.youtube.com/watch?v=L-Kw6unCGQ4&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=27
	*/
	string pattern = "abba";
	string s = "dog cat cat dog";

	// string pattern = "aaaa";
	// string s = "dog cat cat dog";

	// string pattern = "aaa";
	// string s = "aa aa aa aa";
	bool ans = wordPattern(pattern, s);
	cout << "res" << endl;
	if (ans)cout << "true";
	else cout << "false";

}