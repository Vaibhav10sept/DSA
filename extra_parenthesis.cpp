#include <bits/stdc++.h>
using namespace std;

int main() {
	string exp = "(a+b)";
	stack<char> st;
	for (int i = 0; i < exp.size(); i++) {
		char ch = exp[i];
		if (ch == '(') {
			st.push(ch);
		}
		else if (ch == ')')  {
			if (st.top() == '(') {
				cout << "true";
				return 0;
			}
			while (st.size() > 0 and st.top() != '(') st.pop();
			st.pop();

		}

		else if (ch == '+') {
			st.push(ch);
		}
	}
	cout << "false";
}