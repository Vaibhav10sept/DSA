#include <bits/stdc++.h>
using namespace std;

string multiplyStrings(string n1, string n2) {
	vector<int> res(n1.size() + n2.size());
	int powerFactor = 0;
	int k = res.size() - 1 - powerFactor;
	for (int i = n1.size() - 1; i >= 0; i--) {
		int carry = 0;
		k = res.size() - 1 - powerFactor;
		for (int j = n2.size() - 1; j >= 0; j--) {
			int firstDigit = n1[i] - '0';
			int secondDigit = n2[j] - '0';
			int product = firstDigit * secondDigit + carry + res[k];
			carry = product / 10;
			res[k] = product % 10;
			k--;
		}
		if (carry != 0) {
			res[k] += carry;
		}
		powerFactor++;
	}

	//we don't want to print leading zeros
	int i = 0;
	while (res[i] == 0) i++;
	string ans = "";

	for (; i < res.size(); i++) ans += to_string(res[i]);
	return ans;
}

int main() {
	//*********************************
	// NOTE: one more my written solution is there
	// VIDEO LINK: https://www.youtube.com/watch?v=5NdhK3tZViQ&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=29
	// QUESTION:
	// 1. Given two non-negative integers num1 and num2 represented as strings.
	// 2. Return the product of num1 and num2, also represented as a string.
	// 3. Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
	//*********************************
	string	n1 = "100";
	string n2 = "12";
	cout << multiplyStrings(n1, n2);
}