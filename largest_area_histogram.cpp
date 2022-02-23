
#include <bits/stdc++.h>
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

int main() {
	vector<int> arr = {6, 2, 5, 4, 5, 1, 6};
	vector<int> left = leftnextsmallerindex(arr);
	vector<int> right = rightnextsmallerindex(arr);
	int ans = INT_MIN;
	for (int i = 0; i < arr.size(); i++) {
		int height = arr[i];
		int width = right[i] - left[i] - 1;
		ans = max(ans, height * width);
	}
	cout << ans << endl;
}