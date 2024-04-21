#include <bits/stdc++.h>
using namespace std;

int romanToInteger(string str) {
	// WV recommended
	// I wrote this code just after understanding the approach from the video
	unordered_map<char, int> mp = { { 'I' , 1 },
		{ 'V' , 5 },
		{ 'X' , 10 },
		{ 'L' , 50 },
		{ 'C' , 100 },
		{ 'D' , 500 },
		{ 'M' , 1000 }
	};
	int ans = 0;
	for (int i = 0; i < str.size(); i++) {
		if (i < str.size() and mp[str[i]] < mp[str[i + 1]]) { //means its negative value, ex: CM -> 900
			ans += (mp[str[i]] * -1); //so, we are adding -ve of mp[i] to ans
		}
		else {
			//add it normally
			ans += mp[str[i]];
		}
	}
	return ans;
}

int main() {
	/*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=3jdxYj3DD98
	// LEETCODE LINK: https://leetcode.com/problems/roman-to-integer/
	//*********************************/
	string s = "LVIII";
	cout << romanToInteger(s) << endl;
}