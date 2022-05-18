#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> arr, int x, int y, int mid, vector<vector<bool>> &visited) {
	//mid --> represent max difference of heights between adjacent cell(effort question ke hisab se)
	int n = arr.size();
	int m = arr[0].size();
	//base condition
	if (x == n - 1 and y == m - 1) return true;
	// if (visited[x][y]) return false; //visited hai toh return false

	//mark visited
	visited[x][y] = true;

	vector<vector<int>> directions = {{ -1, 0}, {1, 0}, {0, -1}, {0, 1}};
	for (int i = 0; i < 4; i++) {
		int nx = x + directions[i][0];
		int ny = y + directions[i][1];

		//check for validity of nx and ny.
		if (nx<0 or ny<0 or nx >= n or ny >= n) continue;

		//check, efforts aega x,y and nx,ny se vo mid(max possible effort) se <= hona chahie.
		if (abs(arr[x][y] - arr[nx][ny]) <= mid) {
			//recursive call for nx and ny
			if (dfs(arr, nx, ny, mid, visited)) return true;
		}
	}
	return false;
}

int minimumEffortPath(vector<vector<int>> &arr) {
	int start = 0;
	int end = 1e9 + 1;
	int ans = INT_MAX;
	while (start <= end) {
		cout << "start " << start << " " << end << endl;
		int mid = (start + end) / 2;
		//NOTE: mid --> max diffence between two adjacent cell(effort)
		//or hame max diff ko minimize krna hai. isse think about binary search ke direction.
		vector<vector<bool>> visited(105, vector<bool>(105, false)); //105--> constraint in question
		// visited.clear(); //think, logic
		if (dfs(arr, 0, 0, mid, visited)) {
			ans = min(mid, ans); //minimize krna hai.
			//move to left kyoki hame minimum ans dhundhna hai
			end = mid - 1;
		}
		else {
			//dfs ne false return kia, means mid(effort) chota hai hame or bda mid chahie, move to right
			start = mid + 1;
		}
	}
	return ans;
}


int main()
{
	/*
	NOTE: binary search and DFS is used here.
	LEETCODE LINK:
	VIDEO LINK: https://www.youtube.com/watch?v=xrozg2SQpVA
	*/
	// vector<vector<int>> heights = {{1, 2, 1, 1, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 1, 1, 2, 1}};
	vector<vector<int>> heights = {{1, 10, 6, 7, 9, 10, 4, 9}};
	cout << minimumEffortPath(heights);
}