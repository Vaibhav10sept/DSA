#include <bits/stdc++.h>
using namespace std;

string removeAdjacent2(string str, int k) {
	//NOTE: i wrote it myself, no vidoe, no reading
	stack<pair<char, int>> st; //pair --> char, count
	for (char ch : str) {
		if (st.empty()) {
			st.push({ch, 1});
		}
		else {
			if (st.top().first == ch) {
				//increase the count of top of stack
				st.top().second++;
				//if count is equal to k then pop that value
				if (st.top().second == k) {
					st.pop();
				}
			}
			else {
				st.push({ch, 1});
			}
		}
	}

	//convert the values in stack to string, reverse it and then return that string
	string ans = "";
	while (!st.empty()) {
		int count = st.top().second;
		char ch = st.top().first;
		st.pop();

		while (count--) {
			ans += ch;
		}
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	/*********************************
	 * NOTE: we use stack here.
	 * //NOTE: i wrote it myself, no vidoe, no reading
	// VIDEO LINK:
	// QUESTION: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

	//*********************************/
	string s = "pbbcggttciiippooaais";
	int k = 2;
	cout << removeAdjacent2(s, k);
}