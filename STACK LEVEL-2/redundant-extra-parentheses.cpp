#include<bits/stdc++.h>
using namespace std;

int checkRedundancy(string str) {
	// NOTE: i wrote this
	stack<int> st;

	for (char ch : str) {
		if (ch == '(') st.push(ch);

		else if (ch == '+' or ch == '*' or ch == '-' or ch == '/') {
			st.push(ch);
		}

		else if (ch == ')') {
			//NOTE: st empty nhi hogi cause question me bracket valid h, to empty hone ka sawal hi paeda nhi hota
			if (st.top() == '(') return true;

			else { //operator hoge
				while (st.top() != '(') st.pop();
				//now st ke top me ( hoga
				st.pop();
			}
		}
	}
	return false;
}

int main() {
	/*
	NOTE: i wrote this
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=azYOlJh9z8U
	LEETCODE LINK: https://practice.geeksforgeeks.org/problems/expression-contains-redundant-bracket-or-not/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
	*/
	string exp = "((a+b))";
	if (checkRedundancy(exp)) {
		cout << "yes";
	}
	else cout << "no";
}