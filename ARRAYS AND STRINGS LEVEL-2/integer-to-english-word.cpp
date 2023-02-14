#include <bits/stdc++.h>
using namespace std;

vector<pair<int, string>> arr = {{1000000000, "Billion"}, {1000000, "Million"},
	{1000, "Thousand"}, {100, "Hundred"}, {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"},
	{60, "Sixty"}, {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"}, {20, "Twenty"}, {19, "Nineteen"},
	{18, "Eighteen"}, {17, "Seventeen"}, {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"},
	{13, "Thirteen"}, {12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"},
	{7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}
};

string integerToEnglish(int num) {
	//this is edge case not base case
	if (num == 0)  return "Zero";

	string ans = "";
	for (auto it : arr) {
		ans = "";
		if (num >= it.first) { //two recursive calls lgegi
			//left call
			if (num >= 100) {
				ans += integerToEnglish(num / it.first);
				ans += " ";
			}
			ans = ans + it.second;
			//right call
			if (num % it.first != 0) {
				ans = ans + " " + integerToEnglish(num % it.first);
			}
			return ans;
		}

	}

}

int main() {
	/*********************************
	 * NOTE: recursion is used here.
	 * SIMILAR CONCEPT: integer to roman
	 * NOTE: this code is copied from leetcode with my changes
	// LEETCODE LINK: https://leetcode.com/problems/integer-to-english-words/description/
	//*********************************/
	int num = 123;
	cout << integerToEnglish(num) << endl;
}