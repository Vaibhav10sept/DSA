#include<bits/stdc++.h>
using namespace std;

int scoreOfParentheses(string str) {
	//NOTE:
	// -1 in stack represents --> '('
	stack<int> st;
	for (char ele : str) {
		if (ele == '(') {
			st.push(-1);
		}

		else { // ele == ')'
			if (st.top() == -1) {
				st.pop();
				st.push(1);
			}
			else { //st.top() me direct '(' nhi hai, mtlb kuch scores pda hoga jise hme add krna hai
				int score = 0;

				while (st.top() != -1) { // we are not checking for st.empty() as the given string is valid parenthesis mtlb har ) ke lie koi na koi ( jarur hoga
					score += st.top();
					st.pop();
				}
				st.pop(); //for one '('
				st.push(2 * score);
			}
		}
	}

	int ans = 0;
	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}
	return ans;
}

int main() {
	/*
	PREREQUISITE: "removeOutterMostParenthesis"
	VIDEO LINK: https://www.youtube.com/watch?v=rWsv46ME6lI&list=PL-Jc9J83PIiE1_SifBEWRsD-fzxrvkja9&index=11
	LEETCODE LINK:
	*/
	// string str = "()()()";
	// string str = "((((((())))()())))";
	string str = "()";
	cout << scoreOfParentheses(str);
}