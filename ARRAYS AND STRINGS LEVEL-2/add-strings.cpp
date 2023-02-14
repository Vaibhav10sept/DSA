#include <bits/stdc++.h>
using namespace std;

string addStrings(string n1, string n2) {
	int i1 = n1.size() - 1;
	int i2 = n2.size() - 1;
	int carry = 0;
	string res = "";
	while (i1 >= 0 and i2 >= 0) {
		int firstDigit = n1[i1] - '0'; //char to int
		int secondDigit = n2[i2] - '0';

		int sum = firstDigit + secondDigit + carry;
		int remainder = sum % 10;
		carry = sum / 10;
		char remainderCh = remainder + '0'; //int to char
		res = remainderCh + res;
		i1--;
		i2--;
	}

	while (i1 >= 0) {
		int firstDigit = n1[i1] - '0';
		int sum = firstDigit + carry;
		char sumCh = sum + '0';
		res = sumCh + res;
		carry = 0;
		i1--;
	}

	while (i2 >= 0) {
		int firstDigit = n2[i2] - '0';
		int sum = firstDigit + carry;
		char sumCh = sum + '0';
		res = sumCh + res;
		carry = 0;
		i2--;
	}
	return res;
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=6KWwfw43fOg&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=28
	// QUESTION:
	// 1. Given two non-negative integers, num1 and num2 represented as string.
	// 2. Return the sum of num1 and num2 as a string.
	// 3. You must solve the problem without using any built-in library for handling large integers (such as BigInteger).
	// 4. You must also not convert the inputs to integers directly.
	//*********************************
	string	n1 = "11234";
	string n2 = "897";
	cout << addStrings(n1, n2);
}