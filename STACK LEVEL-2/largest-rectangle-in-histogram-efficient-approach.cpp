#include<bits/stdc++.h>
using namespace std;

int largestRectangleHistogramEfficient(vector<int> arr) {
	//watch video recommended.
	stack<int> st; //store the index
	int n = arr.size();
	st.push(-1);
	int maxArea = INT_MIN;

	for (int i = 0; i <= n; i++) { //NOTE: i<=n
		int val = i == n ? 0 : arr[i];//i == n, ye invalid index hoga, isilie 0 krdia

		while (st.top() != -1 and arr[st.top()] >= val) {
			int rightMin = i;
			int height = arr[st.top()];
			st.pop();
			int leftMin = st.top();
			maxArea = max(maxArea, height * (rightMin - leftMin - 1));
			//rightMin - leftMin - 1 --> gives the width
		}
		st.push(i);
	}
	return maxArea;
}

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=41VuLYR0btE&list=PL-Jc9J83PIiE1_SifBEWRsD-fzxrvkja9&index=6
	LEETCODE LINK: https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/
	*/
	vector<int> arr = {2, 1, 5, 6, 2, 3};
	cout << largestRectangleHistogramEfficient(arr);
}