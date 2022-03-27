#include <bits/stdc++.h>
using namespace std;
bool isPallindrome(string str, int i, int j) {
	while (i < j) {
		if (str[i] != str[j]) return false;
	}
	return true;
}

bool validPallindrome2(string str) {
	int i = 0;
	int j = str.size() - 1;
	while (i < j) {
		if (str[i] == str[j]) {
			i++;
			j--;
		}
		else {
			// two cases will be there as we can skip atmost one element
			// case1. skip the left one(i++).
			// case2. skip the right one(j--).
			// agr inn dono me se koi bhi true hoga(pallindrome hoga). toh ham true return krege.
			return isPallindrome(str, i + 1, j) || isPallindrome(str, i, j - 1);
		}
	}

	return true;
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=nMjhRtYg2_A&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=31
	// QUESTION:
	// 1. Given a string s.
	// 2. Return true if the s can be palindrome after deleting at most one character from it.
	//*********************************
	string str = "abca";

	cout << validPallindrome2(str);
}