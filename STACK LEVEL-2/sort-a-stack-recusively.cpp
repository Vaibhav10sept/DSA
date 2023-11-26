#include<bits/stdc++.h>
using namespace std;

void DisplayStack(stack<int> s) {
	while (!s.empty()) {
		// Print the elements
		cout << (s.top()) << " ";
		s.pop();
	}
}

void sortInsert(stack<int> &st, int ele) {
	// Base case: Either stack is empty or newly inserted
	// item is greater than top (more than all existing)
	if (st.empty() or ele >= st.top()) {
		st.push(ele);
		return;
	}

	int temp = st.top();
	st.pop();

	sortInsert(st, ele);
	st.push(temp);
}

void sortStackUsingRecusion(stack<int> &st) {
	if (st.empty()) return;

	int num = st.top();
	st.pop();

	sortStackUsingRecusion(st);

	// Push the top item back in sorted stack
	sortInsert(st, num);
}

int main() {
	/*
	SIMILAR CODE PATTERN: REVERSE A STACK USING RECURSION.
	LINK: https://www.geeksforgeeks.org/sort-a-stack-using-recursion/
	VIDEO LINK: no video just read the article on gfg
	LEETCODE LINK: https://practice.geeksforgeeks.org/problems/sort-a-stack/1
	*/
	stack<int> st;
	st.push(11);
	st.push(2);
	st.push(32);
	st.push(3);
	st.push(41);
	sortStackUsingRecusion(st);
	DisplayStack(st);
}