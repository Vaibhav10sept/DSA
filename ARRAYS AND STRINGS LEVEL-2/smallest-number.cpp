#include <bits/stdc++.h>
using namespace std;

string smallestNumber(int s, int d) {
	// NOTE: wv
	//edge case
	if (d * 9 < s) return "-1"; //think, cs, wv
	string ans = "";
	for (int i = d - 1; i >= 0; i--) {
		if (s > 9) {
			ans += '9';
			s -= 9;
		}
		else { // s<=9;
			if (i == 0) {
				ans = to_string(s) + ans;
			}
			else { //i>0
				ans = to_string(s - 1) + ans;
				i--;
				while (i > 0) {
					ans = '0' + ans;
					i--;
				}
				//now, i is 0
				ans = '1' + ans;
				break;
			}
		}
	}
	return ans;
}

int main() {
	/*********************************
	 * NOTE: wv
	// VIDEO LINK: https://www.youtube.com/watch?v=H7iqIjbWty4
	// QUESTION: https://practice.geeksforgeeks.org/problems/smallest-number5829/1
	//*********************************/
	int s = 9;
	int d = 2;
	cout << smallestNumber(s, d);
}