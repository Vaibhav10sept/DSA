#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:
	int maxSize;
	int* stackArray;
	int top;

	MyStack(int s) {
		maxSize = s;
		stackArray = new int[maxSize];
		top = -1;
	}
	void push(int j) {
		stackArray[++top] = j;
	}
	int pop() {
		return stackArray[top--];
	}
	int peek() {
		return stackArray[top];
	}
	bool isEmpty() {
		return (top == -1);
	}
	bool isFull() {
		return (top == maxSize - 1);
	}
};

int main() {
	MyStack st(10);

	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);

	while (!st.isEmpty()) {
		int value = st.pop();
		cout << value << " ";
	}
}