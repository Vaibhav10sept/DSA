#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b) {
	//NOTE: I wrote this code without any video or solution all by myself
	int i = a.size() - 1;
	int j = b.size() - 1;
	int carry = 0;
	string ans = "";
	while (i >= 0 or j >= 0) {
		int sum = carry;
		if (i >= 0) sum = sum + (a[i] - '0');
		if (j >= 0) sum = sum + (b[j] - '0');

		carry = sum / 2;
		int val = sum % 2;

		char charVal = val + '0';
		ans = charVal + ans;

		i--;
		j--;
	}
	if (carry) {
		char charCarry = carry + '0';
		ans = charCarry + ans;
	}
	return ans;
}

int main() {
	//*********************************
	//NOTE: I wrote this code without any video or solution all by myself
	// LEETCODE: https://leetcode.com/problems/add-binary/description/
	//*********************************
	string a = "11";
	string b = "1";
	cout << addBinary(a, b);
}