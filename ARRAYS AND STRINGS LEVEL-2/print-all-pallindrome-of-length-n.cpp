#include <bits/stdc++.h>
using namespace std;

void printAllPallindromeOfN(int n) {
	// if (n == 1) {
	// 	for (int i = 0; i < 10; i++)
	// 		cout << i << endl;
	// 	return;
	// }
	long long len = 0, pre = 0;
	if (n % 2 == 0) len = n / 2 - 1;
	else len = (n / 2);
	pre = (int)pow(10, len);

	if (pre % 10 == 9) pre++; //this is for this compiler only, i think something is wrong with this(sublime text) compiler
	// cout << pre << " pre" << endl;

	int end = pow(10, len + 1);
	if (end % 10 == 9) end++; //this is for this compiler only, i think something is wrong with this(sublime text) compiler
	// cout << end << " end" << endl;

	for (int i = pre; i < end; i++) {
		int temp = i;
		if (n % 2 != 0) {
			temp /= 10;
		}
		string rev = to_string(temp);
		reverse(rev.begin(), rev.end());
		string ans = to_string(i);
		if (rev != "0")
			ans += rev;
		cout  << ans << endl;
	}
}


int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=W8bpOKpPtPA
	// LINK: https://leetcode.com/contest/weekly-contest-286/problems/find-palindrome-with-fixed-length/
	//*********************************
	int n = 3;
	printAllPallindromeOfN(n);
}