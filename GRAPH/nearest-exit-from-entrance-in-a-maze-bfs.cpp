#include <bits/stdc++.h>
using namespace std;

int nearestExit(vector<vector<char>> arr, vector<int> entrance) {
	int n = arr.size();
	int m = arr[0].size();
	vector<vector<bool>> visited(arr.size(), vector<bool>(arr[0].size(), false));
	vector<vector<int>> dirs = {{1, 0}, {0, 1}, { -1, 0},  {0, -1}};
	queue<pair<int, int>> q; // pair<int,int> --> row, col (coordinates)
	int level = 0; //we can also call this steps

	visited[entrance[0]][entrance[1]] = true;
	q.push({entrance[0], entrance[1]});


	while (!q.empty()) {
		level++;
		int size = q.size();

		while (size != 0) {
			pair<int, int> coordinate = q.front();
			q.pop();

			//iterate in all the four directions
			for (int i = 0; i < dirs.size(); i++) {
				vector<int> dir = dirs[i];
				int nextRow = coordinate.first + dir[0];
				int nextCol  = coordinate.second + dir[1];

				//check for validity of next row and next col
				if (nextRow < 0 or nextCol < 0 or nextRow >= n or nextCol >= m or arr[nextRow][nextCol] == '+' or visited[nextRow][nextCol] == true) continue;

				//check if next row and next col is the exit;
				if (nextRow == 0 or nextCol == 0 or nextRow == n - 1 or nextCol == m - 1) return level;

				//mark the next row and next col as visited
				visited[nextRow][nextCol] = true;
				//put the next row and next col in the queue
				q.push({nextRow, nextCol});

			}//for ends
			size--;
		}
	}
	return -1; //didn't get the answer, return -1
}

int main() {
	/************************************************************
	 * NOTE: this solution will not give TLE as this a BFS solution
	 * NOTE: A DFS solution is also there, that gives you TLE,
	//VIDEO LINK: https://www.youtube.com/watch?v=niDFGmMytLk
	//LEETCODE LINK: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/
	//************************************************************/


	// vector<vector<char>> maze = {{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};
	// vector<int> entrance = {1, 2};

	vector<vector<char>> maze = {{'+', '+', '+'}, {'.', '.', '.'}, {'+', '+', '+'}};
	vector<int> entrance = {1, 0};

	cout << nearestExit(maze, entrance);
}