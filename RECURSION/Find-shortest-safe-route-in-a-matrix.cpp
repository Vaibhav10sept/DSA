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

bool isValid2(int i, int j, int n, int m) {
	if (i >= 0 and j >= 0 and i < n and j < m) return true;

	return false;
}

bool isValid(int i, int j, int n, int m, vector<vector<bool>> &visited, vector<vector<int>> &arr) {
	if (i >= 0 and j >= 0 and i < n and j < m and visited[i][j] == false and arr[i][j] == 1) return true;

	return false;
}

int findShortestPath(vector<vector<int>> &mat)
{
	// NOTE: I wrote this code
	int n = mat.size();
	int m = mat[0].size();

	vector<vector<int>> arr(n, vector<int>(m, 1));
	//modify arr according to question
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 0) {
				//all four directions
				vector<int> di = {1, 0, -1, 0};
				vector<int> dj = {0, 1, 0, -1};
				for (int k = 0; k < 4; k++) {
					int ni = i + di[k];
					int nj = j + dj[k];

					if (isValid2(ni, nj, n, m)) {
						arr[i][j] = 0;
						arr[ni][nj] = 0;
					}
				}
			}
		}
	}

	//BFS is used here
	queue<vector<int>> q;
	//0 index -> row
	//1 index -> col
	//2 index -> steps

	vector<vector<bool>> visited(n, vector<bool>(m, false));
	int minSteps = INT_MAX;
	//put all the first col in the
	for (int i = 0; i < n; i++) {
		if (arr[i][0] == 1) {
			q.push({i, 0, 1});
		}
	}
	vector<int> di = {1, 0, -1, 0};
	vector<int> dj = {0, 1, 0, -1};

	while (!q.empty()) {
		vector<int> vec = q.front();
		q.pop();
		int i = vec[0];
		int j = vec[1];
		int step = vec[2];

		if (j == m - 1) { //last col me pahuch gae
			minSteps = min(minSteps, step);
			return minSteps;
		}

		if (visited[i][j]) continue;

		//mark visited
		visited[i][j] = true;

		//all four directions


		for (int k = 0; k < 4; k++) {
			int ni = i + di[k];
			int nj = j + dj[k];

			if (isValid(ni, nj, n, m, visited, arr)) {
				q.push({ni, nj, step + 1});
			}
		}
	}

	return -1;
}

int main()
{
	/*
	NOTE: I wrote this code
	VIDEO:
	QUESTION: https://practice.geeksforgeeks.org/problems/find-shortest-safe-route-in-a-matrix/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
	*/
	vector<vector<int>> arr = {{1, 0, 1, 1, 1},
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1},
		{1, 1, 1, 0, 1},
		{1, 1, 1, 1, 0}
	};
	cout << "ans " << findShortestPath(arr);
}