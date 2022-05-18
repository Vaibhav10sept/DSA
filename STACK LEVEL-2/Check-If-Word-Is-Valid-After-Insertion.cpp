#include <bits/stdc++.h>
using namespace std;

bool CheckIfWordIsValidAfterInsertion(string str) {
	stack<char> st;
	for (char ch : str) {
		if (ch == 'c') {
			if (st.size() >= 2) {
				if (st.top() != 'b') return false;
				st.pop(); //'b' ko pop krega
				if (st.top() != 'a') return false;
				st.pop(); //'a' ko pop krega
			}
			else {
				return false;
			}
		}
		else { //ch == 'a' or ch == 'b'
			st.push(ch);
		}
	}
	return st.empty(); //agr stack empty hai means true,ham abc ke insertion se str bna skte h.
}

int main()
{
	/*
	memory:
	time:
	VIDEO LINK: https://www.youtube.com/watch?v=Trz7JM610Uc
	LEETCODE LINK: https://leetcode.com/problems/min-stack/
	*/
	string str = "aabcbc";
	cout << CheckIfWordIsValidAfterInsertion(str);
}