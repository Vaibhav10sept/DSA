#include<bits/stdc++.h>
using namespace std;

int basicCalculator(string str) {
	//good, hard question lot of steps are there
	//pay attention, how the sign variable works(this is the tricky part of this question)
	int sum = 0;
	int sign = 1; //can be +ve(1) or -ve(-1).
	stack<int> st;

	for (int i = 0; i < str.size(); i++) {
		char ch = str[i];
		if (isdigit(ch)) {
			//get the whole number, like if ch is '1' then iterate further to get the number like '15'
			int val = 0;
			while (i < str.size() and isdigit(str[i])) {
				val = val * 10 + (str[i] - '0');
				i++;
			}
			i--;//coz, i ab ek no digit(symbol) pe aa gya, or outer for loop se vo ek age or bdh jaega, ek char miss kr dega islie i-- kia
			val = val * sign; //val me sign lgaya
			sign = 1;//sign ko reset kia
			sum += val;
		}
		else if (ch == '(') {
			//sum dalo stack pe, sign dalo stack pe or fir sign and sum ko reset kro
			st.push(sum);
			st.push(sign);
			//reset sign and sum;
			sum = 0;
			sign = 1;
		}
		else if (ch == ')') {
			//stack se sign nikalo or use sum se multiply krdo
			sum *= st.top();
			st.pop();
			//ab stack ke top pe sum hoga jo ki hmne '(' milne pr dala tha(see above else if)
			sum += st.top();
			st.pop();
		}
		else if (ch == '-') {
			//minus hota h to sign ko reverse krte hai,bachpn me math me pda tha
			sign *= -1; //sign ko toggle kia hai
		}
	}
	return sum;
}

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=HUfUzA9Ekgo&list=PL-Jc9J83PIiE1_SifBEWRsD-fzxrvkja9&index=24
	LEETCODE LINK:
	*/
	string  str = "(1+(4+5+2)-3)+(6+8)";
	cout << basicCalculator(str);
}