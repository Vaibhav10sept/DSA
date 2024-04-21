#include <bits/stdc++.h>
using namespace std;

void displayMatrix(vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int asFarFromLand(vector<vector<int>> arr) {
	// * NOTE: i wrote it after WV
	//0 --> water
	//1 --> land
	int n = arr.size();
	queue<pair<int, int>> q;

	//put all the land in queue
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) q.push({i, j});
		}
	}

	//BFS
	int level = 0;
	vector<vector<int>> dir = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}};
	while (!q.empty()) {
		int size = q.size();
		level++;
		for (int i = 0; i < size; i++) {
			pair<int, int> removed = q.front();
			int row = removed.first;
			int col = removed.second;
			q.pop();

			//traverse in all four directions
			for (int j = 0; j < 4; j++) {
				int nRow = row + dir[j][0];
				int nCol = col + dir[j][1];
				if (nRow >= 0 and nCol >= 0 and nRow < n
				        and nCol < n and arr[nRow][nCol] == 0) {
					q.push({nRow, nCol});
					//mark visited
					arr[nRow][nCol] = level;
				}
			}
		}
		// displayMatrix(arr);
		// cout << "**** " << level << endl;
	}

	return level > 1 ? level - 1 : -1;
}

int main() {
	/************************************************************
	 * NOTE: i wrote it after WV
	//VIDEO LINK: https://www.youtube.com/watch?v=edXdVwkYHF8
	QUESTION: https://leetcode.com/problems/as-far-from-land-as-possible/
	//NOTE:
	//NOTE: breadth first traversal is same as the level order traversal of tree.
	//************************************************************/
	// vector<vector<int>> mat = {{1, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	vector<vector<int>> mat = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
	cout << "ans " << asFarFromLand(mat);
}