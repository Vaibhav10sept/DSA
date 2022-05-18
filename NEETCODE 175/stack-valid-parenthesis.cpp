#include<bits/stdc++.h>
using namespace std;

bool validParenthesis(string str) {
	stack<char> st;
	for (char ele : str) {
		if (ele == '(' or ele == '{' or ele == '[') {
			st.push(ele);
		}
		else if (ele == ')') {
			if (st.empty() or st.top() != '(') return false;
			else st.pop();
		}
		else if (ele == ']') {
			if (st.empty() or  st.top() != '[') return false;
			else st.pop();
		}
		else if (ele == '}') {
			if (st.empty() or st.top() != '{') return false;
			else st.pop();
		}
		else {

		}
	}
	return st.empty();
}

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK:
	LEETCODE LINK: https://leetcode.com/problems/validate-stack-sequences/
	*/
	// string str = "()[]{}";
	string str = "){";
	cout << validParenthesis(str);
}