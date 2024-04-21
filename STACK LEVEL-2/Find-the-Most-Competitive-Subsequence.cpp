#include <bits/stdc++.h>
using namespace std;

vector<int> lexicographicallySmallestSubsequence(vector<int> arr, int k) {
	stack<int> st;
	//we are using monotonic increasing stack concept here: wv, think, dry
	int maxNumberWeCanRemove = arr.size() - k;

	for (auto ele : arr) {
		while (!st.empty() and maxNumberWeCanRemove != 0 and st.top() > ele) {
			st.pop();
			maxNumberWeCanRemove--;
		}

		st.push(ele);
	}

	//remove all the extra value in stack to make it of size k
	while (maxNumberWeCanRemove != 0) {
		st.pop();
		maxNumberWeCanRemove--;
	}

	//move stack to ans vector
	vector<int> ans;
	while (!st.empty()) {
		ans.push_back(st.top());
		st.pop();
	}

	reverse(ans.begin(), ans.end());

	return ans;
}

int main() {
	/*
	NOTE: this is of monotonic stack question
	NOTE: good question pura smjh me aya, thoda tricky h smjhna , but dry run kro, wv
	SAME QUESTION: find the lexicographicall smallest subsequence of size k.
	VIDEO LINK: https://www.youtube.com/watch?v=Ol7yz0XKKLw
	QUESTION LINK: https://leetcode.com/problems/find-the-most-competitive-subsequence/
	*/
	vector<int> arr = {2, 4, 3, 3, 5, 4, 9, 6};
	int  k = 4;
	vector<int> ans = lexicographicallySmallestSubsequence(arr, k);
	for (auto ele : ans) cout << ele << " ";
}