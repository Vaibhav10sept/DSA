#include <bits/stdc++.h>
using namespace std;

void markAllConnected(vector<vector<bool>> &visited,
                      vector<vector<int>> &grid, int i, int j) {
	//this is recursive
	//bc
	if (i<0 or j<0 or i >= grid.size() or j >= grid[0].size() or grid[i][j] == 0
	        or visited[i][j] == true) return;
	//bc ends

	// recursive calls in all four directions
	visited[i][j] = true;
	markAllConnected(visited, grid, i, j + 1); //right
	markAllConnected(visited, grid, i, j - 1); //left
	markAllConnected(visited, grid, i + 1, j); //top
	markAllConnected(visited, grid, i - 1, j); //bottom
}

int maxAreaOfIsland(vector<vector<int>> grid) {
	vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
	int countOfIsland = 0;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			if (grid[i][j] == 1 and visited[i][j] == false) {
				countOfIsland++;
				markAllConnected(visited, grid, i, j);
			}
		}
	}
	return countOfIsland;
}

int main() {
	//*********************************
	// NOTE: done before in graph question -> "count no of island".
	// NOTE: here we are solving this question using recursion.
	// VIDEO LINK: https://www.youtube.com/watch?v=aAcC3QXmnDE&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=33
	// QUESTION:
	// 	You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

	// The area of an island is the number of cells with a value 1 in the island.

	// Return the maximum area of an island in grid. If there is no island, return 0.
	//*********************************

	vector<vector<int>> grid =
	{	{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}
	};
	cout << "no of islands are: " << maxAreaOfIsland(grid);
}