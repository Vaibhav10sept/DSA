#include <bits/stdc++.h>
using namespace std;

bool checkString(string start, string goal) {
	// good question nice, logic, think, dry run
	//steps:
	// make a temp string like start + start
	// see if goal is a substring of temp
	// if yes then goal is the rotation of start(think, cs) return true
	// else return false(goal is not the rotation of start)

	//edge case: if goal and start size is not same return false
	if (start.size() != goal.size()) return false;


	string temp = start + start;

	//step 2: see is goal is a substring of temp;
	if (temp.find(goal) != string::npos) { //found
		return true;
	}
	return false;
}


int main() {
	/************************************
	 * QUESTION: https://leetcode.com/problems/rotate-string/
	// VIDEO LINK:
	//************************************/
	string s = "abcde";
	string goal = "cdeab";
	if (checkString(s, goal)) cout << "true";
	else cout << "false";
}


