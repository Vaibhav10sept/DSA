#include<bits/stdc++.h>
using namespace std;

bool validateStackSequences(vector<int> pushed, vector<int> popped) {
	//watch video to understand the logic.
	stack<int> st;
	int j = 0; //iterate through popped array.

	for (int ele : pushed) {
		st.push(ele);
		while (!st.empty() and st.top() == popped[j]) {
			st.pop();
			j++;
		}
	}

	//agr j popped vector ke end pr pahuch gya, means valid stack sequence hai(think)
	return j == popped.size();
}

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=KsIeZfmvuVQ&list=PL-Jc9J83PIiE1_SifBEWRsD-fzxrvkja9&index=8
	LEETCODE LINK: https://leetcode.com/problems/validate-stack-sequences/
	*/
	vector<int> pushed = {1, 2, 3, 4, 5};
	vector<int> popped = {4, 5, 3, 2, 1};
	bool ans = validateStackSequences(pushed, popped);
	if (ans) cout << "true";
	else cout << "false";
}