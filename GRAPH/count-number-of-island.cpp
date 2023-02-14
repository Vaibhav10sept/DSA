#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>  constructMatrix() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int> (m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	return arr;
}

void turn_to_dust(vector<vector<int>>& grid, int i, int j, int m, int n) {
	if (i < 0 || j < 0 || i == m || j == n || grid[i][j] == 0) return;
	grid[i][j] = 0;
	turn_to_dust(grid, i + 1, j, m, n);
	turn_to_dust(grid, i, j + 1, m, n);
	turn_to_dust(grid, i - 1, j, m, n);
	turn_to_dust(grid, i, j - 1, m, n);
	return;
}

int countNumberOfIslands(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	int res = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 1) {
				res++;
				turn_to_dust(grid, i, j, m, n);
			}
		}
	}
	return res;
}

int main() {
	//************************************************************
	//VIDEO LINK: https://www.youtube.com/watch?v=ErPZFxugYkI&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=527
	//NOTE: similar is "get-connected-components"
	//NOTE: this is code is copied from leetcode solutions
	//I found this code better and understandable.
	//************************************************************
	// INPUT:
	// 8
	// 8
	// 0 0 1 1 1 1 1 1
	// 0 0 1 1 1 1 1 1
	// 1 1 1 1 1 1 1 0
	// 1 1 0 0 0 1 1 0
	// 1 1 1 1 0 1 1 0
	// 1 1 1 1 0 1 1 0
	// 1 1 1 1 1 1 1 0
	// 1 1 1 1 1 1 1 0

	vector<vector<int>> graph = constructMatrix();
	cout << "the count of island is: " << countNumberOfIslands(graph);

}