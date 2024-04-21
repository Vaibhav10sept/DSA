#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<int>> &arr) {
	if (i<0 or j<0 or i >= arr.size() or j >= arr[0].size() or arr[i][j] == 1) return;

	//mark visited
	arr[i][j] = 1;

	//recursive call to all four directions
	vector<vector<int>> dir = {{0, 1}, {1, 0}, { -1, 0}, {0, -1}};
	for (int k = 0; k < 4; k++) {
		int i_ = i + dir[k][0];
		int j_ = j + dir[k][1];

		dfs(i_, j_, arr);
	}
}

int numberOfClosedIsland(vector<vector<int>>& arr) {
	//NOTE: I wrote myself no video required
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			if (i == 0 or j == 0 or i == arr.size() - 1 or j == arr[0].size() - 1) {
				//means hm corner/edge of arr me traverse kr rhe hai
				if (arr[i][j] == 0) { //land hai	-> mark all the island as visited
					//visited mark krne ke liye hm given(question) arr ko hi modify kr rhe hai
					dfs(i, j, arr);
				}
			}
		}
	}

	int countOfClosedIsland = 0;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			if (arr[i][j] == 0) {
				countOfClosedIsland++;
				dfs(i, j, arr);
			}
		}
	}

	return countOfClosedIsland;
}

int main() {
	/************************************************************
	 * LEETCODE: https://leetcode.com/problems/number-of-closed-islands/
	//NOTE: I wrote myself no video required
	//************************************************************/
	vector<vector<int>> arr = {{1, 1, 1, 1, 1, 1, 1, 0}, {1, 0, 0, 0, 0, 1, 1, 0}, {1, 0, 1, 0, 1, 1, 1, 0}, {1, 0, 0, 0, 0, 1, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 0}};
	cout << numberOfClosedIsland(arr);

}