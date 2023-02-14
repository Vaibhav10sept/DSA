#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> arr, int prevHeight) {
	if (i<0 or j<0 or i >= arr.size() or j >= arr[0].size() or visited[i][j] or arr[i][j] < prevHeight) return;
	// BC ends

	//recursive calls
	visited[i][j] = true;
	dfs(i + 1, j, visited, arr, arr[i][j]);
	dfs(i, j + 1, visited, arr, arr[i][j]);
	dfs(i - 1, j, visited, arr, arr[i][j]);
	dfs(i, j - 1, visited, arr, arr[i][j]);
}

vector<vector<int>> pacificAtlanticWaterFlow(vector<vector<int>> arr) {
	vector<vector<bool>> pacificVisited(arr.size(), vector<bool>(arr[0].size(), false));
	vector<vector<bool>> atlanticVisited(arr.size(), vector<bool>(arr[0].size(), false));
	int n = arr.size();
	int m = arr[0].size();

	//here we are calling dfs for the first row and last row, think, CS, logic, you cannot watch video
	for (int j = 0; j < m; j++) {
		//note first row ke lie pacificVisited paas hoga as visited
		dfs(0, j, pacificVisited, arr, arr[0][j]);
		//note last row ke lie atlanticVisited pass hoga as visited
		dfs(n - 1, j, atlanticVisited, arr, arr[n - 1][j]);
	}

	//here we are calling dfs for the first col and last col, think, CS, logic, you cannot watch video
	for (int i = 0; i < n; i++) {
		//note first col ke lie pacificVisited paas hoga as visited
		dfs(i, 0, pacificVisited, arr, arr[i][0]);
		//note last col ke lie atlanticVisited pass hoga as visited
		dfs(i, m - 1, atlanticVisited, arr, arr[i][m - 1]);
	}

	//using pacificVisited and atlanticVisited we are creating the result vector
	vector<vector<int>> result;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (pacificVisited[i][j] and atlanticVisited[i][j]) {
				result.push_back({i, j});
			}
		}
	}
	return result;
}

int main()
{
	//***************************
	// video link: NONE. is code ko smjh ke leetcode se copy kia
	// LEETCODE LINK: https://leetcode.com/problems/pacific-atlantic-water-flow/
	//**************************************************
	vector<vector<int>> heights = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
	vector<vector<int>> ans = pacificAtlanticWaterFlow(heights);
	for (auto vec : ans) {
		for (auto ele : vec ) cout << ele << " ";
		cout << endl;
	}
}