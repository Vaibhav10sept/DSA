#include <bits/stdc++.h>
using namespace std;

int editDistance(string s, string p) {
	//WV highly recommended
	vector<vector<bool>> dp(p.size() + 1, vector<bool>(s.size() + 1, false));
	//STORAGE: dp[i][j] stores true or false ki for "p" from start to i and for "s" from start to j...kya "p" se "s" bna skta h(booleans)
	//NOTE: 0th row and 0th col are for initilization.
	//NOTE: becoz of above initilization indx of dp is one more than the indx of s and p. so s and p ke indx ko access krne ke lie j-1 and i-1 krna hoga

	for (int i = 0; i < dp.size(); i++) {
		for (int j = 0; j < dp[0].size(); j++) {

			//initiliazation starts
			if (i == 0 and j == 0) {
				dp[i][j] = true; //blank s and p to hmesa hi match krege.
			}
			else if (i == 0) { //for first row
				//blank p hmesa hi false hoga
				dp[0][j] = false;
			}
			else if (j == 0) { //for first col, means s = ""
				//crucial h, wv
				if (p[i - 1] == '*') {
					// Here, you need to think (WV)
					dp[i][j] = dp[i - 2][j]; // i-2 kbhi out of bound nhi jaega, as "p" ki starting "*" se nhi ho skti (think,WV)
				}
				else {
					dp[i][j] = false;
				}
			}
			//initializastion ends

			else { //crucial part, WV
				char patternChar = p[i - 1];
				char stringChar = s[j - 1];

				if (patternChar == '*') {
					if (dp[i - 2][j]) { //i-2 kbhi out of bound nhi jaega, as "p" ki starting "*" se nhi ho skti (think,WV)
						dp[i][j] = true;
					}
					else {
						char pslc = p[i - 2]; //i-1 last char ke lie(coz indexing of dp is one more than indexing of s and p), so second last char i-2 hoga
						// pslc --> pattern second last char
						if (pslc == '.' or pslc == stringChar) {
							dp[i][j] = dp[i][j - 1]; //ye sochna kinda muskil h, so WV
						}
					}
				}
				else if (patternChar == '.') {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else if (patternChar == stringChar) {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else { // patternchar != stringChar
					dp[i][j] = false;
				}
			}
		}
	}
	return dp[dp.size() - 1][dp[0].size() - 1];
}

int main() {
	/*********************************
	LEETCODE: https://leetcode.com/problems/regular-expression-matching/
	VIDEO LINK: https://www.youtube.com/watch?v=DJvw8jCmxUU
	*********************************/
	string s = "aa";
	string p = "a*";

	bool ans = editDistance(s, p);
	if (ans) cout << "true";
	else cout << "false";
}