#include <bits/stdc++.h>
using namespace std;

vector<string> getKeypadCombination(string str, vector<string> codes) {
	if (str.size() == 0) {
		vector<string> baseResult;
		baseResult.push_back("");
		return baseResult;
	}
	char code = str[0];
	int IntCode = code - '0';
	string pattern = codes[IntCode];
	string restOfCode = str.substr(1);
	vector<string> recursionResult = getKeypadCombination(restOfCode, codes);
	vector<string> myResult;
	for (string val : recursionResult) {
		for (char code : pattern) {
			myResult.push_back(code + val);
		}
	}
	return myResult;
}



int main()
{
	//********************************
	// LEETCODE: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
	// VIDEO LINK: https://www.youtube.com/watch?v=hMJAlbJIS7E&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=399
	//***********************************
	vector<string> codes = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vws", "yz"};
	vector<string> ans = getKeypadCombination("735", codes);
	for (auto val : ans) cout << val << endl;
}