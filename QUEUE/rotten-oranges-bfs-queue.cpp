#include <bits/stdc++.h>
using namespace std;

int rottenOranges(vector<vector<int>> arr) {
	//WV Recommended
	// NOTE: I wrote this code after understanding the approach through video
	queue<vector<int>> q; //vector is of 3 size:
	// index 0 --> x coordinate of arr
	// index 1 --> y coordinate of arr
	// index 2 --> time at which it become rotten

	int totalFresh = 0;
	int totalConverted = 0;
	int days = 0;
	//traverse through entire arr and push the coordinate for rotten  oranges
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			if (arr[i][j] == 2) { //means rotten orange
				q.push({i, j, 0});
			}
			if (arr[i][j] == 1) {//means fresh orange
				totalFresh++;
			}
		}
	}

	//use BFS technique
	while (!q.empty()) {
		vector<int> vec = q.front();
		int x = vec[0];
		int y = vec[1];
		int currTime = vec[2];
		q.pop();

		//charo direction me check kroge
		int dx[] = {0, 0, 1, -1};
		int dy[] = {1, -1, 0, 0};

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			//check for validity of nx and ny
			if (nx >= 0 and ny >= 0 and nx < arr.size() and ny < arr[0].size()) { //its valid
				if (arr[nx][ny] == 1) { // if fresh orange
					arr[nx][ny] = 2; // rot it
					totalConverted++;
					days = currTime + 1;
					q.push({nx, ny, currTime + 1});
				}
			}
		}
	}

	if (totalConverted == totalFresh) return days;
	return -1;

}

int main()
{
	/*
	NOTE: we use BFS here.
	NOTE: I wrote this code after understanding the approach through video
	VIDEO: https://www.youtube.com/watch?v=yf3oUhkvqA0
	QUESTION: https://leetcode.com/problems/rotting-oranges/
	NOTE: please refer to the design circular dequeue question first
	*/
	vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
	cout << rottenOranges(grid);

}

