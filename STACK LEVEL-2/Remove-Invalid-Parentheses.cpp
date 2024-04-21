#include<bits/stdc++.h>
using namespace std;

bool isValidParentheses(string str) {
	stack<char> st;
	for (char ch : str) {
		if (ch == '(') st.push(ch);

		else if (ch == ')') { //ch == ')
			if (st.empty()) return false;
			else {
				st.pop();
			}
		}
	}

	if (st.size() == 0) return true;
	return false;
}


int minRemoveToMakeParenthesesValid(string str) {
	//this is my own logic and code
	//this function is copied form this question --> minimum add to make parenthesis valid
	stack<char> st;
	int minRemove = 0;
	for (char ele : str) {
		if (ele == '(') {
			st.push(ele);
		}
		else if (ele == ')') { // ele == ')'
			if (st.empty()) minRemove++; //means, ele == ) hai or stack khali hai mtlb ) ke lie ( hona chahie to ans++ kra

			if (!st.empty()) {
				st.pop();
			}
		}
	}
	return st.size() + minRemove;
}

void dfs(string str, int minRemovalAllowed, vector<string> &res, set<string> &set) {
	if (set.find(str) != set.end()) { //found
		return;
	}
	else {
		set.insert(str);
	}
	//the above code will optimize the code and not give TLE(wv)

	if (minRemovalAllowed == 0) {
		if (isValidParentheses(str)) {
			res.push_back(str);
		}
		return;
	}
	//BC ends

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(' or str[i] == ')') {
			string left = str.substr(0, i);
			string right = str.substr(i + 1);
			dfs(left + right, minRemovalAllowed - 1, res, set);
		}
	}
}

vector<string> removeInvalidParentheses(string str) {
	int minRemovalToMakeParenthesesValid = minRemoveToMakeParenthesesValid(str);

	vector<string> res;
	set<string> set;
	dfs(str, minRemovalToMakeParenthesesValid, res, set);

	return res;
}

int main() {
	/*
	PREREQUISITE: minimum add to make parenthesis valid(I am using one function of this question)
	VIDEO LINK: https://www.youtube.com/watch?v=qC5DGX0CPFA
	VIDEO FOR OPTIMIZATION OF CODE: https://www.youtube.com/watch?v=y7Us-H5um0M
	LEETCODE LINK: https://leetcode.com/problems/remove-invalid-parentheses/description/
	*/
	string str = "(a)())()";
	vector<string> ans = removeInvalidParentheses(str);
	for (auto ele : ans) cout << ele << endl;
}