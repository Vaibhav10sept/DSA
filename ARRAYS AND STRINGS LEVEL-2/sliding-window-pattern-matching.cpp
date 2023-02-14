#include<bits/stdc++.h>
using namespace std;

vector<int> patternMatching(string s, string t) {
	//THIS SOLUTION IS WRITTEN BY ME.
	int i = 0, j = 0, start = 0;
	vector<int> ans;

	while (j < s.length()) {
		if (j - i + 1 < t.size()) {
			j++;
		}

		else if (j - i + 1 == t.size())  {
			string sub = s.substr(i, j - i + 1);
			cout << "sub " << sub << endl;
			if (sub == t) {
				ans.push_back(i);
			}
			i++;
			j++;
		}

	}
	return ans;
}

int main() {
	/*
	NOTE: I write this solution
	LINK: https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
	VIDEO LINK:
	*/
	string str  = "GEEKS FOR GEEKS";
	string pat = "GEEK";
	vector<int> ans = patternMatching(str, pat);
	cout << "res" << endl;
	for (auto ele : ans) cout << ele << " ";
}