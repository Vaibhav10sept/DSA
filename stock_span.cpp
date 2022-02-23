#include <bits/stdc++.h>
using namespace std;
void fun(vector<int> arr) {
	stack<int> st;
	vector<int> ans(arr.size());
	int n = arr.size();
	// ans[0] = 0;
	// st.push(0);
	for (int i = 0; i < n; i++) {
		while (st.size() > 0 and arr[i] < arr[st.top()]) st.pop();
		if (st.size() == 0) ans[i] = 1;
		else ans[i] = st.top()  ;
		st.push(i);

	}
	for (auto i : ans)cout << i << " ";
}
int main() {
	vector<int> arr = {100, 80, 60, 70, 60, 75, 80};


	// output: 1,1,1,2,1,4,6

	// logic: find the index of next smaller element from left
	fun(arr);
}