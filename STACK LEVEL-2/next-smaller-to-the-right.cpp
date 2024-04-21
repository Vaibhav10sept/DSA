#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerToTheRight(vector<int> arr) {
	int n = arr.size();
	vector<int> ans(n);
	stack<int> st;
	// st.push(arr[n - 1]);
	// ans[n - 1] = -1;
	//right to left traversal
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() and st.top() > arr[i]) st.pop();
		if (st.empty()) ans[i] = -1;
		else ans[i] = st.top();
		st.push(arr[i]);
	}
	return ans;
}

int main() {
	/*
	VIDEO LINK: https://www.youtube.com/watch?v=neTjptte3VA&list=PL-Jc9J83PIiE1_SifBEWRsD-fzxrvkja9&index=3
	LEETCODE LINK:
	*/
	vector<int> nums1 = {2, 5, 9, 3, 1, 12, 6, 8, 7};
	vector<int> ans = nextSmallerToTheRight(nums1);
	cout << "res" << endl;
	for (auto ele : ans)cout << ele << " ";
}