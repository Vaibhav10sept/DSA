#include <bits/stdc++.h>
using namespace std;

int recursiveHelper(int i, int j, vector<vector<char>> arr, vector<vector<bool>> visited, vector<int> entrance) {
	//BC
	if (i<0 or j<0 or i >= arr.size() or j >= arr[0].size() or arr[i][j] == '+' or visited[i][j] == true) return INT_MAX;
	if ((i != entrance[0] or j != entrance[1]) and (i == 0 or j == 0 or i == arr.size() - 1 or j == arr[0].size() - 1)) return 0;
	//BC Ends


	int ans = INT_MAX;
	visited[i][j] = true;

	//rec call for all four directions
	ans = min(ans, recursiveHelper(i + 1, j, arr, visited, entrance));
	ans = min(ans, recursiveHelper(i, j + 1, arr, visited, entrance));
	ans = min(ans, recursiveHelper(i - 1, j, arr, visited, entrance));
	ans = min(ans, recursiveHelper(i, j - 1, arr, visited, entrance));

	//backtrack
	visited[i][j] = false;

	if (ans != INT_MAX) return ans + 1;
	return INT_MAX;
}

int nearestExit(vector<vector<char>> arr, vector<int> entrance) {
	vector<vector<bool>> visited(arr.size(), vector<bool>(arr[0].size(), false));

	int ans = recursiveHelper(entrance[0], entrance[1], arr, visited, entrance);

	if (ans == INT_MAX) return -1;
	return ans;
}

int main() {
	/************************************************************
	 * NOTE: this solution will TLE as this a DFS solution, we need BFS solution to submit
	 * NOTE: A BFS solution is also there, that don't give you TLE,
	//VIDEO LINK: https://www.youtube.com/watch?v=niDFGmMytLk
	//LEETCODE LINK: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/
	//************************************************************/


	vector<vector<char>> maze = {{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};
	vector<int> entrance = {1, 2};

	// vector<vector<char>> maze = {{'+', '+', '+'}, {'.', '.', '.'}, {'+', '+', '+'}};
	// vector<int> entrance = {1, 0};


	cout << nearestExit(maze, entrance);
}