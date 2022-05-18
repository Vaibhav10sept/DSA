#include<bits/stdc++.h>
using namespace std;

int minAddToMakeParenthesesValid(string str) {
	//this is my own logic and code
	stack<char> st;
	int ans = 0;
	for (char ele : str) {
		if (ele == '(') {
			st.push(ele);
		}
		else { // ele == ')'
			if (st.empty()) ans++; //means, ele == ) hai or stack khali hai mtlb ) ke lie ( hona chahie to ans++ kra

			if (!st.empty() and st.top() == '(') {
				st.pop();
			}
		}
	}
	return st.size() + ans;
}

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=e7HyTdHAf4U&list=PL-Jc9J83PIiE1_SifBEWRsD-fzxrvkja9&index=9
	LEETCODE LINK:
	*/
	string str = "(((";
	cout << minAddToMakeParenthesesValid(str);;
}