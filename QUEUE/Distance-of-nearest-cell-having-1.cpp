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

bool isValid(int x, int y, int n, int m) {
	if (x < 0 or y < 0 or x >= n or y >= m) return false;
	return true;
}


vector<vector<int>> nearest(vector<vector<int>> &arr)
{
	int n = arr.size();
	int m = arr[0].size();

	vector<vector<int>> ans(n, vector<int>(m, INT_MAX));

	queue<vector<int>> q; // x,y,distance --> in vector

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				q.push({i, j, 0});
			}
		}
	}

	vector<int> dx = { -1, 1, 0, 0};
	vector<int> dy = {0, 0, 1, -1};

	while (!q.empty()) {
		vector<int> removed = q.front();
		q.pop();
		int x = removed[0];
		int y = removed[1];
		int dist = removed[2];

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isValid(nx, ny, n, m)) {
				if (arr[nx][ny] == 0) {
					ans[nx][ny] = min(ans[nx][ny], dist + 1);
					arr[nx][ny] = 1;
					q.push({nx, ny, dist + 1});
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ans[i][j] == INT_MAX) ans[i][j] = 0;
		}
	}


	return ans;
}

int main()
{
	/*
	SAME PATTERN: rotten oranges
	NOTE: I wrote it, but giving TLE on gfg
	QUESTION: https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
	*/
	vector<vector<int>> grid = {{0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 1, 1}};

	vector<vector<int>> ans = nearest(grid);
	displayMatrix(ans);
}

