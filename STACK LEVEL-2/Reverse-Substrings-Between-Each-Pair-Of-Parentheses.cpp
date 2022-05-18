#include<bits/stdc++.h>
using namespace std;

string reverseSubstringsBetweenEachPairOfParentheses(string str) {
	string ans = "";
	stack<char> st;

	for (char ele : str) {
		if (ele == '(') {
			st.push(ele);
		}

		else if (ele == ')') {
			queue<char> q;
			while (st.top() != '(') {
				q.push(st.top());
				st.pop();
			}
			st.pop(); //for one '('
			//add the char from queue to stack
			while (!q.empty()) {
				st.push(q.front());
				q.pop();
			}
		}

		else { //char
			st.push(ele);
		}
	}

	//st ko ans string me daal do.
	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=4a4bspKyOH8&list=PL-Jc9J83PIiE1_SifBEWRsD-fzxrvkja9&index=12
	LEETCODE LINK:
	*/
	string str = "(u(love)i)";
	cout << reverseSubstringsBetweenEachPairOfParentheses(str);
}