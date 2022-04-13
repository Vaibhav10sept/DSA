#include <bits/stdc++.h>
using namespace std;

string mySwap(string str, int i, int j) {
	char temp = str[i];
	str[i] = str[j];
	str[j] = temp;
	return str;
}


void helperRecursive(string str, int k, string &maxString) {
	if (str > maxString) {
		maxString = str;
	}
	if (k == 0) {
		return;
	}
	for (int i = 0; i < str.size() - 1; i++) {
		for (int j = i + 1; j < str.size(); j++) {
			if (str[j] > str[i]) {
				string swapped = mySwap(str, i, j);
				helperRecursive(swapped, k - 1, maxString);
			}
		}
	}
}

string maxNumberAfterKSwaps(string str, int k) {
	string maxString = "";
	for (int i = 0; i < str.size() - 1; i++) {
		for (int j = i + 1; j < str.size(); j++) {
			if (str[j] > str[i]) {
				string swapped = mySwap(str, i, j);
				helperRecursive(swapped, k - 1, maxString);
			}
		}
	}
	return maxString;
}

int main()
{
	/*
	VIDEO LINK: https://www.youtube.com/watch?v=5crucASFoA4
	QUESTION:
	1. You are given a string which represents digits of a number.
	2. You have to create the maximum number by performing at-most k swap operations on its digits.

	Note -> Check out the question video and write the recursive code as it is intended without
	               changing signature. The judge can't force you but intends you to teach a concept.
	*/
	string str = "1234567";
	int k = 4;
	cout << maxNumberAfterKSwaps(str, k);
}