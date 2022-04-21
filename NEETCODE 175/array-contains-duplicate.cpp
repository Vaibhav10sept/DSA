#include <bits/stdc++.h>
using namespace std;

bool containDuplicates(vector<int> arr) {
	set<int> st;
	for (int ele : arr) {
		if (st.find(ele) != st.end()) {
			return true;
		}
		st.insert(ele);
	}
	return false;
}

int main() {
	/*
	LEETCODE LINK: https://leetcode.com/problems/contains-duplicate/
	VIDEO LINK:
	*/
	vector<int> arr = {1, 2, 3, 1};

	cout << containDuplicates(arr);
}