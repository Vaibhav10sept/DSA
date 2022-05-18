#include <bits/stdc++.h>
using namespace std;

/*
LOGIC:
1.min variable me ham min val store krte h
2.min se bdi val ati h to use direct push krte h
3.agr min se choti val ati h to stack me fake val(val + val - min), jo ki min se choti hoti h, vo store krte hai or original val min me jati h
4.agr kisi moment me stack ko top pe min se choti val h, means case 3 hua h, we get original val from min and new min from stack top
*/

class MinStack {
public:
	stack<long> st;
	long minVal = INT_MAX;
	void push(int val) {
		if (st.size() == 0) {
			st.push(val);
			minVal = val;
		}
		else if (val >= minVal) { //case 2
			st.push(val);
		}
		else { //case 3
			st.push(val + (val - minVal)); //(val + val - minVal)--> fake value is always less than minVal, this help us to detect that minVal is changed here
			minVal = val; //original val stored in minVal.
		}
	}

	void pop() {
		if (st.top() >= minVal) {
			//simple pop
			st.pop();
		}

		else { // see case 4.
			//means st.top me fake val store hai
			//means minVal me original val store hai
			//todo: extract the minVal using, minVal and data.top()
			//don't memorize the formula derive it:
			minVal = 2 * minVal - st.top(); //restore minVal
			st.pop();
		}
	}

	int top() {
		if (st.top() >= minVal) {
			//simple return
			return st.top();
		}
		else { // see case 4.
			//means st.top me fake val store hai
			//means minVal me original val store hai
			return minVal;
		}
	}

	int getMin() {
		return minVal;
	}

};

int main()
{
	/*
	memory: O(1)
	time: O(1)
	VIDEO LINK: https://www.youtube.com/watch?v=Trz7JM610Uc
	LEETCODE LINK: https://leetcode.com/problems/min-stack/
	*/
	MinStack minStack = MinStack();
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	cout << minStack.getMin() << endl; // return -3
	minStack.pop();
	cout << minStack.top() << endl; // return 0
	cout << minStack.getMin() << endl; // return -2
}