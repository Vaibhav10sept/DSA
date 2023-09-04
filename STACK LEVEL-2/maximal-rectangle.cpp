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

int maximalRectangle(vector<vector<char>> arr) {
	vector<int> heights(arr[0].size());
	int maxArea = INT_MIN;

	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			if (arr[i][j] == '1') {
				heights[j]++;
			}
			else {
				heights[j] = 0;
			}
		}
		maxArea = max(maxArea, largestRectangleHistogramEfficient(heights));
	}

	return maxArea;
}

int main() {
	/*
	PREREQUISITE: largest area histogram efficient approach
	VIDEO LINK: https://www.youtube.com/watch?v=bgWt2qtFhbQ&list=PL-Jc9J83PIiE1_SifBEWRsD-fzxrvkja9&index=7
	LEETCODE LINK: https://leetcode.com/problems/maximal-rectangle/
	*/
	vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
	cout << maximalRectangle(matrix);;
}