#include<bits/stdc++.h>
using namespace std;

void cal(int val, char sign, stack<int> &st) {
	if (sign == '-') {
		val = -val;
		st.push(val);
	}
	else if (sign == '+') {
		st.push(val);
	}
	else if (sign == '*') { // * or /
		int firstVal = st.top();
		st.pop();
		st.push(firstVal * val);
	}
	else { // sign == '/'
		int firstVal = st.top();
		st.pop();
		st.push(firstVal / val);
	}
}
class UtilPair {
public:
	stack<int> st;
	char sign;

	UtilPair(stack<int> st, char sign) {
		this->st = st;
		this->sign = sign;
	}
};

int basicCalculator2(string str) {
	stack<int> st;
	stack<UtilPair> parenthesisStack;
	char sign = '+';

	for (int i = 0; i < str.size(); i++) {
		char ch = str[i];
		if (isdigit(ch)) {
			//get the whole number, like if ch is '1' then iterate further to get the number like '15'
			int val = 0;
			while (i < str.size() and isdigit(str[i])) {
				val = val * 10 + (str[i] - '0');
				i++;
			}
			i--; //coz, i ab ek no digit pe aa gya, or outer for loop se vo ek age or bdh jaega, ek char miss kr dega islie i-- kia
			//push val in operand stack

			cal(val, sign, st);
			sign = '+';
		}
		else if (ch == ' ') continue;
		else if (ch == '(') {
			//save: jo bhi kuch hai sab save krdo like st and sign into the parenthesisStack using the class UtilPair
			parenthesisStack.push(UtilPair(st, sign));
			//reset: reset the st and sign
			st = stack<int>(); //rem: this is the syntax for clearing the stack. clear() method nhi hota stack me as in case of vector.
			sign = '+';
		}
		else if (ch == ')') {
			//calculate what is there in the st
			int ans = 0;
			while (!st.empty()) {
				int val = st.top();
				st.pop();
				ans += val;
			}

			//restore: what we have stored in the parenthesisStack
			UtilPair obj = parenthesisStack.top();
			parenthesisStack.pop();
			st = obj.st;
			sign = obj.sign;

			//now, as the sign do the calculation jo hm "if (isdigit(ch))" is condition pe krte hai(above code)
			cal(ans, sign, st);
			sign = '+';
		}
		else { //operator
			sign = ch;
		}
	}

	int ans = 0;
	while (!st.empty()) {
		int val = st.top();
		st.pop();
		ans += val;
	}
	return ans;
}

int main() {
	/*
	PREREQUISITE: basic calculator 2 better solution and basic calculator
	NOTE: this code can be derived from basic calculator 2 better solution
	VIDEO LINK: https://www.youtube.com/watch?v=s_EKZnQUOp0&t=552s
	LEETCODE LINK: paid hai
	QUESTION: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/stacks/basic-calculator-3-official/ojquestion
	*/
	string  str = "2*(5+5*2)/3+(6/2+8)";
	cout << basicCalculator2(str);
}