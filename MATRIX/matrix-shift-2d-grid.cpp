#include <bits/stdc++.h>
using namespace std;

void displayMatrix(vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

vector<vector<int>> shiftMatrix(vector<vector<int>> arr, int k) {
	/*
	FORMULAS(don't memorize,watch video):
	1. total = n*m (n--> no of rows and m--> no of columns)
	2. matrix index to flat index: (i*col+j)%total
	3. flat index to matrix index: matrix[flatIndex/columns, flatIndex%columns]
	*/
	int n = arr.size();
	int m = arr[0].size();
	vector<vector<int>> ans(n, vector<int>(m));
	int total = n * m;
	k = k % total;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int flatIndex = (i * m + j) % total;
			int newPosition = (flatIndex + k) % total;
			ans[newPosition / m][newPosition % m] = arr[i][j];
		}
	}
	return ans;
}


int main()
{
	/*
	VIDEO LINK: https://www.youtube.com/watch?v=nJYFh4Dl-as
	LEETCODE LINK: https://leetcode.com/problems/shift-2d-grid
	FORMULAS(don't memorize,watch video):
	1. total = n*m (n--> no of rows and m--> no of columns)
	2. matrix index to flat index: (i*col+j)%total
	3. flat index to matrix index: matrix[flatIndex/columns, flatIndex%columns]
		*/
	vector<vector<int>> grid = {{3, 8, 1, 9}, {19, 7, 2, 5}, {4, 6, 11, 10}, {12, 0, 21, 13}};
	int k = 4;
	vector<vector<int>> ans = shiftMatrix(grid, k);
	displayMatrix(ans);
}