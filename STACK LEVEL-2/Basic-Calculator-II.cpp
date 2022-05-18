#include<bits/stdc++.h>
using namespace std;

int operation(int val1, int val2, char opertor) {
	if (opertor == '+') {
		return val1  + val2;
	}
	else if (opertor == '-') {
		return val1  - val2;
	}
	else if (opertor == '/') {
		return val1  / val2;
	}
	else if (opertor == '*') {
		return val1  * val2;
	}
}

int precedence(char oper) {
	if (oper == '-' or oper == '+') {
		return 1;
	}
	else if (oper == '/' or oper == '*') return 2;
}

int basicCalculator2(string str) {
	stack<int> opertor;
	stack<int> operand;

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
			operand.push(val);
		}
		else if (ch == '+' or ch == '-' or ch == '*' or ch == '/') { //opertor hoga +,-,*,/
			//koi operator apse higher ya barabar precedence vale operator ko solve kra deta hai, and then khud push ho jata hai
			while (!opertor.empty() and precedence(opertor.top()) >= precedence(ch)) {
				int val2 = operand.top();
				operand.pop();
				int val1 = operand.top();
				operand.pop();
				char opert = opertor.top();
				opertor.pop();
				// cout << opert << endl;
				operand.push(operation(val1, val2, opert));

			}
			opertor.push(ch);
		}
	}

	//check, agr opertor stack me kuch ho toh use bhi calculate krdo.
	while (!opertor.empty()) {
		int val2 = operand.top();
		operand.pop();
		int val1 = operand.top();
		operand.pop();
		char opert = opertor.top();
		// cout << opert << endl;
		opertor.pop();
		operand.push(operation(val1, val2, opert));
	}

	return operand.top(); //rem. ans operand stack ke top pe hoga, always.
}

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=gmy6L9vHTbo&list=PL-Jc9J83PIiE1_SifBEWRsD-fzxrvkja9&index=25
	LEETCODE LINK:
	*/
	string  str = " 3+ 5/2";
	cout << basicCalculator2(str);
}