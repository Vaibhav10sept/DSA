#include<bits/stdc++.h>
using namespace std;

void cal(int val, char sign, stack<int> &st) {
	if (sign == '-') {
		val = -val;
		st.push(val);
	}
	else if (sign == '+') {
		st.push(val);
	}
	else if (sign == '*') { // * or /
		int firstVal = st.top();
		st.pop();
		st.push(firstVal * val);
	}
	else { // sign == '/'
		int firstVal = st.top();
		st.pop();
		st.push(firstVal / val);
	}
}

int basicCalculator2(string str) {
	stack<int> st;
	char sign = '+';

	for (int i = 0; i < str.size(); i++) {
		char ch = str[i];
		if (isdigit(ch)) {
			//get the whole number, like if ch is '1' then iterate further to get the number like '15'
			int val = 0;
			while (i < str.size() and isdigit(str[i])) {
				val = val * 10 + (str[i] - '0');
				i++;
			}
			i--; //coz, i ab ek no digit pe aa gya, or outer for loop se vo ek age or bdh jaega, ek char miss kr dega islie i-- kia
			//push val in operand stack

			cal(val, sign, st);
		}
		else if (ch == ' ') continue;
		else { //operator
			sign = ch;
		}
	}

	int ans = 0;
	while (!st.empty()) {
		int val = st.top();
		st.pop();
		ans += val;
	}
	return ans;
}

int main() {
	/*
	PREREQUISITE: basic calculator and basic calculator 2
	NOTE: same question(basic calculator 2) ka ek or more intuitive solution bhi h which uses two stacks.
	VIDEO LINK: https://www.youtube.com/watch?v=gmy6L9vHTbo
	LEETCODE LINK: https://leetcode.com/problems/basic-calculator-ii/
	*/
	string  str = " 3+ 5/2";
	cout << basicCalculator2(str);
}