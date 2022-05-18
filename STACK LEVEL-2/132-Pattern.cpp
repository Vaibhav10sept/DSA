#include<bits/stdc++.h>
using namespace std;

bool patterns(vector<int> arr) {
	//for logic watch video
	int n = arr.size();
	vector<int> leftMin(n);
	leftMin[0] = arr[0];
	for (int i = 1; i < n; i++) {
		leftMin[i] = min(arr[i], leftMin[i - 1]);
	}

	stack<int> st;
	for (int j = n - 1; j >= 0; j--) {
		while (!st.empty() and st.top() <= leftMin[j]) {
			st.pop();
		}

		if (!st.empty() and st.top() < arr[j]) {
			return true;
		}
		st.push(arr[j]);
	}
	return false;
}

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=zesp0cWYs4w&list=PL-Jc9J83PIiE1_SifBEWRsD-fzxrvkja9&index=16
	LEETCODE LINK:
	*/
	vector<int> arr = { -1, 3, 2, 0};
	cout << patterns(arr);
}