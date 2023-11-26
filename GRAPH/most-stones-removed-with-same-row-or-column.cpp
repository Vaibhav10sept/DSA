#include <bits/stdc++.h>
using namespace std;

void dfs(int ind, vector<vector<int>> &arr, vector<bool> &visited) {
	if (visited[ind]) return;

	visited[ind] = true;

	for (int i = 0; i < arr.size(); i++) {
		if (ind == i) continue;
		int row = arr[i][0];
		int col = arr[i][1];

		if ((row == arr[ind][0] or col == arr[ind][1])
		        and visited[i] == false) {
			dfs(i, arr, visited);
		}
	}
}

int mostStonesRemoved(vector<vector<int>> arr) {
	//khatarnaak sa logic used hua h iss question me
	//no of stones removed = n - no of groups of connected(by same row or column) stones
	//iss logic ke liye dry run kro ya wv, cs, think
	// * NOTE: i wrote this code after wv

	int numberOfGroups = 0;
	int n = arr.size(); //n -> no of stones
	vector<bool> visited(arr.size());

	for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
			dfs(i, arr, visited);
			numberOfGroups++;
		}
	}

	return n - numberOfGroups; //crucial part hai, think, dry run, wv
}

int main() {
	/************************************************************
	 * NOTE: i wrote this code after wv
	 * NOTE: use dfs here.
	VIDEO LINK: https://www.youtube.com/watch?v=ZsGTpXm966E
	LEETCODE: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
	//************************************************************/
	vector<vector<int>> stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
	cout << "ans " << mostStonesRemoved(stones);
}