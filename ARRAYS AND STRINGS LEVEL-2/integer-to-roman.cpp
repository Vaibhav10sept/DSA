#include <bits/stdc++.h>
using namespace std;

string integerToRoman(int num) {
	// WV recommended
	vector<pair<int, string>> arr = {
		{1000, "M"},
		{900,  "CM"},
		{500,  "D"},
		{400,  "CD"},
		{100,  "C"},
		{90,   "XC"},
		{50,   "L"},
		{40,   "XL"},
		{10,   "X"},
		{9,    "IX"},
		{5,    "V"},
		{4,    "IV"},
		{1,    "I"}
	};
	string ans = "";

	for (auto it : arr) {
		while (num > 0 and num >= it.first) {
			int qout = num / it.first;
			cout << "ques " << qout << endl;
			cout << "it.first " << it.first << " it.second " << it.second << endl;
			cout << "num " << num % it.first << endl;
			num = num % it.first;
			while (qout--) {
				ans += it.second;
			}
		}
	}
	return ans;
}

int main() {
	/*********************************
	 * SIMILAR CONCEPT: integer to english
	// VIDEO LINK: https://www.youtube.com/watch?v=Rsq1ObYg6ak
	// LEETCODE LINK: https://leetcode.com/problems/integer-to-roman/solutions/2681343/c-using-map/
	//*********************************/
	int num = 94;
	cout << integerToRoman(num) << endl;
}