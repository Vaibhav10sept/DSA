#include <bits/stdc++.h>
using namespace std;

int minFlipsHelper(string& str) {
	//nice logic, wv, think ,cs  dry run
	//LOGIC: there can be only two cases
	//excample if str is 110
	//then case1         101 --> even me 1 hai
	//and  case2         010 --> even me 0 hai
	string case1 = ""; //even index has 1
	string case2 = ""; //even index has 0
	int n = str.size();

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) { //even index
			case1 += '1';
			case2 += '0';
		}
		else { //odd index
			case1 += '0';
			case2 += '1';
		}
	}

	//compare case1 and case2 with given string and return the min flip
	int case1Flips = 0;
	int case2Flips = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] != case1[i]) case1Flips++;
		if (str[i] != case2[i]) case2Flips++;
	}

	return min(case1Flips, case2Flips);
}

int switchFirstAndLast(string str) {
	string originalString = str;
	int n = str.size();
	int minFlipsAns = INT_MAX;
	string newString = originalString;

	minFlipsAns = min(minFlipsAns, minFlipsHelper(originalString));
	for (int i = 0; i < n - 1; i++) {
		char first = newString[0];
		newString.erase(0, 1);
		newString += first;
		// cout << "new " << newString << endl;
		minFlipsAns = min(minFlipsAns, minFlipsHelper(newString));
	}
	return minFlipsAns;
}


int main() {
	/************************************
	 * NOTE: giving TLE
	 * QUESTION: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/
	// VIDEO LINK: https://www.youtube.com/watch?v=MOeuK6gaC2A
	//************************************/
	string s = "01001001101";
	cout << "ans " << switchFirstAndLast(s);
}


