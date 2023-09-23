#include<bits/stdc++.h>
using namespace std;

void singleMultiply(int val, string s1, int k, vector<int> &ans) {
	int  carry = 0;
	for (int i = s1.size() - 1; i >= 0; i--) {
		int mul = (s1[i] - '0') * val + carry;
		carry = mul / 10;
		mul = mul % 10;
		ans[k] += mul;

		if (ans[k] > 9) {
			int kCarry = ans[k] / 10;
			ans[k] = ans[k] % 10;
			ans[k - 1] += kCarry;
		}
		k--;
	}
	// cout << "car " << carry << endl;
	if (carry != 0) {
		ans[k] += carry;

	}
	// for (auto ele : ans) cout << ele << " ";
	// cout << endl;
}

string multiplyStrings(string s1, string s2) {
	// NOTE: I wrote with code without any video or solution all by myself

	if (s1 == "0" or s2 == "0") return "0"; //edge case
	vector<int> ans(s1.size() + s2.size(), 0);
	int k = ans.size() - 1;
	int kIncrement = 0;

	for (int j = s2.size() - 1; j >= 0; j--) {
		int s2Val = s2[j] - '0';
		k = ans.size() - 1 - kIncrement;
		singleMultiply(s2Val, s1, k, ans);
		kIncrement++;
	}

	string res = "";
	int i = 0;
	while (ans[i] == 0) i++;
	while (i < ans.size()) {
		char charVal = ans[i] + '0';
		res = res + charVal;
		i++;
	}

	return res;
}


int main() {
	/*
	NOTE: I wrote with code without any video or solution all by myself
	LEETCODE: https://leetcode.com/problems/multiply-strings/description/
	*/
	string num1 = "123";
	string num2 = "456";
	cout << multiplyStrings(num1, num2);
}