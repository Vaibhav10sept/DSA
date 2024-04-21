#include <bits/stdc++.h>
using namespace std;


void reverseQueue(queue<int> &q) {
	if (q.empty()) return;
	int temp = q.front();
	q.pop();
	reverseQueue(q);
	q.push(temp);
	return;
}

int main()
{
	/*
	NOTE: i wrote it myself
	STRONG PREQ: reverse stack using recursion
	SIMILAR QUESTION: reverse stack using recursion
	QUESTION: https://practice.geeksforgeeks.org/problems/queue-reversal/1
	*/
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);

	reverseQueue(q);
	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
}

