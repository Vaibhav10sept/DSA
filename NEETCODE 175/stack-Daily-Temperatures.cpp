#include<bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int> arr) {
	stack<pair<int, int>> st;
	int n = arr.size();
	vector<int> ans(n);

	//right to left, create next greater to the right
	for (int i = n - 1; i >= 0; i--) {
		int ele = arr[i];
		while (!st.empty() and st.top().first <= ele) st.pop();
		if (st.empty()) ans[i] = 0;
		else ans[i] = st.top().second - i;
		st.push({ele, i});
	}
	return ans;
}

int main() {
	/*
	SIMILAR TO: online stock span, next greater to the right
	VIDEO LINK:
	LEETCODE LINK:
	*/
	// vector<int> arr = {73, 74, 75, 71, 69, 72, 76, 73};
	vector<int> arr = {89, 62, 70, 58, 47, 47, 46, 76, 100, 70};
	vector<int> ans =  dailyTemperatures(arr);
	for (auto ele : ans) cout << ele << " ";
}