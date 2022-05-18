#include<bits/stdc++.h>
using namespace std;

string minimumRemovetoMakeValidParentheses(string str) {
	stack<int> st; //index store hoge isme

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			st.push(i);
		}
		else if (str[i] == ')') {
			if (st.empty()) {
				// this ")" bracket is invalid
				// ham isi string me mark krlege using '.'
				str[i] = '.';
			}
			else { //stack not empty
				st.pop(); // ye "(" pop krega
			}
		}
	}
	//handle the remaining '(' in stack
	//coz, stack me bache hue '(' bhi invalid hote hai
	while (!st.empty()) {
		str[st.top()] = '.';
		st.pop();
	}

	//creating ans string by replacing '.' with ''(nothing)
	string ans = "";
	for (auto ele : str) {
		if (ele != '.') ans += ele;
	}
	return ans;
}

int main() {
	/*
	PREREQUISITE: min add to make parenthesis valid.
	VIDEO LINK: https://www.youtube.com/watch?v=Givpwgu9IIc&list=PL-Jc9J83PIiE1_SifBEWRsD-fzxrvkja9&index=14
	LEETCODE LINK:
	*/
	string str = "a)b(c)d";
	cout << minimumRemovetoMakeValidParentheses(str);
}