#include<bits/stdc++.h>
using namespace std;

string removeOutterMostParenthesis(string str) {
	stack<char> st;
	string ans = "";

	for (char ele : str) {
		if (ele == '(') {
			if (st.empty()) {
				st.push(ele);
			}
			else { //stack not empty
				st.push(ele);
				ans += ele;
			}
		}
		else { // ele == ')'
			//agr closing hai toh opening jrur hoga stack me, given in question that the parenthesis are valid
			st.pop(); //for corresponding '(' bracket
			if (!st.empty()) { // '(' pop krne ke baad if stack is not empty means ye inner parenthesis tha, so add it in ans string
				ans += ele;
			}
		}
	}
	return ans;
}

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=MLfAFCkzChU&list=PL-Jc9J83PIiE1_SifBEWRsD-fzxrvkja9&index=11
	LEETCODE LINK:
	*/
	string str = "(()())(())(()(()))";
	cout << removeOutterMostParenthesis(str);;
}