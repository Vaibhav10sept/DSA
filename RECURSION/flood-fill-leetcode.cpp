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

void dfs(int i, int j, vector<vector<bool>> visited, int sourceColor, int targetColor, vector<vector<int>> &arr) {
	if (i<0 or j<0 or i >= arr.size() or j >= arr[0].size() or visited[i][j] == true) return;
	if (arr[i][j] != sourceColor) return;
	arr[i][j] = targetColor;

	//mark visited
	visited[i][j] = true;
	//recursive call in all four directions
	dfs(i + 1, j, visited, sourceColor, targetColor, arr);
	dfs(i, j + 1, visited, sourceColor, targetColor, arr);
	dfs(i - 1, j, visited, sourceColor, targetColor, arr);
	dfs(i, j - 1, visited, sourceColor, targetColor, arr);
	return;
}

vector<vector<int>> floodFill(vector<vector<int>> arr, int sr, int sc, int targetColor) {
	int sourceColor = arr[sr][sc];
	vector<vector<bool>> visited(arr.size(), vector<bool>(arr[0].size(), false));
	dfs(sr, sc, visited, sourceColor, targetColor, arr);
	return arr;
}


int main()
{
	/*
	LEETCODE: https://leetcode.com/problems/flood-fill/description/
	*/

	vector<vector<int>> arr = {{0, 0, 0}, {0, 1, 0}};
	int sr = 1;
	int sc = 1;
	int color = 2;
	vector<vector<int>> ans = floodFill(arr, sr, sc, color);
	displayMatrix(ans);
}