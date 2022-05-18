#include<bits/stdc++.h>
using namespace std;

int solve(int val1, int val2, string opertor) {
	if (opertor == "+") {
		return val1 + val2;
	}
	else if (opertor == "-") {
		return val1 - val2;
	}
	else if (opertor == "/") {
		return val1 / val2;
	}
	else if (opertor == "*") {
		return val1 * val2;
	}
	return 0;
}

int evaluatePostfixExpression(vector<string> arr) {
	stack<int> st;
	for (string ele : arr) {
		if (ele == "+" or ele == "-" or ele == "*" or ele == "/") {
			int val2 = st.top();
			st.pop();
			int val1 = st.top();
			st.pop();
			int res = solve(val1, val2, ele);
			st.push(res);
		}

		else { //operand
			st.push(stoi(ele));
		}
	}
	return st.top();
}

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK:
	LEETCODE LINK: https://leetcode.com/problems/evaluate-reverse-polish-notation/
	*/
	vector<string> arr = {"4", "13", "5", "/", "+"};
	// vector<string> arr = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
	cout << evaluatePostfixExpression(arr);
}