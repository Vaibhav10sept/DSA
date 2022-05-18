#include<bits/stdc++.h>
using namespace std;

int largestRectangleHistogramEfficient(vector<int> arr) {
	//watch video recommended.
	stack<int> st;
	int n = arr.size();
	st.push(-1);
	int maxArea = INT_MIN;

	for (int i = 0; i <= n; i++) {
		int val = i == n ? 0 : arr[i];

		while (st.top() != -1 and arr[st.top()] >= val) {
			int rightMin = i;
			int height = arr[st.top()];
			st.pop();
			int leftMin = st.top();
			maxArea = max(maxArea, height * (rightMin - leftMin - 1));
		}
		st.push(i);
	}
	return maxArea;
}

int maximalRectangle(vector<vector<char>> arr) {
	vector<int> heights(arr[0].size());

	//first row
	for (int j = 0; j < arr[0].size(); j++) {
		heights[j] = arr[0][j] - '0';
	}

	int maxArea = largestRectangleHistogramEfficient(heights);
	cout << maxArea << endl;

	//rest of the rows
	for (int i = 1; i < arr.size(); i++) { //i=1, coz first row ke lie pehle hi solve kr dia
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
	PREREQUISITE: largest area histogram
	VIDEO LINK: https://www.youtube.com/watch?v=bgWt2qtFhbQ&list=PL-Jc9J83PIiE1_SifBEWRsD-fzxrvkja9&index=7
	LEETCODE LINK: https://leetcode.com/problems/maximal-rectangle/
	*/
	vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
	cout << maximalRectangle(matrix);;
}