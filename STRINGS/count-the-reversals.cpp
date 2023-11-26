#include<bits/stdc++.h>
using namespace std;

int countReversals(string str) {
	//this is my own logic and code, no video, no reading
	stack<char> st;
	for (char ele : str) {
		if (ele == '{') {
			st.push(ele);
		}
		else { // ele == '}'
			if (!st.empty() and st.top() == '{') st.pop();
			else {
				st.push(ele);
			}
		}
	}

	//NOTE: stack me sare vo brackets hoge jike pair nhi mile.Think, cs
	int countOpening  = 0;
	int countClosing  = 0;
	while (!st.empty()) {
		if (st.top() == '{') countOpening++;
		if (st.top() == '}') countClosing++;

		st.pop();
	}

	if ((countClosing + countOpening) % 2 != 0) { //odd hai, not possible, dry run, think
		return -1;
	}

	int noOfReversals = 0;
	noOfReversals += countOpening % 2;
	noOfReversals += countOpening / 2;
	noOfReversals += countClosing % 2;
	noOfReversals += countClosing / 2;

	return noOfReversals;
}

int main() {
	/*
	SIMILAR QUESTION: Minimum Number of Swaps to Make the String Balanced
	//this is my own logic and code, no video, no reading
	PREREQUISITE: Minimum Add to Make Parentheses Valid
	VIDEO LINK:
	LEETCODE LINK: https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1
	*/
	string S = "{{}{{{}{{}}{{";
	cout << countReversals(S);;
}