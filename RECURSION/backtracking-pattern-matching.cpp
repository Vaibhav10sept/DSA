#include <bits/stdc++.h>
using namespace std;

void backtrackingHelper(int idx, map<char, string> mp, string str, string pattern) {
	// cout << idx << endl;
	if ( pattern == "" ) {
		if (idx == str.size()) {
			for (auto it : mp) {
				cout << it.first << "-> " << it.second << endl;
			}
			cout << "----------" << endl;
		}
		return;
	}
	// if (idx == str.size() or pattern == "") return;
	//BC ends

	string restOfPattern = pattern.substr(1);
	// cout << "res " << restOfPattern << endl;
	char currChar = pattern[0];

	if (mp.find(currChar) != mp.end()) { //found, already mapped
		string currMapping = mp[currChar];
		if (idx + currMapping.size() <= str.size()) {

			if (str.substr(idx, currMapping.size()) == currMapping) {
				backtrackingHelper(idx + currMapping.size(), mp, str, restOfPattern);
			}
		}

	}

	else { //the str[idx] not mapped already
		//recursive calls to all the substring starting from idx.
		int i = idx;
		while (i < str.size()) {
			string substr = str.substr(idx, i - idx + 1);
			mp[currChar] = substr;
			backtrackingHelper(i + 1, mp, str, restOfPattern);
			//backtrack
			mp.erase(currChar);
			i++;
		}

	}
}

void patternMatching(string str, string pattern) {
	//LOGIC: level pe pattern ke letter hoge
	// or options me substring hogi
	map<char, string> mp;
	backtrackingHelper(0, mp, str, pattern);
}

int main()
{
	/*******************************
	STRONG NOTE: this is my code, slightly different then the code in the video. DO watch the video please.
	 * NOTE: backtracking is used here.
	 * VIDEO LINK: https://www.youtube.com/watch?v=aVMyXDuSLNM
	 QUESTION LINK: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/pattern-matching-official/ojquestion
	 * *************************************/
	string str  = "mzaddytzaddy";
	string pattern = "abcb";
	patternMatching(str, pattern);

}