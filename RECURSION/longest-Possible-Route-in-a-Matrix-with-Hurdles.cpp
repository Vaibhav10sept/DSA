#include <bits/stdc++.h>
using namespace std;

void rec(int row, int col, int steps, vector<vector<int>> &arr, int ex, int ey, int &maxStep, vector<vector<bool>> &visited) {
	if (row < 0 or col < 0 or row >= arr.size() or col >= arr[0].size()
	        or visited[row][col] or arr[row][col] == 0) return;

	if (row == ex and col == ey) {
		maxStep = max(maxStep, steps);
		return;
	}
	//BC ends

	//mark visited
	visited[row][col] = true;

	//recursive call in four directions
	vector<int> dx = {0, 1, -1, 0};
	vector<int> dy = {1, 0, 0, -1};

	for (int i = 0; i < 4; i++) {
		int nRow = row + dx[i];
		int nCol = col + dy[i];

		rec(nRow, nCol, steps + 1, arr, ex, ey, maxStep, visited);
	}

	visited[row][col] = false;
}

int longestPath(vector<vector<int>> arr, int sx, int sy, int ex, int ey)
{
	// NOTE: i wrote this code
	int n = arr.size();
	int m = arr[0].size();
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	int maxStep = -1;

	rec(sx, sy, 0, arr, ex, ey, maxStep, visited);
	return maxStep;
}

int main()
{
	/*
	NOTE: i wrote this code
	VIDEO LINK:
	QUESTION LINK: https://practice.geeksforgeeks.org/problems/longest-possible-route-in-a-matrix-with-hurdles/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
	*/
	int sx = 0;
	int sy = 0;
	int ex = 1;
	int ey = 7;
	vector<vector<int>>	matrix =
	{	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 0, 1, 1, 0, 1, 1, 0, 1},
		{1 , 1, 1, 1, 1, 1, 1 , 1, 1, 1}
	};
	cout << longestPath(matrix, sx, sy, ex, ey);
}