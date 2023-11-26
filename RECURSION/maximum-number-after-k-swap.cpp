#include <bits/stdc++.h>
using namespace std;

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
				swap(str[i], str[j]);
				helperRecursive(str, k - 1, maxString);
				swap(str[i], str[j]);
			}
		}
	}
}

string findMaximumNum(string str, int k) {
	string maxString = str;
	for (int i = 0; i < str.size() - 1; i++) {
		for (int j = i + 1; j < str.size(); j++) {
			if (str[j] > str[i]) {
				swap(str[i], str[j]);
				helperRecursive(str, k - 1, maxString);
				swap(str[i], str[j]);
			}
		}
	}
	return maxString;
}

int main()
{
	/*
	NOTE: giving TLE On gfg
	VIDEO LINK: https://www.youtube.com/watch?v=5crucASFoA4
	QUESTION LINK: https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1
	QUESTION:
	1. You are given a string which represents digits of a number.
	2. You have to create the maximum number by performing at-most k swap operations on its digits.
	*/
	string str = "1234567";
	int k = 4;
	cout << findMaximumNum(str, k);
}