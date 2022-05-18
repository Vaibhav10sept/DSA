#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterToLeft(vector<int> arr) {
	int n = arr.size();
	vector<int> ans(n);
	stack<int> st;
	st.push(arr[0]);
	ans[0] = -1;
	//left to right traversal
	for (int i = 1; i < n; i++) {
		while (!st.empty() and st.top() < arr[i]) st.pop();
		if (st.empty()) ans[i] = -1;
		else ans[i] = st.top();
		st.push(arr[i]);
	}
	return ans;
}

int main() {
	/*
	VIDEO LINK: https://www.youtube.com/watch?v=TooVFNVlNBI&list=PL-Jc9J83PIiE1_SifBEWRsD-fzxrvkja9&index=2
	LEETCODE LINK:
	*/
	vector<int> nums1 = {2, 5, 9, 3, 1, 12, 6, 8, 7};
	vector<int> ans = nextGreaterToLeft(nums1);
	cout << "res" << endl;
	for (auto ele : ans)cout << ele << " ";
}