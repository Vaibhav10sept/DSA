#include<bits/stdc++.h>
using namespace std;

void DisplayStack(stack<int> st) {
	stack<int> s = st;
	while (!s.empty()) {
		// Print the elements
		cout << (s.top()) << " ";
		s.pop();
	}
	cout << endl;
}

void insertAtBottom(stack<int> &st, int num) {
	if (st.empty()) {
		st.push(num);
		return;
	}

	int temp = st.top();
	st.pop();

	insertAtBottom(st, num);

	st.push(temp);
}

void reverseUsingRecursion(stack<int> &st) {
	//I DID THIS QUESTION MYSELF, STRONG PREREQUISITE IS ORT A STACK recusively
	if (st.empty()) return;

	int num = st.top();
	st.pop();

	reverseUsingRecursion(st);
	cout << "df " << num << endl;
	insertAtBottom(st, num);
}


int main() {
	/*
	STRONG PREREQUISITE: SORT A STACK recusively
	LINK:
	VIDEO LINK:
	LEETCODE LINK:
	*/
	stack<int> st;
	st.push(11);
	st.push(2);
	st.push(32);
	st.push(3);
	st.push(41);
	DisplayStack(st);
	reverseUsingRecursion(st);
	cout << "after reverse" << endl;
	DisplayStack(st);
}