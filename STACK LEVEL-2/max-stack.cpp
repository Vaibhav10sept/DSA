#include <bits/stdc++.h>
using namespace std;

class MaxStack {
public:
	stack<int> st, max;

	void push(int val) {
		st.push(val);
		int maxVal = val;
		if (max.size() > 0) maxVal = std::max(maxVal, max.top());
		max.push(maxVal);
	}

	int pop() {
		max.pop();
		int data = st.top();
		st.pop();
		return data;
	}

	int top() {
		return st.top();
	}

	int peekMax() {
		return max.top();
	}

	int popMax() { //ye sbse crucial method hai, ache se pdna
		int toBeRemoved = max.top();
		stack<int> buffer;

		//pop krte hue(pop dono se hoga(st and max)) buffer me daal do
		while (st.top() != toBeRemoved) {
			buffer.push(this->pop());
		}
		this->pop(); //last vala pop for data.top() == toBeRemoved

		//ab buffer se st me daal do using this->push(think)
		while (!buffer.empty()) {
			this->push(buffer.top());
			buffer.pop();
		}

		return toBeRemoved;
	}

};

int main()
{
	/*
	memory: O(n)
	time: popMax --> O(n)
	VIDEO LINK: https://www.youtube.com/watch?v=z5hFSEFf6Mg&list=PL-Jc9J83PIiE1_SifBEWRsD-fzxrvkja9&index=30
	 LEETCODE: paid
	*/
	MaxStack obj = MaxStack();
	obj.push(5);
	obj.push(1);
	obj.push(5);
	cout << obj.top() << endl;
	obj.push(3);
	cout << obj.popMax() << endl;
	cout << obj.top() << endl;
	cout << obj.peekMax() << endl;
	cout << obj.popMax() << endl;
	cout << obj.pop() << endl;
	cout << obj.peekMax() << endl;
	cout << obj.pop() << endl;
}