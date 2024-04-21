#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &arr, queue<pair<int, int>> &q) {
	if (i<0 or j<0 or i >= arr.size() or j >= arr[0].size()
	        or visited[i][j] or arr[i][j] == 0) return;
	//BC ends

	q.push({i, j});
	visited[i][j] = true;

	///rec dfs call in all four directions
	dfs(i + 1, j, visited, arr, q);
	dfs(i, j + 1, visited, arr, q);
	dfs(i - 1, j, visited, arr, q);
	dfs(i, j - 1, visited, arr, q);
}

int bfs(vector<vector<int>> &arr, queue<pair<int, int>> &q, vector<vector<bool>> &visited) {
	//now, queue has the coordinates of first island
	//dfs over ho gya, ab bfs lga rhe hai
	// visited = vector<vector<bool>>(); //re-initiaze kia h visited vector ko.
	//we are doing level order traveral(u know it, wv, think, cs)
	int level = 0;
	int minDistance = INT_MAX;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			pair<int, int> removedNode = q.front();
			q.pop();

			int i = removedNode.first;
			int j = removedNode.second;

			//it can move in four directions
			vector<vector<int>> directions = {{ -1, 0}, {0, -1}, {1, 0}, {0, 1}};
			for (vector<int> dir : directions) {
				int nextI = i + dir[0];
				int nextJ = j + dir[1];

				if (nextI < 0 or nextJ < 0 or nextI >= arr.size() or nextJ >= arr[0].size() or visited[nextI][nextJ]) continue;

				if (arr[nextI][nextJ] == 1) { //we found a 1 which is unvisited that means ye second island ka 1 hai, to store the min of the level at which we found this one
					minDistance = min(minDistance, level);
				}
				else {// arr[nextI][nextJ] == 0
					visited[nextI][nextJ] = true;
					q.push({nextI, nextJ});
				}

			}


		}
		level++;
	}

	return minDistance;
}

int shortestBridge(vector<vector<int>> arr) {
	// NOTE: I wrote this code after WV
	int n = arr.size();
	int m = arr[0].size();
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	queue<pair<int, int>> q; //for bfs, dfs will fill the queue with the coordinates of first island

	//get connected components vala format
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) { //only first island ke liye hi dfs call hogi, taki first island ke coordinates queue me aa jae
				dfs(i, j, visited, arr, q);
				return bfs(arr, q, visited);
			}
		}
	}
}

int main() {
	/************************************************************
	//VIDEO LINK: https://www.youtube.com/watch?v=GSE0-dReL6Y
	LEETCODE: https://leetcode.com/problems/shortest-bridge/description/
	NOTE: I wrote this code after WV
	PREQ: get connected components and BFS
	//NOTE: BFS give you smaller path as compared to DFS.
	//NOTE: breadth first traversal is same as the level order traversal of tree.
	//NOTE:
	//************************************************************/

	vector<vector<int>> grid = {{0, 1}, {1, 0}};
	cout << shortestBridge(grid);
}