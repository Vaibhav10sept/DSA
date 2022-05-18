#include<bits/stdc++.h>
using namespace std;

string removeKDigits(string str, int k) {
	//nice logic vala question
	stack<char> st;
	for (char ele : str) {
		while (!st.empty() and k > 0 and st.top() > ele) {
			st.pop();
			k--;
		}
		st.push(ele);
	}

	//this is a edge case
	while (!st.empty() and k > 0) { //means ele are in increasing order,toh string ke last(last--> stack ka top hoga) se remove kro
		st.pop();
		k--;
	}

	//create answer vector using stack, fill from the last.
	vector<char> ans(st.size());
	int i = ans.size() - 1;
	while (i >= 0) {
		ans[i--] = st.top();
		st.pop();
	}

	//remove leading zeros
	i = 0;
	while (i < ans.size() and ans[i] == '0') i++;

	//create res string using ans vector
	string res = "";
	for (; i < ans.size(); i++) res += ans[i];

	if (res == "") res += '0';
	return res;
}

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=RCE2L0Zk7xE&list=PL-Jc9J83PIiE1_SifBEWRsD-fzxrvkja9&index=18
	LEETCODE LINK:
	*/
	string str = "101200";
	int k = 1;
	cout << removeKDigits(str, k);
}