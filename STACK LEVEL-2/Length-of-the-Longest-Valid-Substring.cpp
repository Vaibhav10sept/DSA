#include<bits/stdc++.h>
using namespace std;

int longestValidParentheses(string str) {
	//we need two stack here
	//wv recommended
	stack<char> charStack;
	stack<int> indexStack;
	indexStack.push(-1); //rem to add this important hai(think, wv)
	int maxLength = 0;

	for (int i = 0; i < str.size(); i++) {
		char ch = str[i];

		if (ch == '(') {
			charStack.push(ch);
			indexStack.push(i);
		}
		else { //ch == ')'
			if (!charStack.empty() and charStack.top() == '(') {
				charStack.pop();
				indexStack.pop();
				//caluculate the length
				maxLength = max(maxLength, i - indexStack.top());
			}
			else { //charstack ke top me opening bracket nhi hai
				indexStack.push(i);
			}
		}
	}
	return maxLength;
}

int main() {
	/*
	PREREQUISITE: longest valid parentheses
	SAME CODE: longest valid parentheses
	VIDEO LINK: https://www.youtube.com/watch?v=qC5DGX0CPFA
	LEETCODE LINK: https://leetcode.com/problems/longest-valid-parentheses/description/
	*/
	// string str = "(()(";
	string str = "((()))";
	// string str = "))()(()";
	cout << longestValidParentheses(str);
}