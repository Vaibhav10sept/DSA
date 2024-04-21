#include<bits/stdc++.h>
using namespace std;

int largestRectangleHistogramEfficient(vector<int> arr) {
	//watch video recommended.
	//NOTE: main logic is stack me hmesa increasing order me values(ke indexes) hoge.
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
	VIDEO LINK 1: https://www.youtube.com/watch?v=X0X6G-eWgQ8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=82
	VIDEO LINK 2: https://www.youtube.com/watch?v=jC_cWLy7jSI&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=83
	LEETCODE LINK: https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/
	*/
	vector<int> arr = {2, 1, 5, 6, 2, 3};
	cout << largestRectangleHistogramEfficient(arr);
}