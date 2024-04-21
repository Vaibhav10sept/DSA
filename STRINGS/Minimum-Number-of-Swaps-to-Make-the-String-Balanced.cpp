#include <bits/stdc++.h>
using namespace std;

int minSwaps(string str) {
	// NOTE: i wrote it myself no video no reading
	//find the extra braces the is causing the unbalance
	stack<char> st;
	for (auto ele : str) {
		if (ele == '[') st.push(ele);
		else { //ele == ']'
			if (!st.empty() and st.top() == '[') st.pop();
			else {
				st.push(ele);
			}
		}
	}

	//now, stack will contain all the braces that causing the unbalancing
	//logic: khud se dimag me aya similar question dekh lo
	//dry run compare with testcase smjh aa jagea, hit and trial.no video
	int CountOfBraces = st.size() / 2;
	return CountOfBraces / 2 + CountOfBraces % 2;
}

int main() {
	/************************************
	 * SIMILAR QUETION: count the reversals
	 *  NOTE: i wrote it myself no video no reading QUESTION:
	 * https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
	 * // VIDEO LINK:
	//************************************/
	string s = "]]][[[";
	cout << "ans " << minSwaps(s);
}


