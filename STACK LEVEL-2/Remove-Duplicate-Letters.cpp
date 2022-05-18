#include<bits/stdc++.h>
using namespace std;

string removeDuplicateLetters(string str) {
	map<char, int> freqMap;
	stack<char> st;
	vector<bool> visited(26, false);

	//fill the freqmap
	for (char ele : str) freqMap[ele]++;

	for (char ele : str) {
		freqMap[ele]--;

		if (visited[ele - 'a']) continue;

		while (!st.empty() and st.top() > ele and freqMap[st.top()] > 0) {
			visited[st.top() - 'a'] = false;
			st.pop();
		}

		st.push(ele);
		visited[ele - 'a'] = true; //ele - 'a' --> gives the index.
	}
	//make ans string using stack in same order
	string ans = "";
	while (!st.empty()) {
		ans = st.top() + ans;
		st.pop();
	}
	return ans;
}

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=luCn7p2CIbI
	LEETCODE LINK:
	*/
	string str = "cbacdcbc";
	cout << removeDuplicateLetters(str);
}