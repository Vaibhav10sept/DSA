#include <bits/stdc++.h>
using namespace std;


queue<int> reverseQueue(queue<int> q, int k) {
	// NOTE: i wrote it
	stack<int> st;
	queue<int> tempq;

	while (k--) {
		st.push(q.front());
		q.pop();
	}

	while (!q.empty()) {
		tempq.push(q.front());
		q.pop();
	}

	//q is empty
	while (!st.empty()) {
		q.push(st.top());
		st.pop();
	}
	while (!tempq.empty()) {
		q.push(tempq.front());
		tempq.pop();
	}

	return q;
}

int main()
{
	/*
	NOTE: i wrote it
	STRONG PREQ:
	QUESTION: https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1
	*/
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	int k = 3;

	queue<int> ans = reverseQueue(q, k);
	while (!ans.empty()) {
		cout << ans.front() << endl;
		ans.pop();
	}
}

