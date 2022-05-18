#include<bits/stdc++.h>
using namespace std;

string lexicographicallySmallestSubsequence(string str, int k) {
	//acha question hai, nice logic, read comments for better understanding.
	stack<char> st;
	string ans = "";
	int n = str.size();
	for (int i = 0; i < n; i++) {
		//valid and greater ko stack se remove kro
		//valid --> uss str[i] ke baad (k-st.size()) bnde hone chahie tbhi ham k size tk pahuch paege(think)
		//required--> kitne ele or chahie k pura krne ke lie --> k-st.size().
		//remaining --> str[i] ke age kitne ele hai str me --> n-i-1
		//so, remaining >= required. while ki condition dekho
		while (!st.empty() and st.top() > str[i] and n - i - 1 >= k - st.size()) {
			st.pop();
		}

		if (st.size() < k) st.push(str[i]);
	}

	//filling up "ans" string using stack, preserving the order
	while (!st.empty()) {
		ans = st.top() + ans;
		st.pop();
	}
	return ans;
}

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=wuwE7g8VvgQ&list=PL-Jc9J83PIiE1_SifBEWRsD-fzxrvkja9&index=27
	LEETCODE LINK: NOT IN LEETCODE
	*/
	string str = "3526";
	int k = 3;
	cout << lexicographicallySmallestSubsequence(str, k);
}