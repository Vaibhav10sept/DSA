#include <bits/stdc++.h>
using namespace std;

int test(string current, string correct) {
	int hr1 = stoi(current.substr(0, 2));
	int hr2 = stoi(correct.substr(0, 2));

	int min1 = stoi(current.substr(3));
	int min2 = stoi(correct.substr(3));

	// cout << min2;
	int hrdiff = abs(hr2 - hr1);
	// cout << hrdiff << endl;
	int mindiff = abs(min2 - min1);
	cout << "mindiff " << mindiff << endl;

	int ans = 0;
	ans += hrdiff;
	if (mindiff % 60 == 0) {
		ans += mindiff / 60;
	}
	else if (mindiff % 15 == 0) {
		ans += mindiff / 15;
	}
	else if (mindiff % 5 == 0) {
		cout << "5 " << mindiff / 5 << endl;
		ans += mindiff / 5;
	}
	else {
		ans += mindiff;
	}

	// while (mindiff) {
	// 	// cout << "while " << mindiff << endl;
	// 	if (mindiff >= 60) {
	// 		mindiff -= 60;
	// 	}
	// 	else if (mindiff >= 15) {
	// 		mindiff -= 15;
	// 	}
	// 	else if (mindiff >= 5) {
	// 		// cout << "5 run" << endl;
	// 		mindiff -= 5;
	// 	}
	// 	else {
	// 		mindiff--;
	// 	}
	// 	ans++;
	// }
	return ans;
}


int main() {
	//*********************************
	// NOTE:
	// LEETCODE LINK: https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/
	// VIDEO LINK: https://www.youtube.com/watch?v=PIs1EArGpIQ&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=76
	//*********************************
	// string current = "02:30";
	// string correct = "04:35";

	string current = "09:41";
	string correct = "10:34";
	cout << "ans " << test(current, correct);
}