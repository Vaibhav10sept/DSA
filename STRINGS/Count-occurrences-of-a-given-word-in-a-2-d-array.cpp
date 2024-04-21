#include<bits/stdc++.h>
using namespace std;

int dfs(int i, int j, int ind, vector<vector<char>>& arr, string &target, vector<vector<bool>> &visited) {
	if (i<0 or j<0 or i >= arr.size() or j >= arr[0].size()
	        or visited[i][j]) return 0;

	if (ind >= target.size()) return 0;

	if (arr[i][j] == target[ind] and ind == target.size() - 1 ) return 1;

	if (arr[i][j] != target[ind]) return 0;
	//BC ends

	//now, arr[i][j] == target[ind]
	//recursive call in all 4 directions
	int ans = 0;
	visited[i][j] = true;

	vector<vector<int>> dirs = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}};
	for (auto dir : dirs) {
		int i_ = i + dir[0];
		int j_ = j + dir[1];

		ans += dfs(i_, j_, ind + 1, arr, target, visited);
	}

	//backtrack
	visited[i][j] = false;
	return ans;
}

int countOccurences(vector<vector<char>> arr, string target) {
	// NOTE: i wrote it myself, no video, no reading
	int n = arr.size();
	int m = arr[0].size();
	vector<vector<bool>> visited(arr.size(), vector<bool>(arr[0].size(), false));
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == target[0]) {
				cnt += dfs(i, j, 0, arr, target, visited);
			}
		}
	}

	return cnt;
}

int main() {
	/*
	NOTE: i wrote it myself, no video, no reading
	PREREQUISITE:
	VIDEO LINK:
	LEETCODE LINK: https://practice.geeksforgeeks.org/problems/count-occurences-of-a-given-word-in-a-2-d-array/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
	*/
	vector<vector<char>> mat = {{'S', 'N', 'B', 'S', 'N'},
		{'B', 'A', 'K', 'E', 'A'},
		{'B', 'K', 'B', 'B', 'K'},
		{'S', 'E', 'B', 'S', 'E'}
	};
	string target = "SNAKES";
	cout << countOccurences(mat, target);;
}