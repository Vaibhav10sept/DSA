#include <bits/stdc++.h>
using namespace std;
void insertBottom(stack<int> &st, int ele) {
	if (st.empty()) {
		st.push(ele);
		return;
	}
	int num = st.top();
	st.pop();
	insertBottom(st, ele);
	// if (num != -1)

	st.push(num);
}
void reverse(stack<int> &st) {
	if (st.empty()) return;

	int ele = st.top();
	st.pop();
	reverse(st);
	insertBottom(st, ele);
	// st.push(ele);
}
int main() {
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);

	reverse(st);


	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
}