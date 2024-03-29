#include<bits/stdc++.h>
using namespace std;

vector<int> onlineStockSpan(vector<int> arr) {
	vector<int> ans;
	stack<pair<int, int>> st;
	//pair: first -->element
	//pair: second --> index

	//traverse left to right and remove all the small from stack
	for (int i = 0; i < arr.size(); i++) {
		while (!st.empty() and st.top().first <= arr[i]) {
			st.pop();
		}

		if (!st.empty()) {
			ans.push_back(i - st.top().second);
		}
		else { //st is empty
			if (i == 0) ans.push_back(1);
			else ans.push_back(i);
		}

		st.push({arr[i], i});
	}
	return ans;
}

int main() {
	/*
	PREREQUISITE: code blueprint is similar to next greater element
	VIDEO LINK: https://www.youtube.com/watch?v=Givpwgu9IIc&list=PL-Jc9J83PIiE1_SifBEWRsD-fzxrvkja9&index=14
	LEETCODE LINK: https://leetcode.com/problems/online-stock-span/
	*/
	// vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
	vector<int> arr = {31, 41, 48, 59, 79};

	vector<int> ans = onlineStockSpan(arr);
	for (int ele : ans)cout << ele << " ";
}