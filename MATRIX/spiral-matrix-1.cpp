#include <bits/stdc++.h>
using namespace std;

vector<int> spiralMatrix1(vector<vector<int>> arr) {
	int ele = 1;
	int totalElement = arr.size() * arr[0].size();
	vector<int> ans;

	int minr = 0;
	int minc = 0;
	int maxr = arr.size() - 1;
	int maxc = arr[0].size() - 1;
	while (ele <= totalElement) {
		//top wall
		for (int i = minc; i <= maxc and ele <= totalElement; i++) {
			ans.push_back(arr[minr][i]);
			ele++;
		}
		minr++;

		//right wall
		for (int i = minr; i <= maxr and ele <= totalElement; i++) {
			ans.push_back(arr[i][maxc]);
			ele++;
		}
		maxc--;

		//bottom wall
		for (int i = maxc; i >= minc and ele <= totalElement; i--) {
			ans.push_back(arr[maxr][i]);
			ele++;
		}
		maxr--;

		//left wall
		for (int i = maxr; i >= minr and ele <= totalElement; i--) {
			ans.push_back(arr[i][minc]);
			ele++;
		}
		minc++;
	}
	return ans;
}


int main()
{
	/*
		LEETCODE LINK: https://leetcode.com/problems/spiral-matrix/
	*/
	vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	vector<int> ans = spiralMatrix1(matrix);
	for (auto ele : ans) cout << ele << " ";
}