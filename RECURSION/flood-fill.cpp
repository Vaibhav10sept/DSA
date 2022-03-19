#include <bits/stdc++.h>
using namespace std;

void floodFill(vector<vector<int>> maze, int row, int col, vector<vector<bool>> visited, string ans) {
	if (row == -1 || col == -1 || row == maze.size() || col == maze[0].size()
	        || maze[row][col] == 1 || visited[row][col] == true) {
		//rem:  maze[row][col]==1 || visited[row][col] == true put
		// these two condition at the end of if (think)
		return;
	}
	if (row == maze.size() - 1 and col == maze[0].size() - 1) {
		cout << ans << endl;
	}
	//base conditions over

	//recursive calls
	// sequence is top,left,bottom,right
	visited[row][col] = true;
	floodFill(maze, row - 1, col, visited, ans + "t");
	floodFill(maze, row, col - 1, visited, ans + "l");
	floodFill(maze, row + 1, col, visited, ans + "b");
	floodFill(maze, row, col + 1, visited, ans + "r");
	//backtrack
	visited[row][col] = false;
}



int main()
{
	//QUESTION LINK: https://www.youtube.com/watch?v=FkkgY7qQF_s&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=417
	//input:
	// 3 3
	// 0 0 0
	// 1 0 1
	// 0 0 0
	int m, n;
	cin >> n >> m;
	vector<vector<int>> maze(n, vector<int>(m));
	for (int i = 0; i < maze.size(); i++) {
		for (int j = 0; j < maze[0].size(); j++) {
			cin >> maze[i][j];
		}
	}
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	floodFill(maze, 0, 0, visited, "");
}