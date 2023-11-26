#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int n, vector<vector<bool>>&visited) {
	if (i >= 0 && i < n && j >= 0 && j < n && visited[i][j] == false) {
		return true;
	}
	return false;
}

int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int n)
{
	// Code here
	int tx = TargetPos[0] - 1, ty = TargetPos[1] - 1;
	int x1 = KnightPos[0] - 1, y1 = KnightPos[1] - 1;

	if (x1 == tx && y1 == ty) return 0;

	vector<vector<bool>>visited(n, vector<bool>(n, false));

	queue<pair<int, int>>q;
	q.push({x1, y1});
	visited[x1][y1] = true;

	int ans = 0;
	while (!q.empty()) {

		int size = q.size();
		ans++;
		while (size != 0) {
			pair<int, int>p = q.front();
			q.pop();

			int xx = p.first;
			int yy = p.second;

			int ax[8] = {1, 1, -1, -1, 2, -2, 2, -2};
			int ay[8] = {2, -2, 2, -2, 1, 1, -1, -1};

			for (int i = 0; i < 8; i++) {
				int nx = xx + ax[i];
				int ny = yy + ay[i];

				if (nx == tx && ny == ty) return ans;

				if (isValid(nx, ny, n, visited)) {
					visited[nx][ny] = true;
					q.push({nx, ny});
				}
			}

			size--;
		}
	}


	return ans;
}

int main()
{
	/*
	STRONG PREQ: knight tour
	NOTE:
	VIDEO: https://www.youtube.com/watch?v=XhYVY6PQSxs
	QUESTION: https://practice.geeksforgeeks.org/problems/knight-walk4521/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
	*/
	vector<int> KnightPos = {4, 5};
	vector<int> TargetPos =  {1, 1};
	int n = 6;
	cout << "ans " << minStepToReachTarget(KnightPos, TargetPos, n);
}