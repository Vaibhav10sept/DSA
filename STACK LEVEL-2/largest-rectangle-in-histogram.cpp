#include<bits/stdc++.h>
using namespace std;

vector<int> leftnextsmallerindex(vector<int> arr) {
	vector<int> ans(arr.size());
	ans[0] = -1;
	stack<int> st;
	st.push(0);
	for (int i = 1; i < arr.size(); i++) {
		while (st.size() > 0 and arr[st.top()] >= arr[i]) st.pop();
		if (st.empty()) {
			ans[i] = -1;
		} else {
			ans[i] = st.top();

		}
		st.push(i);
	}
	return ans;
}

vector<int> rightnextsmallerindex(vector<int> arr) {
	vector<int> ans(arr.size());
	ans[arr.size() - 1] = arr.size();
	stack<int> st;
	st.push(arr.size() - 1);
	for (int i = arr.size() - 2; i >= 0; i--) {
		while (st.size() > 0 and arr[st.top()] >= arr[i]) st.pop();
		if (st.empty()) {
			ans[i] = arr.size();
		} else {
			ans[i] = st.top();

		}
		st.push(i);
	}
	return ans;

}

int largestRectangleHistogram(vector<int> arr) {

	vector<int> left = leftnextsmallerindex(arr);
	vector<int> right = rightnextsmallerindex(arr);
	int ans = INT_MIN;

	for (int i = 0; i < arr.size(); i++) {
		int height = arr[i];
		int width = right[i] - left[i] - 1;
		ans = max(ans, height * width);
	}
	return ans;
}

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=41VuLYR0btE&list=PL-Jc9J83PIiE1_SifBEWRsD-fzxrvkja9&index=6
	LEETCODE LINK: https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/
	*/
	vector<int> arr = {2, 1, 5, 6, 2, 3};
	cout << largestRectangleHistogram(arr);
}